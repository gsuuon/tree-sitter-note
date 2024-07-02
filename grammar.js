function lex(precedence, pattern) {
  return token(prec(precedence, pattern))
}

/// char should be regex escaped if necessary
function marker(char) {
  return lex(2, RegExp(`\\s*${char} `))
}

module.exports = grammar({
  name: 'note',

  externals: $ => [
    // NOTE dedent starts before the ending newline of an item, while eqdent/indent start after the newline
    // this is because dedent is 0-width, skipping the newline and can be immediately followed by another eqdent so that
    // all same-level items begin with an eqdent (including after a dedent)
    $._indent,
    $._dedent,
    $._eqdent,
    $._section_in,
    $._section_de,
    $._section_eq,
    $._section_header_closing_scope,
    $._bof,
    $._eof,
  ],

  conflicts: $ => [
    [$._body, $._item_item],
    [$._body, $._section_section],

    [$.section],
    [$._section_section],
    [$._sections],

    [$._item_item],
    [$._items],

    [$._body_segment],
    [$._body],
  ],

  // explicit whitespace/newlines
  extras: _ => [],

  rules: {
    document: $ => seq(
      $._section_bof,
      $._eof
    ),

    _newlines: $ => prec.right(choice(
      $._newline,
      seq($._newlines, $._newlines)
    )),

    _newline: _ => /\n/,


    ////// item //////
    _item_item: $ => seq(
      $._marker,
      alias($._body_line, $.content),
      optional(
        seq(
          $._newlines,
          alias($._body, $.body)
        )
      ),
      optional($._item_scope),
    ),

    item_indent: $ => prec.dynamic(2, seq($._indent, $._item_item)),
    item_eqdent: $ => prec.dynamic(2, seq($._eqdent, $._item_item)),

    _item_scope: $ => prec.dynamic(2, seq(
      alias($.item_indent, $.item),
      optional($._items),
      choice(
        // NOTE currently section_header_closing_scope and dedent tokens take a newline
        // this differs from the convention for most terms to not contain boundary newlines
        // that means _item_item takes a trailing newline as well (as well as item, items, so on)
        // TODO maybe these shouldn't take any newlines since they're used as delimiters
        // currently it works because they take, but don't require, newlines
        $._section_header_closing_scope,
        $._dedent,
        $._eof,
      ),
    )),

    _items: $ => choice(
      alias($.item_eqdent, $.item),
      seq($._items, $._items)
    ),


    ////// body //////
    _body_segment: $ => prec.dynamic(0, choice(
      /[ ]+/,
      alias(/\s\[\S+\]\s/, $.link),
      alias(' -> ', $.decorate_flow),
      seq($._body_segment, $._body_segment),

      // TODO this may have broken link/decorate but is necessary for bodies that start with spaces
      // and maybe which contain spaces at all that aren't link or decorate?
      // i just want this to be lowest prio
      /[^ \n]+/
    )),

    decorate_select: _ => ' <-',

    _body_line: $ => choice(
      $._body_segment,
      seq($._body_segment, $.decorate_select)
    ),

    // TODO clean this and the alias($._body, $.body) members
    // This is unnamed and then aliased so we can get the combined term seq without extra nodes
    // i could also wrap this but that creates a conflict with the wrapping term
    _body: $ => choice(
      $._body_line,
      $.code_block,
      seq($._body, $._newlines, $._body)
    ),


    ////// code block //////
    _code_block_lines: $ => prec.left(choice(
      /.+/,
      seq($._code_block_lines, $._newlines, $._code_block_lines)
    )),

    _code_block_fence_start: $ => prec.right(choice(
      lex(2, /```/),
      seq(
        lex(2, /```/),
        $.code_block_language
      ),
    )),
    _code_block_fence_end: _ => lex(2, /```/),
    code_block_language: _ => /.+/,
    code_block: $ => seq(
      $._code_block_fence_start,
      choice(
        seq(
          $._newline,
          alias($._code_block_lines, $.code_block_content),
          $._newline,
        ),
        $._newlines
      ),
      $._code_block_fence_end,
    ),


    ////// marker //////
    marker_task_pending: _ => marker('\\-'),
    marker_task_cancelled: _ => marker(','),
    marker_task_paused: _ => marker('='),
    marker_task_done: _ => marker('\\.'),
    marker_task_current: _ => marker('>'),

    marker_property_info: _ => marker('\\*'),
    marker_property_label: _ => marker('\\['),

    _marker: $ => choice(
      $.marker_task_pending,
      $.marker_task_cancelled,
      $.marker_task_paused,
      $.marker_task_done,
      $.marker_task_current,

      $.marker_property_info,
      $.marker_property_label
    ),


    ////// section //////
    section_header: _ => lex(2, /#+\s.+/),

    _section_section: $ => choice(
      // TODO is there a better way to say one or more of these terms in a given order?
      // can be body and or items and or section scope, but at least one and in that order


      // one of any
      alias($._body, $.body),
      $._items,
      $._section_scope,

      // sequences
      seq(
        alias($._body, $.body),
        $._newlines,
        $._items
      ),
      seq(
        alias($._body, $.body),
        $._newlines,
        $._section_scope
      ),
      seq(
        $._items,
        $._newlines,
        $._section_scope
      ),
      seq(
        alias($._body, $.body),
        $._newlines,
        $._items,
        $._newlines,
        $._section_scope
      ),
    ),

    section: $ => prec.dynamic(2, seq(
      $.section_header,
      optional(
        seq(
          $._newlines,
          choice(
            $._section_section,
            $._eof
          )
        )
      )
    )),

    _section_bof: $ => seq(
      $._bof,
      optional($._newlines),
      $._section_section
    ),

    _section_scope: $ => prec.dynamic(2, seq(
      $._section_in,
      $.section,
      optional(seq($._newlines, $._sections)),
      choice(
        $._section_de,
        $._eof
      )
    )),

    _sections: $ => choice(
      seq($._section_eq, $.section),
      seq($._sections, $._newlines, $._sections)
    ),
  }
});
