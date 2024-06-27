function marker(char) {
  return RegExp(`\\s*${char} `)
}

module.exports = grammar({
  name: 'note',

  externals: $ => [
    $.indent,
    $.dedent,
    $.eqdent,
    $.eof
  ],

  conflicts: $ => [
    [$.items_root],
    [$.item_top]
  ],

  extras: _ => [], // explicit everything

  rules: {
    document: $ => seq(
      $.items_root,
      optional($.newline), // TODO not sure why this is necessary when eof consumes and skips newlines
      $.eof
    ),

    items_root: $ => seq(
      // This only exists because there is no BOF or regex anchoring
      // ___item_repeat doesn't work due to required newline seps
      $.eqdent,
      $.item,
      repeat(
        seq(
          optional($.newline),
          // TODO dedent will take this newline, but otherwise needed before eqdent
          $.eqdent,
          $.item,
        )
      )
    ),

    newline: _ => '\n',

    content: _ => /.+/,

    item: $ => choice(
      $.item_top,
      $.item_scope,
      // $.___item_repeat
    ),

    item_top: $ => seq(
      $.marker,
      $.content,
      optional(
        $.item_scope
      )
    ),

    item_scope: $ => seq(
      $.newline,
      $.indent,
      $.item,
      optional($.___item_repeat),
      choice(
        $.dedent,
        $.eof
      )
    ),

    ___item_repeat: $ => repeat1(
      seq(
        $.newline, // or beginning of file
        $.eqdent,
        $.item,
      )
    ),

    marker_task_pending: _ => marker('-'),
    marker_property_info: _ => marker('\\*'),

    marker: $ => choice(
      $.marker_task_pending,
      $.marker_property_info
    ),

    body: _ => repeat1(
      /[^*]+/,
    )
  }
});
