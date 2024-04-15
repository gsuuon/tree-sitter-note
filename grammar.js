module.exports = grammar({
  name: 'note',

  externals: $ => {
    $.indent,
    $.dedent,
    $.newline
  },

  rules: {
    document: $ => repeat1($.item),
    item: _ => /.+/,
    marker_task: _ => '- ',
    marker_property: _ => '* ',
  }
});
