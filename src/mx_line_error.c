#include "pathfinder.h"

void mx_line_error(int line_num, char ***arr) {
  char *line = mx_itoa(line_num);

  mx_printerr(LINE_ERR);
  mx_printerr(line);
  mx_printerr(INVALID);
  mx_err_exit(&line, arr);
}
