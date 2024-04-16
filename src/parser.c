#include "tree_sitter/parser.h"

#if defined(__GNUC__) || defined(__clang__)
#pragma GCC diagnostic ignored "-Wmissing-field-initializers"
#endif

#define LANGUAGE_VERSION 14
#define STATE_COUNT 59
#define LARGE_STATE_COUNT 4
#define SYMBOL_COUNT 26
#define ALIAS_COUNT 0
#define TOKEN_COUNT 11
#define EXTERNAL_TOKEN_COUNT 3
#define FIELD_COUNT 0
#define MAX_ALIAS_SEQUENCE_LENGTH 6
#define PRODUCTION_ID_COUNT 1

enum ts_symbol_identifiers {
  sym_marker_task_pending = 1,
  sym_marker_task_done = 2,
  sym_marker_property_info = 3,
  sym_marker_property_label = 4,
  sym__line = 5,
  sym__newline = 6,
  anon_sym_BQUOTE_BQUOTE_BQUOTE = 7,
  sym__indent = 8,
  sym__dedent = 9,
  sym__eof = 10,
  sym_document = 11,
  sym_marker_task = 12,
  sym_marker_property = 13,
  sym_marker = 14,
  sym_content = 15,
  sym_body = 16,
  sym_item = 17,
  sym_children = 18,
  aux_sym__lines = 19,
  sym_code_block_language = 20,
  sym_code_block_content = 21,
  sym_code_block = 22,
  aux_sym_document_repeat1 = 23,
  aux_sym_body_repeat1 = 24,
  aux_sym_children_repeat1 = 25,
};

static const char * const ts_symbol_names[] = {
  [ts_builtin_sym_end] = "end",
  [sym_marker_task_pending] = "marker_task_pending",
  [sym_marker_task_done] = "marker_task_done",
  [sym_marker_property_info] = "marker_property_info",
  [sym_marker_property_label] = "marker_property_label",
  [sym__line] = "_line",
  [sym__newline] = "_newline",
  [anon_sym_BQUOTE_BQUOTE_BQUOTE] = "```",
  [sym__indent] = "_indent",
  [sym__dedent] = "_dedent",
  [sym__eof] = "_eof",
  [sym_document] = "document",
  [sym_marker_task] = "marker_task",
  [sym_marker_property] = "marker_property",
  [sym_marker] = "marker",
  [sym_content] = "content",
  [sym_body] = "body",
  [sym_item] = "item",
  [sym_children] = "children",
  [aux_sym__lines] = "_lines",
  [sym_code_block_language] = "code_block_language",
  [sym_code_block_content] = "code_block_content",
  [sym_code_block] = "code_block",
  [aux_sym_document_repeat1] = "document_repeat1",
  [aux_sym_body_repeat1] = "body_repeat1",
  [aux_sym_children_repeat1] = "children_repeat1",
};

static const TSSymbol ts_symbol_map[] = {
  [ts_builtin_sym_end] = ts_builtin_sym_end,
  [sym_marker_task_pending] = sym_marker_task_pending,
  [sym_marker_task_done] = sym_marker_task_done,
  [sym_marker_property_info] = sym_marker_property_info,
  [sym_marker_property_label] = sym_marker_property_label,
  [sym__line] = sym__line,
  [sym__newline] = sym__newline,
  [anon_sym_BQUOTE_BQUOTE_BQUOTE] = anon_sym_BQUOTE_BQUOTE_BQUOTE,
  [sym__indent] = sym__indent,
  [sym__dedent] = sym__dedent,
  [sym__eof] = sym__eof,
  [sym_document] = sym_document,
  [sym_marker_task] = sym_marker_task,
  [sym_marker_property] = sym_marker_property,
  [sym_marker] = sym_marker,
  [sym_content] = sym_content,
  [sym_body] = sym_body,
  [sym_item] = sym_item,
  [sym_children] = sym_children,
  [aux_sym__lines] = aux_sym__lines,
  [sym_code_block_language] = sym_code_block_language,
  [sym_code_block_content] = sym_code_block_content,
  [sym_code_block] = sym_code_block,
  [aux_sym_document_repeat1] = aux_sym_document_repeat1,
  [aux_sym_body_repeat1] = aux_sym_body_repeat1,
  [aux_sym_children_repeat1] = aux_sym_children_repeat1,
};

static const TSSymbolMetadata ts_symbol_metadata[] = {
  [ts_builtin_sym_end] = {
    .visible = false,
    .named = true,
  },
  [sym_marker_task_pending] = {
    .visible = true,
    .named = true,
  },
  [sym_marker_task_done] = {
    .visible = true,
    .named = true,
  },
  [sym_marker_property_info] = {
    .visible = true,
    .named = true,
  },
  [sym_marker_property_label] = {
    .visible = true,
    .named = true,
  },
  [sym__line] = {
    .visible = false,
    .named = true,
  },
  [sym__newline] = {
    .visible = false,
    .named = true,
  },
  [anon_sym_BQUOTE_BQUOTE_BQUOTE] = {
    .visible = true,
    .named = false,
  },
  [sym__indent] = {
    .visible = false,
    .named = true,
  },
  [sym__dedent] = {
    .visible = false,
    .named = true,
  },
  [sym__eof] = {
    .visible = false,
    .named = true,
  },
  [sym_document] = {
    .visible = true,
    .named = true,
  },
  [sym_marker_task] = {
    .visible = true,
    .named = true,
  },
  [sym_marker_property] = {
    .visible = true,
    .named = true,
  },
  [sym_marker] = {
    .visible = true,
    .named = true,
  },
  [sym_content] = {
    .visible = true,
    .named = true,
  },
  [sym_body] = {
    .visible = true,
    .named = true,
  },
  [sym_item] = {
    .visible = true,
    .named = true,
  },
  [sym_children] = {
    .visible = true,
    .named = true,
  },
  [aux_sym__lines] = {
    .visible = false,
    .named = false,
  },
  [sym_code_block_language] = {
    .visible = true,
    .named = true,
  },
  [sym_code_block_content] = {
    .visible = true,
    .named = true,
  },
  [sym_code_block] = {
    .visible = true,
    .named = true,
  },
  [aux_sym_document_repeat1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_body_repeat1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_children_repeat1] = {
    .visible = false,
    .named = false,
  },
};

