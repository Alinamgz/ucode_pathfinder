#include "pathfinder.h"

static void line_error(int line_num) {
    char *line = mx_itoa(line_num);

    mx_printerr(LINE_ERR);
    mx_printerr(line);
    mx_printerr(INVALID);
    exit(1);
}

static void check_line_part(t_validation *v, char delim, bool (*f)(int)) {
    char *line = v->file_strarr[v->i];
    int rslt = v->j;

    for ( ; line[rslt] && line[rslt] != delim; rslt++) {
        if (f(line[rslt])  == FALSE) {
            line_error((1 + v->i));
        }
    }
    if (delim && line[rslt] != delim) {
        line_error((1 + v->i));
    }
    v->j = 1 + rslt;
}

void mx_validate_lines(t_validation *v) {
    int isl_in_line = 0;
    char *isl = NULL;

    for (v->i = 0; v->file_strarr[v->i]; v->i++) {
        if (v->i > 0) {
            v->j = 0;
            check_line_part(v, '-', mx_isalpha);

            isl = mx_strndup(v->file_strarr[v->i], (v->j - 1));
            isl_in_line = mx_count_substr(v->file_strarr[v->i], isl);
            mx_strdel(&isl);
            if (isl_in_line != 1)
                line_error((1 + v->i));

            check_line_part(v, ',', mx_isalpha);
        }
        check_line_part(v, 0, mx_isdigit);
    }
    v->lines = v->i;
}
