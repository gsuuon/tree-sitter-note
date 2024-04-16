module.exports = grammar({
  name: 'note',

  externals: $ => [
    $._indent,
    $._dedent,
    $._eof
  ],

  rules: {
    document: $ => seq(
      repeat1(
        choice(
          $.item,
          $.section_marker
        )
      ),
      $._eof
    ),

    section_title: $ => $._line,

    section_marker: $ => seq(
      token(prec(1, repeat1('#'))),
      ' ',
      $.section_title
    ),

    marker_task_pending: _ => '- ',
    marker_task_done: _ => '. ',
    marker_task: $ => choice(
      $.marker_task_pending,
      $.marker_task_done,
    ),

    marker_property_info: _ => '* ',
    marker_property_label: _ => '[ ',

    marker_property: $ => choice(
      $.marker_property_info,
      $.marker_property_label
    ),

    marker: $ => choice(
      $.marker_task,
      $.marker_property
    ),

    content: $ => $._line,

    body: $ => prec.right(repeat1(
      prec.left(choice(
        $._lines,
        $.code_block
      ))
    )),

    item: $ => prec.right(
      seq(
        $.marker,
        $.content,
        optional($.body),
        optional($.children)
      ),
    ),

    children: $ => seq(
      $._indent,
      repeat1($.item),
      choice($._dedent, $._eof)
    ),

    _line: _ => /.+/,
    _lines: $ => repeat1(
      choice(
        $._line,
        $._newline
      )
    ),
    _newline: _ => /\n/,

    code_block_language: $ => $._line,
    code_block_content: $ => prec.left($._lines),
    code_block: $ => seq(
      token(prec(1, '```')),
      optional($.code_block_language),
      $._newline,
      $.code_block_content,
      $._newline,
      token(prec(1, '```')),
    )
  }
});
