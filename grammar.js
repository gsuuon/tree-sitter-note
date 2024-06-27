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
    [$.items_repeat],
    [$.item_item],
    [$.body],
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
      $.items_repeat,
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

    body_line: _ => /.+/,

    body: $ => seq(
      $.body_line,
      prec.left(
        repeat(
          seq(
            $.newline,
            $.body_line
          )
        )
      )
    ),

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

    items_repeat: $ => repeat1(
      seq(
        $.start_of_line,
        $.eqdent,
        $.item,
      )
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
