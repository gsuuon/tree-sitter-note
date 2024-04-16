#include "tree_sitter/parser.h"
#include "tree_sitter/alloc.h"
#include "tree_sitter/array.h"

enum TokenType {
    INDENT,
    DEDENT,
    END_OF_FILE
};

typedef struct {
    unsigned int last_indent_column;
    unsigned int emitted_indent_column;
} Scanner;


void *tree_sitter_note_external_scanner_create(void) {
    return ts_calloc(1, sizeof(Scanner));
}

void tree_sitter_note_external_scanner_destroy(void *payload) {
    ts_free(payload);
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
        memcpy(payload, buffer, sizeof(Scanner));
    }
}

bool tree_sitter_note_external_scanner_scan(
  void *payload,
  TSLexer *lexer,
  const bool *valid_symbols
) {
    Scanner *scanner = (Scanner *)payload;
    unsigned int current_column = lexer->get_column(lexer);
    unsigned int spaces = 0;

    if (lexer->lookahead == '\n') {
        lexer->advance(lexer, true);
    }

    while (lexer->lookahead == ' ') {
        spaces++;
        lexer->advance(lexer, false);
    }

    if (valid_symbols[END_OF_FILE] && lexer->eof(lexer)) {

        lexer->result_symbol = END_OF_FILE;
        return true;
    }

    switch (lexer->lookahead) {
        case '-':
        case '.':
        case ',':
        case '=':
        case '*':
        case '[':
            break;
        default:
            // our next token isn't a marker
            return false;
    }

    if (valid_symbols[INDENT]) {
        /* printf( */
        /*     "---- Checking for indent. current_column: %d, last_indent_column: %d, spaces: %d\n", */
        /*     current_column, */
        /*     scanner->last_indent_column, */
        /*     spaces */
        /* ); */

        if (spaces == scanner->last_indent_column + 2) {

            lexer->result_symbol = INDENT;
            scanner->last_indent_column = spaces;
            scanner->emitted_indent_column = spaces;

            return true;
        }
    }

    if (valid_symbols[DEDENT]) {
        /* printf( */
        /*     "[DEDENT] spaces: %d, last_indent_column: %d, emitted_indent_column: %d\n", */
        /*     spaces, */
        /*     scanner->last_indent_column, */
        /*     scanner->emitted_indent_column */
        /* ); */

        if (spaces < scanner->last_indent_column && spaces % 2 == 0) {
            lexer->result_symbol = DEDENT;
            scanner->emitted_indent_column = scanner->last_indent_column - 2;
            scanner->last_indent_column = spaces;
            /* printf("[DEDENT] emit dedent because current spaces less than last_indent_column\n"); */

            return true;
        }

        if (scanner->emitted_indent_column > scanner->last_indent_column) {
            lexer->result_symbol = DEDENT;
            scanner->emitted_indent_column = scanner->emitted_indent_column - 2;
            /* printf("[DEDENT] emit dedent because emitted indents less than last_indent_column\n"); */

            return true;
        }
    }

    return false;
}
