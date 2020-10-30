#include "pathfinder.h"

void mx_validate_lines(t_validation *v) {
    int isl_in_line = 0;
    char *isl = NULL;

    for (v->i = 0; v->file_strarr[v->i]; v->i++) {
        if (v->i > 0) {
            v->j = 0;
            v->j = mx_check_line_part(v, '-', mx_isalpha);

            isl = mx_strndup(v->file_strarr[v->i], (v->j - 1));
            isl_in_line = mx_count_substr(v->file_strarr[v->i], isl);
            mx_strdel(&isl);
            if (isl_in_line != 1)
                mx_line_error((1 + v->i), &(v->file_strarr));

            v->j = mx_check_line_part(v, ',', mx_isalpha);
        }
        v->j = mx_check_line_part(v, 0, mx_isdigit);
    }
}
