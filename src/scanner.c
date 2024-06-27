#include "tree_sitter/parser.h"
#include <stdio.h>

enum TokenType {
    INDENT,
    DEDENT,
    EQDENT,
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

// mark_end true marks the end after consuming the whitespaces
// all advances are skip false https://github.com/tree-sitter/tree-sitter/issues/2315
// advance skip true really means mark begin, so needs to be handled in the calling context of this function
int find_marker_column(TSLexer *lexer, bool mark_end) {
    int spaces = 0;
    printf("--- Finding marker, mark_end: %s\n", mark_end ? "true" : "false");

    while (lexer->lookahead == ' ') {
        spaces++;
        lexer->advance(lexer, false);
    }

    if (mark_end) {
        printf("--- Mark end after spaces: %i\n", spaces);
        lexer->mark_end(lexer);
    }

    switch (lexer->lookahead) {
        case '-':
        case '.':
        case ',':
        case '=':
        case '*':
        case '[': {
            // next char needs to be space
            lexer->advance(lexer, false);
            if (lexer->lookahead != ' ') {
                return -1;
            }

            // next char can't be newline
            lexer->advance(lexer, false);
            if (lexer->lookahead == '\n' || lexer->lookahead == '\r') {
                return -1;
            }

            return spaces;
        }
        default:
            return -1;
    }
}

void print_debugs(const bool *valid_symbols) {
    printf("--- lex\n");
    if (valid_symbols[INDENT]) { printf("--- valid: INDENT\n"); }
    if (valid_symbols[DEDENT]) { printf("--- valid: DEDENT\n"); }
    if (valid_symbols[EQDENT]) { printf("--- valid: EQDENT\n"); }
    if (valid_symbols[END_OF_FILE]) { printf("--- valid: END_OF_FILE\n"); }

    if (valid_symbols[ERROR_RECOVERY]) { printf("--- valid: ERROR_RECOVERY\n"); }

    if (valid_symbols[ERROR_RECOVERY]) {
        printf("--- error\n");
        // docs seem to be wrong? error_recovery can be valid without all other tokens being valid
        // or some sort of cache issue is causing the token enum to get out of sync between grammar.json and this?
        /* return false; */
    }

    if (valid_symbols[INDENT]
        && valid_symbols[EQDENT]
        && valid_symbols[DEDENT]
    ) {
        printf("--- OOPS: [in/eq/de]dent all valid\n");
    }
}

bool tree_sitter_note_external_scanner_scan(
  void *payload,
  TSLexer *lexer,
  const bool *valid_symbols
) {
    Scanner *scanner = (Scanner *)payload;

    print_debugs(valid_symbols);

    if (valid_symbols[DEDENT]) {
        printf("--- searching dedent\n");

        // Still have dedents that need to be emitted
        if (scanner->emitted_indent_column > scanner->last_indent_column) {

            printf("--- had queued dedent\n");
            lexer->result_symbol = DEDENT;

            scanner->emitted_indent_column = scanner->emitted_indent_column - 2;

            return true;
        }

        bool did_see_newline = false;

        // mark_end then advance skip makes this 0-width, doesn't consume the newline
        lexer->mark_end(lexer);

        while (lexer->lookahead == '\n') {
            printf("--- dedent consume newline\n");
            lexer->advance(lexer, true);
            did_see_newline = true;
        }

        if (did_see_newline) {
            int spaces = find_marker_column(lexer, false);

            // See a dedent
            if (spaces < scanner->last_indent_column && spaces % 2 == 0) {

                lexer->result_symbol = DEDENT;

                scanner->emitted_indent_column = scanner->last_indent_column - 2;
                scanner->last_indent_column = spaces;

                return true;
            }

        }
    }


    if (valid_symbols[INDENT] || valid_symbols[EQDENT]) {
        printf("--- searching [in/eq]dents\n");

        if (lexer->get_column(lexer) != 0) {
            printf("--- not col 0\n");
            return false;
        }

        int spaces = find_marker_column(lexer, true);
        printf("--- spaces: %i\n", spaces);

        if (spaces != -1) {
            if (valid_symbols[INDENT]) {
                if (spaces == scanner->last_indent_column + 2) {

                    lexer->result_symbol = INDENT;

                    scanner->last_indent_column = spaces;
                    scanner->emitted_indent_column = spaces;

                    return true;
                }
            }

            if (valid_symbols[EQDENT]) {
                if (spaces == scanner->last_indent_column) {

                    lexer->result_symbol = EQDENT;

                    scanner->last_indent_column = spaces;
                    scanner->emitted_indent_column = spaces;

                    return true;
                }
            }

            return false;
        }
    }

    if (valid_symbols[END_OF_FILE]) {
        while(lexer->lookahead == '\n') {
            lexer->advance(lexer, true);
        }

        if (lexer->eof(lexer)) {
            lexer->result_symbol = END_OF_FILE;
            return true;
        }

        return false;
    }

    return false;
}
