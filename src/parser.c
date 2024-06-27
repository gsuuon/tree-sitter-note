#include "tree_sitter/parser.h"

#if defined(__GNUC__) || defined(__clang__)
#pragma GCC diagnostic ignored "-Wmissing-field-initializers"
#endif

#define LANGUAGE_VERSION 14
#define STATE_COUNT 41
#define LARGE_STATE_COUNT 2
#define SYMBOL_COUNT 17
#define ALIAS_COUNT 0
#define TOKEN_COUNT 9
#define EXTERNAL_TOKEN_COUNT 4
#define FIELD_COUNT 0
#define MAX_ALIAS_SEQUENCE_LENGTH 5
#define PRODUCTION_ID_COUNT 1

enum ts_symbol_identifiers {
  sym_newline = 1,
  sym_content = 2,
  sym_marker_task_pending = 3,
  sym_marker_property_info = 4,
  sym_indent = 5,
  sym_dedent = 6,
  sym_eqdent = 7,
  sym_eof = 8,
  sym_document = 9,
  sym_items_root = 10,
  sym_item = 11,
  sym_item_top = 12,
  sym_item_scope = 13,
  aux_sym____item_repeat = 14,
  sym_marker = 15,
  aux_sym_items_root_repeat1 = 16,
};

static const char * const ts_symbol_names[] = {
  [ts_builtin_sym_end] = "end",
  [sym_newline] = "newline",
  [sym_content] = "content",
  [sym_marker_task_pending] = "marker_task_pending",
  [sym_marker_property_info] = "marker_property_info",
  [sym_indent] = "indent",
  [sym_dedent] = "dedent",
  [sym_eqdent] = "eqdent",
  [sym_eof] = "eof",
  [sym_document] = "document",
  [sym_items_root] = "items_root",
  [sym_item] = "item",
  [sym_item_top] = "item_top",
  [sym_item_scope] = "item_scope",
  [aux_sym____item_repeat] = "___item_repeat",
  [sym_marker] = "marker",
  [aux_sym_items_root_repeat1] = "items_root_repeat1",
};

static const TSSymbol ts_symbol_map[] = {
  [ts_builtin_sym_end] = ts_builtin_sym_end,
  [sym_newline] = sym_newline,
  [sym_content] = sym_content,
  [sym_marker_task_pending] = sym_marker_task_pending,
  [sym_marker_property_info] = sym_marker_property_info,
  [sym_indent] = sym_indent,
  [sym_dedent] = sym_dedent,
  [sym_eqdent] = sym_eqdent,
  [sym_eof] = sym_eof,
  [sym_document] = sym_document,
  [sym_items_root] = sym_items_root,
  [sym_item] = sym_item,
  [sym_item_top] = sym_item_top,
  [sym_item_scope] = sym_item_scope,
  [aux_sym____item_repeat] = aux_sym____item_repeat,
  [sym_marker] = sym_marker,
  [aux_sym_items_root_repeat1] = aux_sym_items_root_repeat1,
};

