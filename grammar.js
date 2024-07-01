/// char should be regex escaped if necessary
function marker(char) {
  return RegExp(`\\s*${char} `)
}

function lex(precedence, pattern) {
  return token(prec(precedence, pattern))
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
    [$.body, $.section_section],
    [$.items, $.section_section],
    [$.sections],
    [$.item_item],
    [$.items],
    [$.body],
  ],

  extras: _ => [], // explicit everything

  rules: {
    document: $ => seq(
      $.section_bof
    ),


    ////// Newlines //////

    // This only exists because there is no BOF or regex anchoring
    start_of_line: $ => choice(
      $.newline,
      // $.bof,
    ),

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
          $.start_of_line,
          $.item_scope,
        )
      ),
    ),

    item_scope: $ => prec.right(seq(
      prec.dynamic(2, alias($.item_indent, $.item)),
      optional(
        seq(
          $.start_of_line,
          $.items
        )
      ),
      choice(
        $.dedent,
        seq(
          optional($.start_of_line),
          $.eof
        ),
      )
    )),

    item_indent: $ => prec.dynamic(2, seq($.indent, $.item_item)),
    item_eqdent: $ => prec.dynamic(2, seq($.eqdent, $.item_item)),

    items: $ => prec.dynamic(2, choice(
      alias($.item_eqdent, $.item),
      seq($.items, $.start_of_line, $.items)
    )),


    ////// Item body //////
    body: $ => prec.dynamic(1, choice(
      $.body_line,
      $.code_block,
      seq($.body, $.start_of_line, $.body)
    )),

    // I want this to be the lowest precedence lex
    body_line: _ => /.+/,

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
      seq(
        $.items,
        optional($.section_scope)
      ),
      seq(
        $.body,
        optional($.items),
        optional($.section_scope)
      ),
      $.items,
      $.body,
      $.section_scope,
    ),

    section: $ => prec.dynamic(2, seq(
      $.section_header,
      $.start_of_line,
      $.section_section
    )),

    section_bof: $ => seq(
      $.bof,
      $.section_section
    ),

    section_scope: $ => prec.dynamic(2, seq(
      $.section_in,
      $.section,
      optional($.sections),
      choice(
        $.section_de,
        $.eof
      )
    )),

    sections: $ => choice(
      seq($.section_eq, $.section),
      seq($.sections, $.start_of_line, $.sections)
    ),
  }
});
