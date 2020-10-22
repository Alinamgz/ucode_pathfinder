#include "pathfinder.h"

void mx_validate_lines(char **arr) {
    int j = 0;
    int isl_in_line = 0;
    char *isl = NULL;

    for (int i = 0; arr[i]; i++) {
        if (i > 0) {
            j = 0;
            j = mx_check_line_part(arr, i, j, '-', mx_isalpha);
            
            isl = mx_strndup(arr[i], (j - 1));
            isl_in_line = mx_count_substr(arr[i], isl);
            mx_strdel(&isl);
            if (isl_in_line != 1)
                mx_line_error((1 + i), &arr);

            j = mx_check_line_part(arr, i, j, ',', mx_isalpha);
        }
        j = mx_check_line_part(arr, i, j, 0, mx_isdigit);
    }
}
