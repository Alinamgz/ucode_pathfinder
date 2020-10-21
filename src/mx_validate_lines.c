#include "pathfinder.h"

void mx_validate_lines(char **arr) {
  char *line = NULL;
  char *island = NULL;
  int isl_in_line  = 0;
  int j;

  for (int i = 0; arr[i]; i++) {
    line = arr[i];

    for (j = 0; i > 0 && line[j] && line[j] != '-'; j++) {
      if (mx_isalpha(line[j]) == FALSE) {
        mx_line_err((1 + i), &arr);
      }
    }
    if (i > 0) {
      island = mx_strndup(line, j);
  mx_printchar(DELIM);
  mx_printstr(island);
  mx_printchar(DELIM);
      isl_in_line = mx_count_substr(line, island);
      mx_strdel(island);
      if (line[j++] != '-' || isl_in_line != 1) {
        mx_line_err((1 + i), &arr);
      }
    }
    for ( ; i > 0 && line[j] && line[j] != ','; j++) {
      if (mx_isalpha(line[j]) == FALSE) {
        mx_line_err((1 + i), &arr);
      }
    }
    if (i > 0) {
      if (line[j++] != ',') {
        mx_line_err((1 + i), &arr);
      }
    }
    for (; line[j]; j++) {
      if (mx_isdigit(line[j]) == FALSE) {
        mx_line_err((1 + i), &arr);
      }
    }
  }
}