static const TSSymbol ts_alias_sequences[PRODUCTION_ID_COUNT][MAX_ALIAS_SEQUENCE_LENGTH] = {
  [0] = {0},
};

static const uint16_t ts_non_terminal_alias_map[] = {
  0,
};

static const TSStateId ts_primary_state_ids[STATE_COUNT] = {
  [0] = 0,
  [1] = 1,
  [2] = 2,
  [3] = 2,
  [4] = 4,
  [5] = 5,
  [6] = 5,
  [7] = 4,
  [8] = 8,
  [9] = 9,
  [10] = 9,
  [11] = 11,
  [12] = 12,
  [13] = 13,
  [14] = 14,
  [15] = 15,
  [16] = 16,
  [17] = 8,
  [18] = 16,
  [19] = 19,
  [20] = 19,
  [21] = 14,
  [22] = 12,
  [23] = 23,
  [24] = 23,
  [25] = 25,
  [26] = 25,
  [27] = 27,
  [28] = 28,
  [29] = 29,
  [30] = 29,
  [31] = 27,
  [32] = 32,
  [33] = 33,
  [34] = 33,
  [35] = 35,
  [36] = 35,
  [37] = 37,
  [38] = 38,
  [39] = 37,
  [40] = 8,
  [41] = 41,
  [42] = 41,
  [43] = 43,
  [44] = 44,
  [45] = 45,
  [46] = 46,
  [47] = 47,
  [48] = 48,
  [49] = 49,
  [50] = 50,
  [51] = 43,
  [52] = 52,
  [53] = 53,
  [54] = 54,
  [55] = 54,
  [56] = 50,
  [57] = 53,
  [58] = 48,
};

