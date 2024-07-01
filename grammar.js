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
    $.indent,
    $.dedent,
    $.eqdent,
    $.section_in,
    $.section_de,
    $.section_eq,
    $.bof,
    $.eof,
  ],

  // inline: $ => [$.section_section],
  // i want to inline to deduplicate a possibly empty string sequence

  conflicts: $ => [
    // TODO clean these up. I think most (all?) of these are due to newline handling and 1 token lookahead
    [$.body, $.item_item],
    [$.items, $.item_scope],
    [$.section_section],
    [$.sections],
    [$.item_scope],
    [$.item_item],
    [$.items],
    [$.body],
  ],

  extras: _ => [], // explicit everything

  rules: {
    document: $ => seq(
      $.section_bof,
      $.eof
    ),

    ////// Newlines //////
    start_of_line: $ => choice(
      $.newlines,
      $.eqdent // NOTE: eqdent can always be emitted at start of line since we can't mark_end after advancing - see notes in scanner
    ),

    newlines: _ => /\n+/,
    newline: _ => /\n/,


    ////// Items //////
    content: _ => /.+/,

    item_item: $ => seq(
      $.marker,
      $.content,
      optional(
        seq(
          $.start_of_line,
          $.body
        )
      ),
      optional(
        seq(
          $.item_scope,
        )
      ),
    ),

    item_indent: $ => seq($.indent, $.item_item),
    item_eqdent: $ => seq($.eqdent, $.item_item),

    item_scope: $ => prec.dynamic(2, seq(
      alias($.item_indent, $.item),
      optional(
        seq(
          $.newlines,
          $.items
        )
      ),
      optional($.dedent),
    )),

    items: $ => choice(
      prec.dynamic(2, alias($.item_eqdent, $.item)),
      seq($.items, $.items)
    ),


    ////// Item body //////

    // I want this to be the lowest precedence lex
    body_line: _ => /.+/,

    body: $ => choice(
      $.body_line,
      $.code_block,
      seq($.body, $.start_of_line, $.body)
    ),

    code_block_language: $ => $.body_line,
    code_block_content: $ => prec.left(repeat1($.body_line)),
    code_block_fence_start: $ => choice(
      token(prec(2, /```\n/)),
      seq(
        token(prec(2, /```/)),
        $.code_block_language,
        $.newline
      ),
    ),
    code_block_fence_end: $ => seq(
      $.newline,
      token(prec(2, /```/))
    ),

    code_block: $ => seq(
      $.code_block_fence_start,
      $.code_block_content,
      $.code_block_fence_end,
    ),

    ////// Item markers //////
    marker_task_pending: _ => marker('-'),
    marker_property_info: _ => marker('\\*'),
    marker: $ => choice(
      $.marker_task_pending,
      $.marker_property_info
    ),

    ////// Sections //////
    section_header: _ => lex(2, /#+\s.+/),

    section_section: $ => choice(
      // TODO how do I say one or more of these terms in a given order?
      // can be body and or items and or section scope, but at least one and in that order
      $.items,
      seq(
        $.items,
        $.newlines,
        $.section_scope
      ),
    ),

    section: $ => prec.dynamic(2, seq(
      $.section_header,
      $.newlines,
      $.section_section
    )),

    section_bof: $ => seq(
      $.bof,
      $.section_section
    ),

    section_scope: $ => prec.dynamic(2, seq(
      $.section_in,
      $.section,
      optional(seq($.newlines, $.sections)),
      choice(
        $.section_de,
        $.eof
      )
    )),

    sections: $ => choice(
      seq($.section_eq, $.section),
      seq($.sections, $.newlines, $.sections)
    ),
  }
});
