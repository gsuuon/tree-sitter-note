#include "tree_sitter/parser.h"
#include <stdio.h>

enum TokenType {
    INDENT,
    DEDENT,
    EQDENT,
    SECTION_IN,
    SECTION_DE,
    SECTION_EQ,
    SECTION_HEADER_CLOSING_SCOPE,
    BEGIN_OF_FILE,
    END_OF_FILE,
    ERROR_RECOVERY
};

typedef struct {
    int last_indent_column;
    int emitted_indent_column;
    int last_section_depth;
    int emitted_section_depth;
    bool did_emit_start;
} Scanner;

void *tree_sitter_note_external_scanner_create(void) {
    return calloc(1, sizeof(Scanner));
}

void tree_sitter_note_external_scanner_destroy(void *payload) {
    free(payload);
}

unsigned tree_sitter_note_external_scanner_serialize(
  void *payload,
  char *buffer
) {
    memcpy(buffer, payload, sizeof(Scanner));
    return sizeof(Scanner);
}

void tree_sitter_note_external_scanner_deserialize(
  void *payload,
  const char *buffer,
  unsigned length
) {
    if (length == sizeof(Scanner)) {
        Scanner *scanner = (Scanner *)payload;
        scanner->last_indent_column = 0;
        scanner->emitted_indent_column = 0;
        scanner->last_section_depth = 0;
        scanner->emitted_section_depth = 0;
        scanner->did_emit_start = false;
        memcpy(payload, buffer, sizeof(Scanner));
    } else {
        // reset
        Scanner *scanner = (Scanner *)payload;
        scanner->last_indent_column = 0;
        scanner->emitted_indent_column = 0;
        scanner->last_section_depth = 0;
        scanner->emitted_section_depth = 0;
        scanner->did_emit_start = false;
    }
}

int find_marker_column(TSLexer *lexer) {
    int spaces = 0;
    /* printf("--- Finding marker\n"); */

    while (lexer->lookahead == ' ') {
        spaces++;
        lexer->advance(lexer, false);
    }

    switch (lexer->lookahead) {
        case '-':
        case '.':
        case ',':
        case '=':
        case '*':
        case '[': {
            return spaces;
        }
    }

    return -1;
}

void print_debugs(const bool *valid_symbols) {
    printf("--- lex valid_symbols\n");
    if (valid_symbols[INDENT]) { printf("--- valid: INDENT\n"); }
    if (valid_symbols[DEDENT]) { printf("--- valid: DEDENT\n"); }
    if (valid_symbols[EQDENT]) { printf("--- valid: EQDENT\n"); }

    if (valid_symbols[SECTION_IN]) { printf("--- valid: SECTION_IN\n"); }
    if (valid_symbols[SECTION_DE]) { printf("--- valid: SECTION_DE\n"); }
    if (valid_symbols[SECTION_EQ]) { printf("--- valid: SECTION_EQ\n"); }
    if (valid_symbols[SECTION_HEADER_CLOSING_SCOPE]) { printf("--- valid: SECTION_HEADER_CLOSING_SCOPE\n"); }

    if (valid_symbols[BEGIN_OF_FILE]) { printf("--- valid: BEGIN_OF_FILE\n"); }
    if (valid_symbols[END_OF_FILE]) { printf("--- valid: END_OF_FILE\n"); }

    if (valid_symbols[ERROR_RECOVERY]) { printf("--- valid: ERROR_RECOVERY\n"); }
}

/// Sets scanner state on success
enum TokenType try_find_section_symbol(
    Scanner *scanner,
    TSLexer *lexer,
    const bool *valid_symbols,
    int *depth
) {
    /* printf("--- Section find\n"); */

    while (lexer->lookahead == '#') {
        lexer->advance(lexer, false);
        (*depth)++;
    }

    /* printf("--- Section depth: %i\n", (*depth)); */

    if (lexer->lookahead != ' ') {

        /* printf("--- Section: not a header, missing space after #\n"); */
        return -1;
    }

    if (valid_symbols[SECTION_HEADER_CLOSING_SCOPE] && (*depth) > 0) {
        // we're trying to end an item_scope with a section header
        return SECTION_HEADER_CLOSING_SCOPE;
    }

    // Gone 1 deeper (can only increase section depth 1 at a time)
    if (valid_symbols[SECTION_IN] && (*depth) == scanner->last_section_depth + 1) {
        return SECTION_IN;
    }

    if (valid_symbols[SECTION_DE]) {
        // We've closed several sections and need to emit more 0 width section_de, e.g. #### to #
        if (scanner->emitted_section_depth > scanner->last_section_depth) {
            return SECTION_DE;
        }

        // Depth decreased
        if ((*depth) < scanner->last_section_depth) {
            return SECTION_DE;
        }
    }

    if (valid_symbols[SECTION_EQ] && scanner->last_section_depth == (*depth)) {
        return SECTION_EQ;
    }

    return -1;
}

