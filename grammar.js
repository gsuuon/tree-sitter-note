function marker(char) {
  return RegExp(`\\s*${char} `)
}

module.exports = grammar({
  name: 'note',

  externals: $ => [
    $.indent,
    $.dedent,
    $.eqdent,
    $.bof,
    $.eof,
  ],

  conflicts: $ => [
    // TODO clean these up so that all newline-based conflicts are in one scope, I think most (all?) of these are due to newline handling and 1 token lookahead
    [$.item_item, $.body],
    [$.item_item],
    [$.items],
    [$.body],
  ],

  extras: _ => [], // explicit everything

  rules: {
    document: $ => seq(
      $.start_of_line,
      optional($.body),
      optional($.items),
      optional($.newline),
      $.eof
    ),


    ////// Newlines //////

    // This only exists because there is no BOF or regex anchoring
    start_of_line: $ => choice(
      $.newline,
      $.bof,
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
          choice(
            $.item_scope,
            $.body
          )
        )
      )
    ),

    item_scope: $ => seq(
      seq($.start_of_line, alias($.item_indent, $.item)),
      optional($.items),
      choice(
        $.dedent,
        $.eof
      )
    ),

    item_indent: $ => seq($.indent, $.item_item),
    item_eqdent: $ => seq($.eqdent, $.item_item),

    items: $ => prec.dynamic(2, choice(
      alias($.item_eqdent, $.item),
      seq($.items, $.start_of_line, $.items)
    )),


    ////// Item body //////
    body: $ => prec.dynamic(1, choice(
      $.body_line,
      // seq($.start_of_line, $.code_block),
      seq($.body, $.start_of_line, $.body)
    )),

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
    code_block: $ => seq(
      $.code_block_fence_start,
      $.code_block_content,
      token(prec(2, /```\n/)),
    ),


    ////// Item markers //////
    marker_task_pending: _ => marker('-'),
    marker_property_info: _ => marker('\\*'),
    marker: $ => choice(
      $.marker_task_pending,
      $.marker_property_info
    ),
  }
});
