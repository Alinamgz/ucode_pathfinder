#include "pathfinder.h"

static void check_line_part(t_validation *v, char delim, bool (*f)(int)) {
    char *line = v->file_strarr[v->i];
    int rslt = v->j;

    for (; line[rslt] && line[rslt] != delim; rslt++) {
        if (f(line[rslt]) == FALSE) {
            mx_line_error((1 + v->i));
        }
    }
    if (delim && line[rslt] != delim) {
        mx_line_error((1 + v->i));
    }
    v->j = 1 + rslt;
}

void mx_validate_lines(t_validation *v) {
    for (v->i = 0; v->file_strarr[v->i]; v->i++) {
        if (v->i > 0) {
            v->j = 0;
            check_line_part(v, '-', mx_isalpha);
            check_line_part(v, ',', mx_isalpha);
        }
        check_line_part(v, 0, mx_isdigit);
    }
    v->lines = v->i;
}