static const TSSymbolMetadata ts_symbol_metadata[] = {
  [ts_builtin_sym_end] = {
    .visible = false,
    .named = true,
  },
  [sym_newline] = {
    .visible = true,
    .named = true,
  },
  [sym_content] = {
    .visible = true,
    .named = true,
  },
  [sym_marker_task_pending] = {
    .visible = true,
    .named = true,
  },
  [sym_marker_property_info] = {
    .visible = true,
    .named = true,
  },
  [sym_indent] = {
    .visible = true,
    .named = true,
  },
  [sym_dedent] = {
    .visible = true,
    .named = true,
  },
  [sym_eqdent] = {
    .visible = true,
    .named = true,
  },
  [sym_eof] = {
    .visible = true,
    .named = true,
  },
  [sym_document] = {
    .visible = true,
    .named = true,
  },
  [sym_items_root] = {
    .visible = true,
    .named = true,
  },
  [sym_item] = {
    .visible = true,
    .named = true,
  },
  [sym_item_top] = {
    .visible = true,
    .named = true,
  },
  [sym_item_scope] = {
    .visible = true,
    .named = true,
  },
  [aux_sym____item_repeat] = {
    .visible = false,
    .named = false,
  },
  [sym_marker] = {
    .visible = true,
    .named = true,
  },
  [aux_sym_items_root_repeat1] = {
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
  [3] = 3,
  [4] = 4,
  [5] = 3,
  [6] = 6,
  [7] = 7,
  [8] = 8,
  [9] = 9,
  [10] = 8,
  [11] = 11,
  [12] = 12,
  [13] = 13,
  [14] = 9,
  [15] = 15,
  [16] = 16,
  [17] = 11,
  [18] = 18,
  [19] = 19,
  [20] = 20,
  [21] = 21,
  [22] = 22,
  [23] = 23,
  [24] = 22,
  [25] = 25,
  [26] = 21,
  [27] = 23,
  [28] = 19,
  [29] = 29,
  [30] = 30,
  [31] = 31,
  [32] = 32,
  [33] = 33,
  [34] = 34,
  [35] = 35,
  [36] = 31,
  [37] = 37,
  [38] = 38,
  [39] = 39,
  [40] = 38,
};

static bool ts_lex(TSLexer *lexer, TSStateId state) {
  START_LEXER();
  eof = lexer->eof(lexer);
  switch (state) {
    case 0:
      if (eof) ADVANCE(5);
      if (lookahead == '\n') ADVANCE(6);
      if (lookahead != 0) ADVANCE(8);
      END_STATE();
    case 1:
      if (lookahead == '\n') ADVANCE(7);
      if (lookahead == '*') ADVANCE(2);
      if (lookahead == '-') ADVANCE(3);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') ADVANCE(4);
      END_STATE();
    case 2:
      if (lookahead == ' ') ADVANCE(10);
      END_STATE();
    case 3:
      if (lookahead == ' ') ADVANCE(9);
      END_STATE();
    case 4:
      if (lookahead == '*') ADVANCE(2);
      if (lookahead == '-') ADVANCE(3);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') ADVANCE(4);
      END_STATE();
    case 5:
      ACCEPT_TOKEN(ts_builtin_sym_end);
      END_STATE();
    case 6:
      ACCEPT_TOKEN(sym_newline);
      END_STATE();
    case 7:
      ACCEPT_TOKEN(sym_newline);
      if (lookahead == '*') ADVANCE(2);
      if (lookahead == '-') ADVANCE(3);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') ADVANCE(4);
      END_STATE();
    case 8:
      ACCEPT_TOKEN(sym_content);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(8);
      END_STATE();
    case 9:
      ACCEPT_TOKEN(sym_marker_task_pending);
      END_STATE();
    case 10:
      ACCEPT_TOKEN(sym_marker_property_info);
      END_STATE();
    default:
      return false;
  }
}

static const TSLexMode ts_lex_modes[STATE_COUNT] = {
  [0] = {.lex_state = 0, .external_lex_state = 1},
  [1] = {.lex_state = 0, .external_lex_state = 2},
  [2] = {.lex_state = 1},
  [3] = {.lex_state = 1},
  [4] = {.lex_state = 1},
  [5] = {.lex_state = 1},
  [6] = {.lex_state = 1},
  [7] = {.lex_state = 1},
  [8] = {.lex_state = 0, .external_lex_state = 3},
  [9] = {.lex_state = 0, .external_lex_state = 3},
  [10] = {.lex_state = 0, .external_lex_state = 3},
  [11] = {.lex_state = 0, .external_lex_state = 3},
  [12] = {.lex_state = 0, .external_lex_state = 4},
  [13] = {.lex_state = 0, .external_lex_state = 3},
  [14] = {.lex_state = 0, .external_lex_state = 3},
  [15] = {.lex_state = 0, .external_lex_state = 4},
  [16] = {.lex_state = 0, .external_lex_state = 4},
  [17] = {.lex_state = 0, .external_lex_state = 4},
  [18] = {.lex_state = 0, .external_lex_state = 3},
  [19] = {.lex_state = 0, .external_lex_state = 3},
  [20] = {.lex_state = 0, .external_lex_state = 4},
  [21] = {.lex_state = 0, .external_lex_state = 4},
  [22] = {.lex_state = 0, .external_lex_state = 4},
  [23] = {.lex_state = 0, .external_lex_state = 3},
  [24] = {.lex_state = 0, .external_lex_state = 3},
  [25] = {.lex_state = 0, .external_lex_state = 4},
  [26] = {.lex_state = 0, .external_lex_state = 3},
  [27] = {.lex_state = 0, .external_lex_state = 4},
  [28] = {.lex_state = 0, .external_lex_state = 4},
  [29] = {.lex_state = 0, .external_lex_state = 5},
  [30] = {.lex_state = 0, .external_lex_state = 2},
  [31] = {.lex_state = 0},
  [32] = {.lex_state = 0},
  [33] = {.lex_state = 0},
  [34] = {.lex_state = 0, .external_lex_state = 5},
  [35] = {.lex_state = 0, .external_lex_state = 2},
  [36] = {.lex_state = 0},
  [37] = {.lex_state = 0},
  [38] = {.lex_state = 0, .external_lex_state = 6},
  [39] = {.lex_state = 0},
  [40] = {.lex_state = 0, .external_lex_state = 6},
};

static const uint16_t ts_parse_table[LARGE_STATE_COUNT][SYMBOL_COUNT] = {
  [0] = {
    [ts_builtin_sym_end] = ACTIONS(1),
    [sym_newline] = ACTIONS(1),
    [sym_content] = ACTIONS(1),
    [sym_indent] = ACTIONS(1),
    [sym_dedent] = ACTIONS(1),
    [sym_eqdent] = ACTIONS(1),
    [sym_eof] = ACTIONS(1),
  },
  [1] = {
    [sym_document] = STATE(32),
    [sym_items_root] = STATE(29),
    [sym_eqdent] = ACTIONS(3),
  },
};

static const uint16_t ts_small_parse_table[] = {
  [0] = 5,
    ACTIONS(5), 1,
      sym_newline,
    STATE(12), 1,
      sym_item,
    STATE(31), 1,
      sym_marker,
    ACTIONS(7), 2,
      sym_marker_task_pending,
      sym_marker_property_info,
    STATE(28), 2,
      sym_item_top,
      sym_item_scope,
  [18] = 5,
    ACTIONS(9), 1,
      sym_newline,
    STATE(10), 1,
      sym_item,
    STATE(36), 1,
      sym_marker,
    ACTIONS(7), 2,
      sym_marker_task_pending,
      sym_marker_property_info,
    STATE(19), 2,
      sym_item_top,
      sym_item_scope,
  [36] = 5,
    ACTIONS(9), 1,
      sym_newline,
    STATE(18), 1,
      sym_item,
    STATE(36), 1,
      sym_marker,
    ACTIONS(7), 2,
      sym_marker_task_pending,
      sym_marker_property_info,
    STATE(19), 2,
      sym_item_top,
      sym_item_scope,
  [54] = 5,
    ACTIONS(9), 1,
      sym_newline,
    STATE(8), 1,
      sym_item,
    STATE(36), 1,
      sym_marker,
    ACTIONS(7), 2,
      sym_marker_task_pending,
      sym_marker_property_info,
    STATE(19), 2,
      sym_item_top,
      sym_item_scope,
  [72] = 5,
    ACTIONS(5), 1,
      sym_newline,
    STATE(20), 1,
      sym_item,
    STATE(31), 1,
      sym_marker,
    ACTIONS(7), 2,
      sym_marker_task_pending,
      sym_marker_property_info,
    STATE(28), 2,
      sym_item_top,
      sym_item_scope,
  [90] = 5,
    ACTIONS(5), 1,
      sym_newline,
    STATE(25), 1,
      sym_item,
    STATE(31), 1,
      sym_marker,
    ACTIONS(7), 2,
      sym_marker_task_pending,
      sym_marker_property_info,
    STATE(28), 2,
      sym_item_top,
      sym_item_scope,
  [108] = 3,
    ACTIONS(11), 1,
      sym_newline,
    STATE(14), 1,
      aux_sym____item_repeat,
    ACTIONS(13), 2,
      sym_dedent,
      sym_eof,
  [119] = 3,
    ACTIONS(11), 1,
      sym_newline,
    STATE(13), 1,
      aux_sym____item_repeat,
    ACTIONS(15), 2,
      sym_dedent,
      sym_eof,
  [130] = 3,
    ACTIONS(11), 1,
      sym_newline,
    STATE(9), 1,
      aux_sym____item_repeat,
    ACTIONS(17), 2,
      sym_dedent,
      sym_eof,
  [141] = 3,
    ACTIONS(19), 1,
      sym_newline,
    STATE(26), 1,
      sym_item_scope,
    ACTIONS(22), 2,
      sym_dedent,
      sym_eof,
  [152] = 4,
    ACTIONS(24), 1,
      sym_newline,
    ACTIONS(27), 1,
      sym_eqdent,
    ACTIONS(29), 1,
      sym_eof,
    STATE(16), 1,
      aux_sym_items_root_repeat1,
  [165] = 3,
    ACTIONS(31), 1,
      sym_newline,
    STATE(13), 1,
      aux_sym____item_repeat,
    ACTIONS(34), 2,
      sym_dedent,
      sym_eof,
  [176] = 3,
    ACTIONS(11), 1,
      sym_newline,
    STATE(13), 1,
      aux_sym____item_repeat,
    ACTIONS(36), 2,
      sym_dedent,
      sym_eof,
  [187] = 4,
    ACTIONS(38), 1,
      sym_newline,
    ACTIONS(41), 1,
      sym_eqdent,
    ACTIONS(44), 1,
      sym_eof,
    STATE(15), 1,
      aux_sym_items_root_repeat1,
  [200] = 4,
    ACTIONS(27), 1,
      sym_eqdent,
    ACTIONS(46), 1,
      sym_newline,
    ACTIONS(49), 1,
      sym_eof,
    STATE(15), 1,
      aux_sym_items_root_repeat1,
  [213] = 3,
    ACTIONS(51), 1,
      sym_newline,
    STATE(21), 1,
      sym_item_scope,
    ACTIONS(22), 2,
      sym_eqdent,
      sym_eof,
  [224] = 1,
    ACTIONS(54), 3,
      sym_dedent,
      sym_eof,
      sym_newline,
  [230] = 1,
    ACTIONS(56), 3,
      sym_dedent,
      sym_eof,
      sym_newline,
  [236] = 1,
    ACTIONS(44), 3,
      sym_eqdent,
      sym_eof,
      sym_newline,
  [242] = 1,
    ACTIONS(58), 3,
      sym_eqdent,
      sym_eof,
      sym_newline,
  [248] = 1,
    ACTIONS(60), 3,
      sym_eqdent,
      sym_eof,
      sym_newline,
  [254] = 1,
    ACTIONS(62), 3,
      sym_dedent,
      sym_eof,
      sym_newline,
  [260] = 1,
    ACTIONS(60), 3,
      sym_dedent,
      sym_eof,
      sym_newline,
  [266] = 1,
    ACTIONS(64), 3,
      sym_eqdent,
      sym_eof,
      sym_newline,
  [272] = 1,
    ACTIONS(58), 3,
      sym_dedent,
      sym_eof,
      sym_newline,
  [278] = 1,
    ACTIONS(62), 3,
      sym_eqdent,
      sym_eof,
      sym_newline,
  [284] = 1,
    ACTIONS(56), 3,
      sym_eqdent,
      sym_eof,
      sym_newline,
  [290] = 2,
    ACTIONS(66), 1,
      sym_newline,
    ACTIONS(68), 1,
      sym_eof,
  [297] = 1,
    ACTIONS(70), 1,
      sym_eqdent,
  [301] = 1,
    ACTIONS(72), 1,
      sym_content,
  [305] = 1,
    ACTIONS(74), 1,
      ts_builtin_sym_end,
  [309] = 1,
    ACTIONS(76), 1,
      ts_builtin_sym_end,
  [313] = 1,
    ACTIONS(78), 1,
      sym_eof,
  [317] = 1,
    ACTIONS(80), 1,
      sym_eqdent,
  [321] = 1,
    ACTIONS(82), 1,
      sym_content,
  [325] = 1,
    ACTIONS(84), 1,
      sym_content,
  [329] = 1,
    ACTIONS(86), 1,
      sym_indent,
  [333] = 1,
    ACTIONS(88), 1,
      ts_builtin_sym_end,
  [337] = 1,
    ACTIONS(90), 1,
      sym_indent,
};

static const uint32_t ts_small_parse_table_map[] = {
  [SMALL_STATE(2)] = 0,
  [SMALL_STATE(3)] = 18,
  [SMALL_STATE(4)] = 36,
  [SMALL_STATE(5)] = 54,
  [SMALL_STATE(6)] = 72,
  [SMALL_STATE(7)] = 90,
  [SMALL_STATE(8)] = 108,
  [SMALL_STATE(9)] = 119,
  [SMALL_STATE(10)] = 130,
  [SMALL_STATE(11)] = 141,
  [SMALL_STATE(12)] = 152,
  [SMALL_STATE(13)] = 165,
  [SMALL_STATE(14)] = 176,
  [SMALL_STATE(15)] = 187,
  [SMALL_STATE(16)] = 200,
  [SMALL_STATE(17)] = 213,
  [SMALL_STATE(18)] = 224,
  [SMALL_STATE(19)] = 230,
  [SMALL_STATE(20)] = 236,
  [SMALL_STATE(21)] = 242,
  [SMALL_STATE(22)] = 248,
  [SMALL_STATE(23)] = 254,
  [SMALL_STATE(24)] = 260,
  [SMALL_STATE(25)] = 266,
  [SMALL_STATE(26)] = 272,
  [SMALL_STATE(27)] = 278,
  [SMALL_STATE(28)] = 284,
  [SMALL_STATE(29)] = 290,
  [SMALL_STATE(30)] = 297,
  [SMALL_STATE(31)] = 301,
  [SMALL_STATE(32)] = 305,
  [SMALL_STATE(33)] = 309,
  [SMALL_STATE(34)] = 313,
  [SMALL_STATE(35)] = 317,
  [SMALL_STATE(36)] = 321,
  [SMALL_STATE(37)] = 325,
  [SMALL_STATE(38)] = 329,
  [SMALL_STATE(39)] = 333,
  [SMALL_STATE(40)] = 337,
};

static const TSParseActionEntry ts_parse_actions[] = {
  [0] = {.entry = {.count = 0, .reusable = false}},
  [1] = {.entry = {.count = 1, .reusable = false}}, RECOVER(),
  [3] = {.entry = {.count = 1, .reusable = true}}, SHIFT(2),
  [5] = {.entry = {.count = 1, .reusable = false}}, SHIFT(38),
  [7] = {.entry = {.count = 1, .reusable = true}}, SHIFT(37),
  [9] = {.entry = {.count = 1, .reusable = false}}, SHIFT(40),
  [11] = {.entry = {.count = 1, .reusable = true}}, SHIFT(30),
  [13] = {.entry = {.count = 1, .reusable = true}}, SHIFT(22),
  [15] = {.entry = {.count = 1, .reusable = true}}, SHIFT(23),
  [17] = {.entry = {.count = 1, .reusable = true}}, SHIFT(24),
  [19] = {.entry = {.count = 2, .reusable = true}}, REDUCE(sym_item_top, 2, 0, 0), SHIFT(40),
  [22] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_item_top, 2, 0, 0),
  [24] = {.entry = {.count = 2, .reusable = true}}, REDUCE(sym_items_root, 2, 0, 0), SHIFT(35),
  [27] = {.entry = {.count = 1, .reusable = true}}, SHIFT(6),
  [29] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_items_root, 2, 0, 0),
  [31] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym____item_repeat, 2, 0, 0), SHIFT_REPEAT(30),
  [34] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym____item_repeat, 2, 0, 0),
  [36] = {.entry = {.count = 1, .reusable = true}}, SHIFT(27),
  [38] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_items_root_repeat1, 2, 0, 0), SHIFT_REPEAT(35),
  [41] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_items_root_repeat1, 2, 0, 0), SHIFT_REPEAT(6),
  [44] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_items_root_repeat1, 2, 0, 0),
  [46] = {.entry = {.count = 2, .reusable = true}}, REDUCE(sym_items_root, 3, 0, 0), SHIFT(35),
  [49] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_items_root, 3, 0, 0),
  [51] = {.entry = {.count = 2, .reusable = true}}, REDUCE(sym_item_top, 2, 0, 0), SHIFT(38),
  [54] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym____item_repeat, 3, 0, 0),
  [56] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_item, 1, 0, 0),
  [58] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_item_top, 3, 0, 0),
  [60] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_item_scope, 4, 0, 0),
  [62] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_item_scope, 5, 0, 0),
  [64] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_items_root_repeat1, 3, 0, 0),
  [66] = {.entry = {.count = 1, .reusable = true}}, SHIFT(34),
  [68] = {.entry = {.count = 1, .reusable = true}}, SHIFT(33),
  [70] = {.entry = {.count = 1, .reusable = true}}, SHIFT(4),
  [72] = {.entry = {.count = 1, .reusable = true}}, SHIFT(17),
  [74] = {.entry = {.count = 1, .reusable = true}},  ACCEPT_INPUT(),
  [76] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_document, 2, 0, 0),
  [78] = {.entry = {.count = 1, .reusable = true}}, SHIFT(39),
  [80] = {.entry = {.count = 1, .reusable = true}}, SHIFT(7),
  [82] = {.entry = {.count = 1, .reusable = true}}, SHIFT(11),
  [84] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_marker, 1, 0, 0),
  [86] = {.entry = {.count = 1, .reusable = true}}, SHIFT(5),
  [88] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_document, 3, 0, 0),
  [90] = {.entry = {.count = 1, .reusable = true}}, SHIFT(3),
};

enum ts_external_scanner_symbol_identifiers {
  ts_external_token_indent = 0,
  ts_external_token_dedent = 1,
  ts_external_token_eqdent = 2,
  ts_external_token_eof = 3,
};

static const TSSymbol ts_external_scanner_symbol_map[EXTERNAL_TOKEN_COUNT] = {
  [ts_external_token_indent] = sym_indent,
  [ts_external_token_dedent] = sym_dedent,
  [ts_external_token_eqdent] = sym_eqdent,
  [ts_external_token_eof] = sym_eof,
};

static const bool ts_external_scanner_states[7][EXTERNAL_TOKEN_COUNT] = {
  [1] = {
    [ts_external_token_indent] = true,
    [ts_external_token_dedent] = true,
    [ts_external_token_eqdent] = true,
    [ts_external_token_eof] = true,
  },
  [2] = {
    [ts_external_token_eqdent] = true,
  },
  [3] = {
    [ts_external_token_dedent] = true,
    [ts_external_token_eof] = true,
  },
  [4] = {
    [ts_external_token_eqdent] = true,
    [ts_external_token_eof] = true,
  },
  [5] = {
    [ts_external_token_eof] = true,
  },
  [6] = {
    [ts_external_token_indent] = true,
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