static bool ts_lex(TSLexer *lexer, TSStateId state) {
  START_LEXER();
  eof = lexer->eof(lexer);
  switch (state) {
    case 0:
      if (eof) ADVANCE(11);
      if (lookahead == '\n') ADVANCE(30);
      if (lookahead == '*') ADVANCE(22);
      if (lookahead == '-') ADVANCE(23);
      if (lookahead == '.') ADVANCE(24);
      if (lookahead == '[') ADVANCE(25);
      if (lookahead == '`') ADVANCE(27);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') ADVANCE(20);
      if (lookahead != 0) ADVANCE(29);
      END_STATE();
    case 1:
      if (lookahead == '\n') ADVANCE(31);
      if (lookahead == '*') ADVANCE(4);
      if (lookahead == '-') ADVANCE(5);
      if (lookahead == '.') ADVANCE(6);
      if (lookahead == '[') ADVANCE(7);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(1);
      END_STATE();
    case 2:
      if (lookahead == '\n') ADVANCE(32);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') ADVANCE(21);
      if (lookahead != 0) ADVANCE(29);
      END_STATE();
    case 3:
      if (lookahead == '\n') SKIP(3);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') ADVANCE(28);
      if (lookahead != 0) ADVANCE(29);
      END_STATE();
    case 4:
      if (lookahead == ' ') ADVANCE(16);
      END_STATE();
    case 5:
      if (lookahead == ' ') ADVANCE(12);
      END_STATE();
    case 6:
      if (lookahead == ' ') ADVANCE(14);
      END_STATE();
    case 7:
      if (lookahead == ' ') ADVANCE(18);
      END_STATE();
    case 8:
      if (lookahead == '*') ADVANCE(4);
      if (lookahead == '-') ADVANCE(5);
      if (lookahead == '.') ADVANCE(6);
      if (lookahead == '[') ADVANCE(7);
      if (lookahead == '`') ADVANCE(10);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(8);
      END_STATE();
    case 9:
      if (lookahead == '`') ADVANCE(33);
      END_STATE();
    case 10:
      if (lookahead == '`') ADVANCE(9);
      END_STATE();
    case 11:
      ACCEPT_TOKEN(ts_builtin_sym_end);
      END_STATE();
    case 12:
      ACCEPT_TOKEN(sym_marker_task_pending);
      END_STATE();
    case 13:
      ACCEPT_TOKEN(sym_marker_task_pending);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(29);
      END_STATE();
    case 14:
      ACCEPT_TOKEN(sym_marker_task_done);
      END_STATE();
    case 15:
      ACCEPT_TOKEN(sym_marker_task_done);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(29);
      END_STATE();
    case 16:
      ACCEPT_TOKEN(sym_marker_property_info);
      END_STATE();
    case 17:
      ACCEPT_TOKEN(sym_marker_property_info);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(29);
      END_STATE();
    case 18:
      ACCEPT_TOKEN(sym_marker_property_label);
      END_STATE();
    case 19:
      ACCEPT_TOKEN(sym_marker_property_label);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(29);
      END_STATE();
    case 20:
      ACCEPT_TOKEN(sym__line);
      if (lookahead == '\n') ADVANCE(30);
      if (lookahead == '*') ADVANCE(22);
      if (lookahead == '-') ADVANCE(23);
      if (lookahead == '.') ADVANCE(24);
      if (lookahead == '[') ADVANCE(25);
      if (lookahead == '`') ADVANCE(27);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') ADVANCE(20);
      if (lookahead != 0) ADVANCE(29);
      END_STATE();
    case 21:
      ACCEPT_TOKEN(sym__line);
      if (lookahead == '\n') ADVANCE(32);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') ADVANCE(21);
      if (lookahead != 0) ADVANCE(29);
      END_STATE();
    case 22:
      ACCEPT_TOKEN(sym__line);
      if (lookahead == ' ') ADVANCE(17);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(29);
      END_STATE();
    case 23:
      ACCEPT_TOKEN(sym__line);
      if (lookahead == ' ') ADVANCE(13);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(29);
      END_STATE();
    case 24:
      ACCEPT_TOKEN(sym__line);
      if (lookahead == ' ') ADVANCE(15);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(29);
      END_STATE();
    case 25:
      ACCEPT_TOKEN(sym__line);
      if (lookahead == ' ') ADVANCE(19);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(29);
      END_STATE();
    case 26:
      ACCEPT_TOKEN(sym__line);
      if (lookahead == '`') ADVANCE(33);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(29);
      END_STATE();
    case 27:
      ACCEPT_TOKEN(sym__line);
      if (lookahead == '`') ADVANCE(26);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(29);
      END_STATE();
    case 28:
      ACCEPT_TOKEN(sym__line);
      if (lookahead == '\t' ||
          (0x0b <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') ADVANCE(28);
      if (lookahead != 0 &&
          (lookahead < '\t' || '\r' < lookahead)) ADVANCE(29);
      END_STATE();
    case 29:
      ACCEPT_TOKEN(sym__line);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(29);
      END_STATE();
    case 30:
      ACCEPT_TOKEN(sym__newline);
      if (lookahead == '\n') ADVANCE(30);
      if (lookahead == '`') ADVANCE(27);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') ADVANCE(20);
      END_STATE();
    case 31:
      ACCEPT_TOKEN(sym__newline);
      if (lookahead == '\n') ADVANCE(31);
      END_STATE();
    case 32:
      ACCEPT_TOKEN(sym__newline);
      if (lookahead == '\n') ADVANCE(32);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') ADVANCE(21);
      END_STATE();
    case 33:
      ACCEPT_TOKEN(anon_sym_BQUOTE_BQUOTE_BQUOTE);
      END_STATE();
    default:
      return false;
  }
}

static const TSLexMode ts_lex_modes[STATE_COUNT] = {
  [0] = {.lex_state = 0, .external_lex_state = 1},
  [1] = {.lex_state = 8},
  [2] = {.lex_state = 0, .external_lex_state = 1},
  [3] = {.lex_state = 0, .external_lex_state = 2},
  [4] = {.lex_state = 0, .external_lex_state = 1},
  [5] = {.lex_state = 0, .external_lex_state = 1},
  [6] = {.lex_state = 0, .external_lex_state = 2},
  [7] = {.lex_state = 0, .external_lex_state = 2},
  [8] = {.lex_state = 0, .external_lex_state = 1},
  [9] = {.lex_state = 8, .external_lex_state = 3},
  [10] = {.lex_state = 8, .external_lex_state = 3},
  [11] = {.lex_state = 8, .external_lex_state = 3},
  [12] = {.lex_state = 0, .external_lex_state = 1},
  [13] = {.lex_state = 8, .external_lex_state = 4},
  [14] = {.lex_state = 0, .external_lex_state = 1},
  [15] = {.lex_state = 8, .external_lex_state = 4},
  [16] = {.lex_state = 0, .external_lex_state = 1},
  [17] = {.lex_state = 0, .external_lex_state = 2},
  [18] = {.lex_state = 0, .external_lex_state = 2},
  [19] = {.lex_state = 8},
  [20] = {.lex_state = 8},
  [21] = {.lex_state = 0, .external_lex_state = 2},
  [22] = {.lex_state = 0, .external_lex_state = 2},
  [23] = {.lex_state = 8, .external_lex_state = 1},
  [24] = {.lex_state = 1, .external_lex_state = 2},
  [25] = {.lex_state = 8, .external_lex_state = 3},
  [26] = {.lex_state = 1, .external_lex_state = 4},
  [27] = {.lex_state = 1, .external_lex_state = 4},
  [28] = {.lex_state = 1, .external_lex_state = 4},
  [29] = {.lex_state = 1, .external_lex_state = 4},
  [30] = {.lex_state = 8, .external_lex_state = 3},
  [31] = {.lex_state = 8, .external_lex_state = 3},
  [32] = {.lex_state = 8, .external_lex_state = 4},
  [33] = {.lex_state = 2},
  [34] = {.lex_state = 2},
  [35] = {.lex_state = 2},
  [36] = {.lex_state = 2},
  [37] = {.lex_state = 2},
  [38] = {.lex_state = 2},
  [39] = {.lex_state = 2},
  [40] = {.lex_state = 2},
  [41] = {.lex_state = 3},
  [42] = {.lex_state = 3},
  [43] = {.lex_state = 8},
  [44] = {.lex_state = 3},
  [45] = {.lex_state = 0},
  [46] = {.lex_state = 1},
  [47] = {.lex_state = 3},
  [48] = {.lex_state = 1},
  [49] = {.lex_state = 0},
  [50] = {.lex_state = 8},
  [51] = {.lex_state = 8},
  [52] = {.lex_state = 3},
  [53] = {.lex_state = 1},
  [54] = {.lex_state = 1},
  [55] = {.lex_state = 1},
  [56] = {.lex_state = 8},
  [57] = {.lex_state = 1},
  [58] = {.lex_state = 1},
};

static const uint16_t ts_parse_table[LARGE_STATE_COUNT][SYMBOL_COUNT] = {
  [0] = {
    [ts_builtin_sym_end] = ACTIONS(1),
    [sym_marker_task_pending] = ACTIONS(1),
    [sym_marker_task_done] = ACTIONS(1),
    [sym_marker_property_info] = ACTIONS(1),
    [sym_marker_property_label] = ACTIONS(1),
    [sym__line] = ACTIONS(1),
    [sym__newline] = ACTIONS(1),
    [anon_sym_BQUOTE_BQUOTE_BQUOTE] = ACTIONS(1),
    [sym__indent] = ACTIONS(1),
    [sym__dedent] = ACTIONS(1),
    [sym__eof] = ACTIONS(1),
  },
  [1] = {
    [sym_document] = STATE(49),
    [sym_marker_task] = STATE(47),
    [sym_marker_property] = STATE(47),
    [sym_marker] = STATE(42),
    [sym_item] = STATE(28),
    [aux_sym_document_repeat1] = STATE(13),
    [sym_marker_task_pending] = ACTIONS(3),
    [sym_marker_task_done] = ACTIONS(3),
    [sym_marker_property_info] = ACTIONS(5),
    [sym_marker_property_label] = ACTIONS(5),
  },
  [2] = {
    [sym_body] = STATE(23),
    [sym_children] = STATE(30),
    [aux_sym__lines] = STATE(5),
    [sym_code_block] = STATE(5),
    [aux_sym_body_repeat1] = STATE(5),
    [sym_marker_task_pending] = ACTIONS(7),
    [sym_marker_task_done] = ACTIONS(7),
    [sym_marker_property_info] = ACTIONS(7),
    [sym_marker_property_label] = ACTIONS(7),
    [sym__line] = ACTIONS(9),
    [sym__newline] = ACTIONS(9),
    [anon_sym_BQUOTE_BQUOTE_BQUOTE] = ACTIONS(11),
    [sym__indent] = ACTIONS(13),
    [sym__dedent] = ACTIONS(15),
    [sym__eof] = ACTIONS(15),
  },
  [3] = {
    [sym_body] = STATE(24),
    [sym_children] = STATE(29),
    [aux_sym__lines] = STATE(6),
    [sym_code_block] = STATE(6),
    [aux_sym_body_repeat1] = STATE(6),
    [sym_marker_task_pending] = ACTIONS(7),
    [sym_marker_task_done] = ACTIONS(7),
    [sym_marker_property_info] = ACTIONS(7),
    [sym_marker_property_label] = ACTIONS(7),
    [sym__line] = ACTIONS(17),
    [sym__newline] = ACTIONS(17),
    [anon_sym_BQUOTE_BQUOTE_BQUOTE] = ACTIONS(19),
    [sym__indent] = ACTIONS(21),
    [sym__eof] = ACTIONS(15),
  },
};

static const uint16_t ts_small_parse_table[] = {
  [0] = 5,
    ACTIONS(28), 1,
      anon_sym_BQUOTE_BQUOTE_BQUOTE,
    ACTIONS(25), 2,
      sym__line,
      sym__newline,
    ACTIONS(31), 3,
      sym__indent,
      sym__dedent,
      sym__eof,
    STATE(4), 3,
      aux_sym__lines,
      sym_code_block,
      aux_sym_body_repeat1,
    ACTIONS(23), 4,
      sym_marker_task_pending,
      sym_marker_task_done,
      sym_marker_property_info,
      sym_marker_property_label,
  [24] = 5,
    ACTIONS(11), 1,
      anon_sym_BQUOTE_BQUOTE_BQUOTE,
    ACTIONS(35), 2,
      sym__line,
      sym__newline,
    ACTIONS(37), 3,
      sym__indent,
      sym__dedent,
      sym__eof,
    STATE(4), 3,
      aux_sym__lines,
      sym_code_block,
      aux_sym_body_repeat1,
    ACTIONS(33), 4,
      sym_marker_task_pending,
      sym_marker_task_done,
      sym_marker_property_info,
      sym_marker_property_label,
  [48] = 5,
    ACTIONS(19), 1,
      anon_sym_BQUOTE_BQUOTE_BQUOTE,
    ACTIONS(37), 2,
      sym__indent,
      sym__eof,
    ACTIONS(39), 2,
      sym__line,
      sym__newline,
    STATE(7), 3,
      aux_sym__lines,
      sym_code_block,
      aux_sym_body_repeat1,
    ACTIONS(33), 4,
      sym_marker_task_pending,
      sym_marker_task_done,
      sym_marker_property_info,
      sym_marker_property_label,
  [71] = 5,
    ACTIONS(44), 1,
      anon_sym_BQUOTE_BQUOTE_BQUOTE,
    ACTIONS(31), 2,
      sym__indent,
      sym__eof,
    ACTIONS(41), 2,
      sym__line,
      sym__newline,
    STATE(7), 3,
      aux_sym__lines,
      sym_code_block,
      aux_sym_body_repeat1,
    ACTIONS(23), 4,
      sym_marker_task_pending,
      sym_marker_task_done,
      sym_marker_property_info,
      sym_marker_property_label,
  [94] = 4,
    STATE(8), 1,
      aux_sym__lines,
    ACTIONS(49), 2,
      sym__line,
      sym__newline,
    ACTIONS(52), 3,
      sym__indent,
      sym__dedent,
      sym__eof,
    ACTIONS(47), 5,
      sym_marker_task_pending,
      sym_marker_task_done,
      sym_marker_property_info,
      sym_marker_property_label,
      anon_sym_BQUOTE_BQUOTE_BQUOTE,
  [114] = 6,
    STATE(41), 1,
      sym_marker,
    ACTIONS(3), 2,
      sym_marker_task_pending,
      sym_marker_task_done,
    ACTIONS(5), 2,
      sym_marker_property_info,
      sym_marker_property_label,
    ACTIONS(54), 2,
      sym__dedent,
      sym__eof,
    STATE(11), 2,
      sym_item,
      aux_sym_children_repeat1,
    STATE(47), 2,
      sym_marker_task,
      sym_marker_property,
  [138] = 6,
    STATE(41), 1,
      sym_marker,
    ACTIONS(3), 2,
      sym_marker_task_pending,
      sym_marker_task_done,
    ACTIONS(5), 2,
      sym_marker_property_info,
      sym_marker_property_label,
    ACTIONS(56), 2,
      sym__dedent,
      sym__eof,
    STATE(11), 2,
      sym_item,
      aux_sym_children_repeat1,
    STATE(47), 2,
      sym_marker_task,
      sym_marker_property,
  [162] = 6,
    STATE(41), 1,
      sym_marker,
    ACTIONS(58), 2,
      sym_marker_task_pending,
      sym_marker_task_done,
    ACTIONS(61), 2,
      sym_marker_property_info,
      sym_marker_property_label,
    ACTIONS(64), 2,
      sym__dedent,
      sym__eof,
    STATE(11), 2,
      sym_item,
      aux_sym_children_repeat1,
    STATE(47), 2,
      sym_marker_task,
      sym_marker_property,
  [186] = 2,
    ACTIONS(68), 3,
      sym__indent,
      sym__dedent,
      sym__eof,
    ACTIONS(66), 7,
      sym_marker_task_pending,
      sym_marker_task_done,
      sym_marker_property_info,
      sym_marker_property_label,
      sym__line,
      sym__newline,
      anon_sym_BQUOTE_BQUOTE_BQUOTE,
  [201] = 7,
    ACTIONS(70), 1,
      sym__eof,
    STATE(15), 1,
      aux_sym_document_repeat1,
    STATE(28), 1,
      sym_item,
    STATE(42), 1,
      sym_marker,
    ACTIONS(3), 2,
      sym_marker_task_pending,
      sym_marker_task_done,
    ACTIONS(5), 2,
      sym_marker_property_info,
      sym_marker_property_label,
    STATE(47), 2,
      sym_marker_task,
      sym_marker_property,
  [226] = 2,
    ACTIONS(74), 3,
      sym__indent,
      sym__dedent,
      sym__eof,
    ACTIONS(72), 7,
      sym_marker_task_pending,
      sym_marker_task_done,
      sym_marker_property_info,
      sym_marker_property_label,
      sym__line,
      sym__newline,
      anon_sym_BQUOTE_BQUOTE_BQUOTE,
  [241] = 7,
    ACTIONS(82), 1,
      sym__eof,
    STATE(15), 1,
      aux_sym_document_repeat1,
    STATE(28), 1,
      sym_item,
    STATE(42), 1,
      sym_marker,
    ACTIONS(76), 2,
      sym_marker_task_pending,
      sym_marker_task_done,
    ACTIONS(79), 2,
      sym_marker_property_info,
      sym_marker_property_label,
    STATE(47), 2,
      sym_marker_task,
      sym_marker_property,
  [266] = 2,
    ACTIONS(86), 3,
      sym__indent,
      sym__dedent,
      sym__eof,
    ACTIONS(84), 7,
      sym_marker_task_pending,
      sym_marker_task_done,
      sym_marker_property_info,
      sym_marker_property_label,
      sym__line,
      sym__newline,
      anon_sym_BQUOTE_BQUOTE_BQUOTE,
  [281] = 4,
    STATE(17), 1,
      aux_sym__lines,
    ACTIONS(52), 2,
      sym__indent,
      sym__eof,
    ACTIONS(88), 2,
      sym__line,
      sym__newline,
    ACTIONS(47), 5,
      sym_marker_task_pending,
      sym_marker_task_done,
      sym_marker_property_info,
      sym_marker_property_label,
      anon_sym_BQUOTE_BQUOTE_BQUOTE,
  [300] = 2,
    ACTIONS(86), 2,
      sym__indent,
      sym__eof,
    ACTIONS(84), 7,
      sym_marker_task_pending,
      sym_marker_task_done,
      sym_marker_property_info,
      sym_marker_property_label,
      sym__line,
      sym__newline,
      anon_sym_BQUOTE_BQUOTE_BQUOTE,
  [314] = 5,
    STATE(41), 1,
      sym_marker,
    ACTIONS(3), 2,
      sym_marker_task_pending,
      sym_marker_task_done,
    ACTIONS(5), 2,
      sym_marker_property_info,
      sym_marker_property_label,
    STATE(9), 2,
      sym_item,
      aux_sym_children_repeat1,
    STATE(47), 2,
      sym_marker_task,
      sym_marker_property,
  [334] = 5,
    STATE(41), 1,
      sym_marker,
    ACTIONS(3), 2,
      sym_marker_task_pending,
      sym_marker_task_done,
    ACTIONS(5), 2,
      sym_marker_property_info,
      sym_marker_property_label,
    STATE(10), 2,
      sym_item,
      aux_sym_children_repeat1,
    STATE(47), 2,
      sym_marker_task,
      sym_marker_property,
  [354] = 2,
    ACTIONS(74), 2,
      sym__indent,
      sym__eof,
    ACTIONS(72), 7,
      sym_marker_task_pending,
      sym_marker_task_done,
      sym_marker_property_info,
      sym_marker_property_label,
      sym__line,
      sym__newline,
      anon_sym_BQUOTE_BQUOTE_BQUOTE,
  [368] = 2,
    ACTIONS(68), 2,
      sym__indent,
      sym__eof,
    ACTIONS(66), 7,
      sym_marker_task_pending,
      sym_marker_task_done,
      sym_marker_property_info,
      sym_marker_property_label,
      sym__line,
      sym__newline,
      anon_sym_BQUOTE_BQUOTE_BQUOTE,
  [382] = 3,
    ACTIONS(13), 1,
      sym__indent,
    STATE(25), 1,
      sym_children,
    ACTIONS(91), 6,
      sym__dedent,
      sym__eof,
      sym_marker_task_pending,
      sym_marker_task_done,
      sym_marker_property_info,
      sym_marker_property_label,
  [397] = 4,
    ACTIONS(21), 1,
      sym__indent,
    STATE(26), 1,
      sym_children,
    ACTIONS(91), 2,
      sym__eof,
      sym__newline,
    ACTIONS(93), 4,
      sym_marker_task_pending,
      sym_marker_task_done,
      sym_marker_property_info,
      sym_marker_property_label,
  [414] = 1,
    ACTIONS(95), 6,
      sym__dedent,
      sym__eof,
      sym_marker_task_pending,
      sym_marker_task_done,
      sym_marker_property_info,
      sym_marker_property_label,
  [423] = 2,
    ACTIONS(95), 2,
      sym__eof,
      sym__newline,
    ACTIONS(97), 4,
      sym_marker_task_pending,
      sym_marker_task_done,
      sym_marker_property_info,
      sym_marker_property_label,
  [434] = 2,
    ACTIONS(101), 2,
      sym__eof,
      sym__newline,
    ACTIONS(99), 4,
      sym_marker_task_pending,
      sym_marker_task_done,
      sym_marker_property_info,
      sym_marker_property_label,
  [445] = 3,
    ACTIONS(105), 1,
      sym__newline,
    ACTIONS(107), 1,
      sym__eof,
    ACTIONS(103), 4,
      sym_marker_task_pending,
      sym_marker_task_done,
      sym_marker_property_info,
      sym_marker_property_label,
  [458] = 2,
    ACTIONS(91), 2,
      sym__eof,
      sym__newline,
    ACTIONS(93), 4,
      sym_marker_task_pending,
      sym_marker_task_done,
      sym_marker_property_info,
      sym_marker_property_label,
  [469] = 1,
    ACTIONS(91), 6,
      sym__dedent,
      sym__eof,
      sym_marker_task_pending,
      sym_marker_task_done,
      sym_marker_property_info,
      sym_marker_property_label,
  [478] = 1,
    ACTIONS(101), 6,
      sym__dedent,
      sym__eof,
      sym_marker_task_pending,
      sym_marker_task_done,
      sym_marker_property_info,
      sym_marker_property_label,
  [487] = 1,
    ACTIONS(82), 5,
      sym__eof,
      sym_marker_task_pending,
      sym_marker_task_done,
      sym_marker_property_info,
      sym_marker_property_label,
  [495] = 3,
    STATE(38), 1,
      aux_sym__lines,
    STATE(54), 1,
      sym_code_block_content,
    ACTIONS(109), 2,
      sym__line,
      sym__newline,
  [506] = 3,
    STATE(38), 1,
      aux_sym__lines,
    STATE(55), 1,
      sym_code_block_content,
    ACTIONS(109), 2,
      sym__line,
      sym__newline,
  [517] = 3,
    STATE(38), 1,
      aux_sym__lines,
    STATE(53), 1,
      sym_code_block_content,
    ACTIONS(109), 2,
      sym__line,
      sym__newline,
  [528] = 3,
    STATE(38), 1,
      aux_sym__lines,
    STATE(57), 1,
      sym_code_block_content,
    ACTIONS(109), 2,
      sym__line,
      sym__newline,
  [539] = 3,
    ACTIONS(111), 1,
      sym__line,
    ACTIONS(113), 1,
      sym__newline,
    STATE(58), 1,
      sym_code_block_language,
  [549] = 3,
    ACTIONS(115), 1,
      sym__line,
    ACTIONS(117), 1,
      sym__newline,
    STATE(40), 1,
      aux_sym__lines,
  [559] = 3,
    ACTIONS(111), 1,
      sym__line,
    ACTIONS(119), 1,
      sym__newline,
    STATE(48), 1,
      sym_code_block_language,
  [569] = 2,
    STATE(40), 1,
      aux_sym__lines,
    ACTIONS(121), 2,
      sym__line,
      sym__newline,
  [577] = 2,
    ACTIONS(124), 1,
      sym__line,
    STATE(2), 1,
      sym_content,
  [584] = 2,
    ACTIONS(126), 1,
      sym__line,
    STATE(3), 1,
      sym_content,
  [591] = 1,
    ACTIONS(128), 1,
      anon_sym_BQUOTE_BQUOTE_BQUOTE,
  [595] = 1,
    ACTIONS(130), 1,
      sym__line,
  [599] = 1,
    ACTIONS(132), 1,
      ts_builtin_sym_end,
  [603] = 1,
    ACTIONS(134), 1,
      sym__newline,
  [607] = 1,
    ACTIONS(136), 1,
      sym__line,
  [611] = 1,
    ACTIONS(138), 1,
      sym__newline,
  [615] = 1,
    ACTIONS(140), 1,
      ts_builtin_sym_end,
  [619] = 1,
    ACTIONS(142), 1,
      anon_sym_BQUOTE_BQUOTE_BQUOTE,
  [623] = 1,
    ACTIONS(144), 1,
      anon_sym_BQUOTE_BQUOTE_BQUOTE,
  [627] = 1,
    ACTIONS(146), 1,
      sym__line,
  [631] = 1,
    ACTIONS(148), 1,
      sym__newline,
  [635] = 1,
    ACTIONS(150), 1,
      sym__newline,
  [639] = 1,
    ACTIONS(152), 1,
      sym__newline,
  [643] = 1,
    ACTIONS(154), 1,
      anon_sym_BQUOTE_BQUOTE_BQUOTE,
  [647] = 1,
    ACTIONS(156), 1,
      sym__newline,
  [651] = 1,
    ACTIONS(158), 1,
      sym__newline,
};

static const uint32_t ts_small_parse_table_map[] = {
  [SMALL_STATE(4)] = 0,
  [SMALL_STATE(5)] = 24,
  [SMALL_STATE(6)] = 48,
  [SMALL_STATE(7)] = 71,
  [SMALL_STATE(8)] = 94,
  [SMALL_STATE(9)] = 114,
  [SMALL_STATE(10)] = 138,
  [SMALL_STATE(11)] = 162,
  [SMALL_STATE(12)] = 186,
  [SMALL_STATE(13)] = 201,
  [SMALL_STATE(14)] = 226,
  [SMALL_STATE(15)] = 241,
  [SMALL_STATE(16)] = 266,
  [SMALL_STATE(17)] = 281,
  [SMALL_STATE(18)] = 300,
  [SMALL_STATE(19)] = 314,
  [SMALL_STATE(20)] = 334,
  [SMALL_STATE(21)] = 354,
  [SMALL_STATE(22)] = 368,
  [SMALL_STATE(23)] = 382,
  [SMALL_STATE(24)] = 397,
  [SMALL_STATE(25)] = 414,
  [SMALL_STATE(26)] = 423,
  [SMALL_STATE(27)] = 434,
  [SMALL_STATE(28)] = 445,
  [SMALL_STATE(29)] = 458,
  [SMALL_STATE(30)] = 469,
  [SMALL_STATE(31)] = 478,
  [SMALL_STATE(32)] = 487,
  [SMALL_STATE(33)] = 495,
  [SMALL_STATE(34)] = 506,
  [SMALL_STATE(35)] = 517,
  [SMALL_STATE(36)] = 528,
  [SMALL_STATE(37)] = 539,
  [SMALL_STATE(38)] = 549,
  [SMALL_STATE(39)] = 559,
  [SMALL_STATE(40)] = 569,
  [SMALL_STATE(41)] = 577,
  [SMALL_STATE(42)] = 584,
  [SMALL_STATE(43)] = 591,
  [SMALL_STATE(44)] = 595,
  [SMALL_STATE(45)] = 599,
  [SMALL_STATE(46)] = 603,
  [SMALL_STATE(47)] = 607,
  [SMALL_STATE(48)] = 611,
  [SMALL_STATE(49)] = 615,
  [SMALL_STATE(50)] = 619,
  [SMALL_STATE(51)] = 623,
  [SMALL_STATE(52)] = 627,
  [SMALL_STATE(53)] = 631,
  [SMALL_STATE(54)] = 635,
  [SMALL_STATE(55)] = 639,
  [SMALL_STATE(56)] = 643,
  [SMALL_STATE(57)] = 647,
  [SMALL_STATE(58)] = 651,
};

static const TSParseActionEntry ts_parse_actions[] = {
  [0] = {.entry = {.count = 0, .reusable = false}},
  [1] = {.entry = {.count = 1, .reusable = false}}, RECOVER(),
  [3] = {.entry = {.count = 1, .reusable = true}}, SHIFT(44),
  [5] = {.entry = {.count = 1, .reusable = true}}, SHIFT(52),
  [7] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_item, 2, 0, 0),
  [9] = {.entry = {.count = 1, .reusable = false}}, SHIFT(5),
  [11] = {.entry = {.count = 1, .reusable = false}}, SHIFT(37),
  [13] = {.entry = {.count = 1, .reusable = true}}, SHIFT(19),
  [15] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_item, 2, 0, 0),
  [17] = {.entry = {.count = 1, .reusable = false}}, SHIFT(6),
  [19] = {.entry = {.count = 1, .reusable = false}}, SHIFT(39),
  [21] = {.entry = {.count = 1, .reusable = true}}, SHIFT(20),
  [23] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym_body_repeat1, 2, 0, 0),
  [25] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_body_repeat1, 2, 0, 0), SHIFT_REPEAT(4),
  [28] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_body_repeat1, 2, 0, 0), SHIFT_REPEAT(37),
  [31] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_body_repeat1, 2, 0, 0),
  [33] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_body, 1, 0, 0),
  [35] = {.entry = {.count = 1, .reusable = false}}, SHIFT(4),
  [37] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_body, 1, 0, 0),
  [39] = {.entry = {.count = 1, .reusable = false}}, SHIFT(7),
  [41] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_body_repeat1, 2, 0, 0), SHIFT_REPEAT(7),
  [44] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_body_repeat1, 2, 0, 0), SHIFT_REPEAT(39),
  [47] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym__lines, 2, 0, 0),
  [49] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym__lines, 2, 0, 0), SHIFT_REPEAT(8),
  [52] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym__lines, 2, 0, 0),
  [54] = {.entry = {.count = 1, .reusable = true}}, SHIFT(31),
  [56] = {.entry = {.count = 1, .reusable = true}}, SHIFT(27),
  [58] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_children_repeat1, 2, 0, 0), SHIFT_REPEAT(44),
  [61] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_children_repeat1, 2, 0, 0), SHIFT_REPEAT(52),
  [64] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_children_repeat1, 2, 0, 0),
  [66] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_code_block, 5, 0, 0),
  [68] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_code_block, 5, 0, 0),
  [70] = {.entry = {.count = 1, .reusable = true}}, SHIFT(45),
  [72] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_code_block, 6, 0, 0),
  [74] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_code_block, 6, 0, 0),
  [76] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_document_repeat1, 2, 0, 0), SHIFT_REPEAT(44),
  [79] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_document_repeat1, 2, 0, 0), SHIFT_REPEAT(52),
  [82] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_document_repeat1, 2, 0, 0),
  [84] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_content, 1, 0, 0),
  [86] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_content, 1, 0, 0),
  [88] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym__lines, 2, 0, 0), SHIFT_REPEAT(17),
  [91] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_item, 3, 0, 0),
  [93] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_item, 3, 0, 0),
  [95] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_item, 4, 0, 0),
  [97] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_item, 4, 0, 0),
  [99] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_children, 3, 0, 0),
  [101] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_children, 3, 0, 0),
  [103] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym_document_repeat1, 1, 0, 0),
  [105] = {.entry = {.count = 1, .reusable = true}}, SHIFT(32),
  [107] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_document_repeat1, 1, 0, 0),
  [109] = {.entry = {.count = 1, .reusable = false}}, SHIFT(38),
  [111] = {.entry = {.count = 1, .reusable = false}}, SHIFT(46),
  [113] = {.entry = {.count = 1, .reusable = false}}, SHIFT(35),
  [115] = {.entry = {.count = 1, .reusable = false}}, SHIFT(40),
  [117] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_code_block_content, 1, 0, 0),
  [119] = {.entry = {.count = 1, .reusable = false}}, SHIFT(36),
  [121] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym__lines, 2, 0, 0), SHIFT_REPEAT(40),
  [124] = {.entry = {.count = 1, .reusable = true}}, SHIFT(16),
  [126] = {.entry = {.count = 1, .reusable = true}}, SHIFT(18),
  [128] = {.entry = {.count = 1, .reusable = true}}, SHIFT(21),
  [130] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_marker_task, 1, 0, 0),
  [132] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_document, 2, 0, 0),
  [134] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_code_block_language, 1, 0, 0),
  [136] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_marker, 1, 0, 0),
  [138] = {.entry = {.count = 1, .reusable = true}}, SHIFT(34),
  [140] = {.entry = {.count = 1, .reusable = true}},  ACCEPT_INPUT(),
  [142] = {.entry = {.count = 1, .reusable = true}}, SHIFT(12),
  [144] = {.entry = {.count = 1, .reusable = true}}, SHIFT(14),
  [146] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_marker_property, 1, 0, 0),
  [148] = {.entry = {.count = 1, .reusable = true}}, SHIFT(50),
  [150] = {.entry = {.count = 1, .reusable = true}}, SHIFT(51),
  [152] = {.entry = {.count = 1, .reusable = true}}, SHIFT(43),
  [154] = {.entry = {.count = 1, .reusable = true}}, SHIFT(22),
  [156] = {.entry = {.count = 1, .reusable = true}}, SHIFT(56),
  [158] = {.entry = {.count = 1, .reusable = true}}, SHIFT(33),
};

