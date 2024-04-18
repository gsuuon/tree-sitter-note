module.exports = grammar({
  name: 'note',

  externals: $ => [
    $._indent,
    $._dedent,
    $._section_in,
    $._section_out,
    $._section_sibling,
    $._eof
  ],

  rules: {
    document: $ => seq(
      repeat($.item),
      repeat(
        prec(2, seq(
          optional($._section_in),
          $.section,
        ))
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

    section_children: $ => prec.right(seq(
      $._section_in,
      repeat1($.section),
    )),

    section: $ => prec.right(3, seq(
      $.section_header,
      optional($.body),
      repeat($.item),
      optional($.section_children),

      choice(
        $._section_out,
        $._section_sibling,
        $._eof
      )
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

    body: $ => seq(
      choice(
        $._line,
        $.code_block
      ),
      repeat(
        prec.left(
          choice(
            $.code_block,
            $._lines
          )
        )
      )
    ),

    item: $ => prec.right(
      seq(
        $.marker,
        $.content,
        optional($.body),
        optional($.children)
      ),
    ),

    children: $ => prec.left(seq(
      $._indent,
      repeat1($.item),
      optional(choice($._dedent, $._eof))
    )),

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
