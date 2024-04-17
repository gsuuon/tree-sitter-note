module.exports = grammar({
  name: 'note',

  externals: $ => [
    $._indent,
    $._dedent,
    $._section_in,
    $._section_out,
    $._eof
  ],

  rules: {
    // document: $ => seq(
    //   $._section_in,
    //   $.section,
    // ),

    document: $ => seq(
      repeat1(
        choice(
          $.item,
          seq(
            $._section_in,
            $.section,
          )
        )
      ),
      $._eof
    ),

    section_header: _ => token(
      prec(2, seq(
        repeat1('#'),
        ' ',
        /.+/,
        /\n/
      ))
    ),

    section_children: $ => seq(
      $._section_in,
      repeat1($.section),
      choice(
        $._section_out,
        $._eof
      )
    ),

    section: $ => prec.right(1, seq(
      $.section_header,
      prec(2, repeat($.item)),
      prec(2, optional($.section_children))
    )),

    marker_task_pending: _ => token(prec(1, '- ')),
    marker_task_done: _ => token(prec(1, '. ')),

    marker_task: $ => choice(
      $.marker_task_pending,
      $.marker_task_done,
    ),

    marker_property_info: _ => token(prec(1, '* ')),
    marker_property_label: _ => token(prec(1, '[ ')),

    marker_property: $ => choice(
      $.marker_property_info,
      $.marker_property_label
    ),

    marker: $ => choice(
      $.marker_task,
      $.marker_property
    ),

    content: $ => $._line,

    body: $ => prec.left(repeat1(
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