enum ts_external_scanner_symbol_identifiers {
  ts_external_token__indent = 0,
  ts_external_token__dedent = 1,
  ts_external_token__eof = 2,
};

static const TSSymbol ts_external_scanner_symbol_map[EXTERNAL_TOKEN_COUNT] = {
  [ts_external_token__indent] = sym__indent,
  [ts_external_token__dedent] = sym__dedent,
  [ts_external_token__eof] = sym__eof,
};

static const bool ts_external_scanner_states[5][EXTERNAL_TOKEN_COUNT] = {
  [1] = {
    [ts_external_token__indent] = true,
    [ts_external_token__dedent] = true,
    [ts_external_token__eof] = true,
  },
  [2] = {
    [ts_external_token__indent] = true,
    [ts_external_token__eof] = true,
  },
  [3] = {
    [ts_external_token__dedent] = true,
    [ts_external_token__eof] = true,
  },
  [4] = {
    [ts_external_token__eof] = true,
  },
};

#ifdef __cplusplus
extern "C" {
#endif
void *tree_sitter_note_external_scanner_create(void);
void tree_sitter_note_external_scanner_destroy(void *);
bool tree_sitter_note_external_scanner_scan(void *, TSLexer *, const bool *);
unsigned tree_sitter_note_external_scanner_serialize(void *, char *);
void tree_sitter_note_external_scanner_deserialize(void *, const char *, unsigned);

#ifdef TREE_SITTER_HIDE_SYMBOLS
#define TS_PUBLIC
#elif defined(_WIN32)
#define TS_PUBLIC __declspec(dllexport)
#else
#define TS_PUBLIC __attribute__((visibility("default")))
#endif

TS_PUBLIC const TSLanguage *tree_sitter_note(void) {
  static const TSLanguage language = {
    .version = LANGUAGE_VERSION,
    .symbol_count = SYMBOL_COUNT,
    .alias_count = ALIAS_COUNT,
    .token_count = TOKEN_COUNT,
    .external_token_count = EXTERNAL_TOKEN_COUNT,
    .state_count = STATE_COUNT,
    .large_state_count = LARGE_STATE_COUNT,
    .production_id_count = PRODUCTION_ID_COUNT,
    .field_count = FIELD_COUNT,
    .max_alias_sequence_length = MAX_ALIAS_SEQUENCE_LENGTH,
    .parse_table = &ts_parse_table[0][0],
    .small_parse_table = ts_small_parse_table,
    .small_parse_table_map = ts_small_parse_table_map,
    .parse_actions = ts_parse_actions,
    .symbol_names = ts_symbol_names,
    .symbol_metadata = ts_symbol_metadata,
    .public_symbol_map = ts_symbol_map,
    .alias_map = ts_non_terminal_alias_map,
    .alias_sequences = &ts_alias_sequences[0][0],
    .lex_modes = ts_lex_modes,
    .lex_fn = ts_lex,
    .external_scanner = {
      &ts_external_scanner_states[0][0],
      ts_external_scanner_symbol_map,
      tree_sitter_note_external_scanner_create,
      tree_sitter_note_external_scanner_destroy,
      tree_sitter_note_external_scanner_scan,
      tree_sitter_note_external_scanner_serialize,
      tree_sitter_note_external_scanner_deserialize,
    },
    .primary_state_ids = ts_primary_state_ids,
  };
  return &language;
}
#ifdef __cplusplus
}
#endif
