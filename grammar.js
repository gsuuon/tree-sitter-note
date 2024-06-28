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
    [$.body_lines], // TODO clean these up so that all newline-based conflicts are in one scope, I think most (all?) of these are due to newline handling and 1 token lookahead
    [$.items_repeat],
    [$.item_item],
    // [$.body],
  ],

  extras: _ => [], // explicit everything

  rules: {
    document: $ => seq(
      optional(
        seq(
          $.start_of_line,
          $.body
        )
      ),
      optional($.items_repeat),
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

    item: $ => choice(
      $.item_item,
      $.item_scope,
      $.items_repeat
    ),

    item_item: $ => seq(
      $.marker,
      $.content,
      optional(
        seq(
          $.newline,
          choice(
            $.item_scope,
            $.body
          )
        )
      )
    ),

    item_scope: $ => seq(
      $.indent,
      $.item,
      optional($.items_repeat),
      choice(
        $.dedent,
        $.eof
      )
    ),

    // TODO this is almost always wrapped in an optional, should I change to repeat instead of repeat1?
    // That may make this be able to match nothing?
    items_repeat: $ => repeat1(
      seq(
        $.start_of_line,
        $.eqdent,
        $.item,
      )
    ),


    ////// Item body //////
    body: $ => repeat1(
      choice(
        $.body_lines,
        $.code_block
      )
    ),

    body_line: _ => /.+/,
    body_lines: $ => seq(
      $.body_line,
      prec.left(
        repeat(
          seq(
            $.newline,
            $.body_line
          )
        )
      ),
      $.newline
    ),

    code_block_language: $ => $.body_line,
    code_block_content: $ => prec.left($.body_lines),
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