bool tree_sitter_note_external_scanner_scan(
  void *payload,
  TSLexer *lexer,
  const bool *valid_symbols
) {
    Scanner *scanner = (Scanner *)payload;

    /* print_debugs(valid_symbols); */

    // https://github.com/tree-sitter/tree-sitter/issues/3433
    // store get_column so we only call once
    uint32_t col = lexer->get_column(lexer);

    if (valid_symbols[BEGIN_OF_FILE]) {
        if (!scanner->did_emit_start && col == 0) {
            lexer->result_symbol = BEGIN_OF_FILE;
            scanner->did_emit_start = true;

            return true;
        }
    }

    if (valid_symbols[INDENT] || valid_symbols[EQDENT] || valid_symbols[DEDENT] || valid_symbols[SECTION_HEADER_CLOSING_SCOPE]) {
        /* printf("--- searching [in/eq/de]dents\n"); */

        bool did_see_newline = false;

        lexer->mark_end(lexer);

        while (lexer->lookahead == '\n') {
            lexer->advance(lexer, true);
            did_see_newline = true;
        }


        if (col == 0 || did_see_newline) { // started at or moved to col 0

            if (lexer->lookahead == '#' && valid_symbols[SECTION_HEADER_CLOSING_SCOPE]) {
                // _item_scope section header end
                while (lexer->lookahead == '#') {
                    lexer->advance(lexer, true);
                }

                if (lexer->lookahead == ' ') {
                    // Reset columns
                    scanner->last_indent_column = 0;
                    scanner->emitted_indent_column = 0;

                    lexer->result_symbol = SECTION_HEADER_CLOSING_SCOPE;
                    return true;
                }

            } else {
                // dents
                // consume the newlines
                lexer->mark_end(lexer);

                // Still have dedents that need to be emitted - don't care about the spaces
                if (valid_symbols[DEDENT] && scanner->emitted_indent_column > scanner->last_indent_column) {
                    /* printf("--- had queued dedent\n"); */
                    lexer->result_symbol = DEDENT;

                    scanner->emitted_indent_column = scanner->emitted_indent_column - 2;

                    return true;
                }

                int spaces = find_marker_column(lexer);
                /* printf("--- spaces: %i\n", spaces); */
                /* printf("--- last col: %i\n", scanner->last_indent_column); */

                if (spaces != -1) {
                    if (valid_symbols[INDENT]) {
                        if (spaces == scanner->last_indent_column + 2) {

                            lexer->mark_end(lexer);
                            lexer->result_symbol = INDENT;

                            scanner->last_indent_column = spaces;
                            scanner->emitted_indent_column = spaces;

                            return true;
                        }
                    }

                    if (valid_symbols[EQDENT]) {
                        if (spaces == scanner->last_indent_column && !lexer->eof(lexer)) {

                            lexer->mark_end(lexer);
                            lexer->result_symbol = EQDENT;

                            scanner->last_indent_column = spaces;
                            scanner->emitted_indent_column = spaces;

                            return true;
                        }
                    }

                    if (valid_symbols[DEDENT]) {
                        if (did_see_newline) {
                            // See a dedent
                            if (spaces < scanner->last_indent_column && spaces % 2 == 0) {

                                // don't mark_end, we don't want the spaces after dedent so that an eqdent can immediately follow
                                lexer->result_symbol = DEDENT;

                                scanner->emitted_indent_column = scanner->last_indent_column - 2;
                                scanner->last_indent_column = spaces;

                                return true;
                            }
                        }
                    }
                }
            }
        }
    }


    if ((valid_symbols[SECTION_IN] || valid_symbols[SECTION_IN] || valid_symbols[SECTION_EQ]) && (col == 0)) {
        lexer->mark_end(lexer);

        int depth = 0;
        enum TokenType symbol = try_find_section_symbol(scanner, lexer, valid_symbols, &depth);
        /* printf("--- Section symbol: %i\n", symbol); */

        switch (symbol) {
            case SECTION_IN:
            case SECTION_DE:
            case SECTION_EQ: {
                if (symbol == SECTION_IN) {
                    scanner->emitted_section_depth = scanner->last_section_depth + 1;
                } else if (symbol == SECTION_DE) {
                    scanner->emitted_section_depth = scanner->last_section_depth - 1;
                }

                lexer->result_symbol = symbol;
                scanner->last_section_depth = depth;

                return true;
            }
        }
    }

    if (valid_symbols[END_OF_FILE]) {
        while(lexer->lookahead == '\n') {
            lexer->advance(lexer, false);
        }

        if (lexer->eof(lexer)) {
            lexer->mark_end(lexer);
            lexer->result_symbol = END_OF_FILE;
            return true;
        }
    }

    return false;
}
