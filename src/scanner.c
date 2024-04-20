#include "tree_sitter/parser.h"

enum TokenType {
    INDENT,
    DEDENT,
    EQDENT,
    SECTION_IN,
    SECTION_OUT,
    SECTION_SIBLING,
    END_OF_FILE
};

typedef struct {
    unsigned int last_indent_column;
    unsigned int emitted_indent_column;
    unsigned int last_section_depth;
    unsigned int emitted_section_depth;
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
        memcpy(payload, buffer, sizeof(Scanner));
    } else {
        // reset
        Scanner *scanner = (Scanner *)payload;
        scanner->last_indent_column = 0;
        scanner->emitted_indent_column = 0;
        scanner->last_section_depth = 0;
        scanner->emitted_section_depth = 0;
    }
}

bool tree_sitter_note_external_scanner_scan(
  void *payload,
  TSLexer *lexer,
  const bool *valid_symbols
) {
    Scanner *scanner = (Scanner *)payload;

    while (lexer->lookahead == '\n') {
        lexer->advance(lexer, true);
    }

    if (valid_symbols[END_OF_FILE] && lexer->eof(lexer)) {
        lexer->result_symbol = END_OF_FILE;
        return true;
    }

    if (valid_symbols[INDENT] || valid_symbols[DEDENT] || valid_symbols[EQDENT]) {
        unsigned int spaces = 0;

        lexer->mark_end(lexer);

        while (lexer->lookahead == ' ') {
            spaces++;
            lexer->advance(lexer, true);
        }

        switch (lexer->lookahead) {
            case '-':
            case '.':
            case ',':
            case '=':
            case '*':
            case '[': {
                // next char needs to be space
                lexer->advance(lexer, true);
                if (lexer->lookahead != ' ') {
                    return false;
                }

                // next char can't be newline
                lexer->advance(lexer, true);
                if (lexer->lookahead == '\n' || lexer->lookahead == '\r') {
                    return false;
                }

                if (valid_symbols[INDENT]) {
                    if (spaces == scanner->last_indent_column + 2) {

                        lexer->result_symbol = INDENT;
                        scanner->last_indent_column = spaces;
                        scanner->emitted_indent_column = spaces;

                        return true;
                    }
                }

                if (valid_symbols[DEDENT]) {
                    if (spaces < scanner->last_indent_column && spaces % 2 == 0) {
                        lexer->result_symbol = DEDENT;
                        scanner->emitted_indent_column = scanner->last_indent_column - 2;
                        scanner->last_indent_column = spaces;

                        return true;
                    }

                    if (scanner->emitted_indent_column > scanner->last_indent_column) {
                        lexer->result_symbol = DEDENT;
                        scanner->emitted_indent_column = scanner->emitted_indent_column - 2;

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
            default:
                // our next token isn't a marker
                break;
        }

    }

    if (valid_symbols[SECTION_IN] || valid_symbols[SECTION_OUT] || valid_symbols[SECTION_SIBLING]) {
        unsigned int depth = 0;

        lexer->mark_end(lexer);
            // we don't consume '#' since they're used for section_header
            // section in and out are zero width

        while (lexer->lookahead == '#') {
            depth++;
            lexer->advance(lexer, false);
        }

        if (lexer->lookahead != ' ') {
            // we need a space after the #
            return false;
        }

        if (valid_symbols[SECTION_IN]) {
            if (depth == scanner->last_section_depth + 1) {

                lexer->result_symbol = SECTION_IN;
                scanner->last_section_depth = depth;
                scanner->emitted_section_depth = depth;
                scanner->last_indent_column = 0;
                scanner->emitted_indent_column = 0;

                return true;
            }
        }

        if (valid_symbols[SECTION_OUT]) {
            if (depth < scanner->last_section_depth) {
                lexer->result_symbol = SECTION_OUT;
                scanner->emitted_section_depth = scanner->last_section_depth - 1;
                scanner->last_section_depth = depth;
                scanner->last_indent_column = 0;
                scanner->emitted_indent_column = 0;

                return true;
            }

            if (scanner->emitted_section_depth > scanner->last_section_depth) {
                lexer->result_symbol = SECTION_OUT;
                scanner->emitted_section_depth = scanner->emitted_section_depth - 1;
                scanner->last_indent_column = 0;
                scanner->emitted_indent_column = 0;

                return true;
            }
        }

        if (valid_symbols[SECTION_SIBLING]) {
            if (depth == scanner->last_section_depth) {
                lexer->result_symbol = SECTION_SIBLING;
                scanner->last_indent_column = 0;
                scanner->emitted_indent_column = 0;

                return true;
            }
        }
    }

    return false;
}
