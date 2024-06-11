module.exports = grammar({
  name: 'note',

  externals: $ => [
    $._indent,
    $._dedent,
    $._eqdent,
    $._section_in,
    $._section_out,
    $._section_sibling,
    $._eof
  ],

  extras: _ => [' '], // explicit newlines

  rules: {
    document: $ => seq(
      optional($._body),
      repeat($._item),
      repeat(
        prec(2, seq(
          optional($._section_in),
          $.section,
        ))
      ),
      $._eof
    ),

    _body: $ => seq(
      optional($._blanklines),
      $.body
    ),

    _item: $ => seq(
      optional($._blanklines),
      $.item
    ),

    section_header: $ => seq(
      optional(
        $._section_sibling,
      ),
      token(
        prec(2, seq(
          repeat1('#'),
          ' ',
          /.+/,
          /\n/
        ))
      )
    ),

    section_children: $ => seq(
      $._section_in,
      prec.right(2, repeat1($.section)),
      choice(
        $._section_out,
        $._eof
      )
    ),

    section: $ => prec.right(3, seq(
      $.section_header,
      optional($.body),
      repeat($.item),
      optional($.section_children),
    )),

    marker_task_pending: _ => token.immediate(prec(1, '- ')),
    marker_task_done: _ => token.immediate(prec(1, '. ')),
    marker_task_paused: _ => token.immediate(prec(1, '= ')),
    marker_task_cancelled: _ => token.immediate(prec(1, ', ')),
    marker_task_current: _ => token.immediate(prec(1, '> ')),

    _marker_task: $ => choice(
      $.marker_task_pending,
      $.marker_task_done,
      $.marker_task_paused,
      $.marker_task_cancelled,
      $.marker_task_current
    ),

    marker_property_info: _ => token.immediate(prec(1, '* ')),
    marker_property_label: _ => token.immediate(prec(1, '[ ')),

    _marker_property: $ => choice(
      $.marker_property_info,
      $.marker_property_label
    ),

    _marker: $ => choice(
      $._marker_task,
      $._marker_property
    ),

    content: _ => token.immediate(/.+/),

    body: $ => prec.right(
      seq(
        choice($._line, $.code_block),
        repeat(
          prec.right(
            choice($.code_block, $._lines, $._blanklines)
          )
        )
      )
    ),

    item: $ => prec.right(
      seq(
        field('marker', $._marker),
        $.content,
        token.immediate(/\n/),
        optional($.body),
        optional($._children)
      ),
    ),

    _children: $ => prec.right(
      seq(
        $._indent,
        $.item,
        repeat(
          seq(
            $._eqdent,
            $.item,
          )
        ),
        optional(choice($._dedent, $._eof))
      )
    ),

    _line: _ => /.+/,
    _lines: $ => repeat1(
      choice(
        $._line,
        $._newline
      )
    ),
    _newline: _ => /\n/,
    _blanklines: _ => /\n+/,

    code_block_language: $ => $._line,
    code_block_content: $ => prec.left($._lines),
    code_block: $ => seq(
      choice(
        token(prec(1, '```\n')),
        seq(
          token(prec(1, '```')),
          $.code_block_language,
          '\n'
        )
      ),
      optional($.code_block_content),
      token(prec(1, '```\n')),
    )
  }
});
