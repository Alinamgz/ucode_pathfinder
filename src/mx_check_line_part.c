#include "pathfinder.h"

// int mx_check_line_part(char **arr, int i, int j, char delim, bool (*f)(int)) {
//     char *line = arr[i];
//     int rslt = j;

//     for ( ; line[rslt] && line[rslt] != delim; rslt++) {
//         if (f(line[rslt])  == FALSE) {
//             mx_line_error((1 + i), &arr);
//         }
//     }
//     if (delim && line[rslt] != delim) {
//         mx_line_error((1 + i), &arr);
//     }
//     rslt++;
//     return rslt;
// }

int mx_check_line_part(t_validation *v, char delim, bool (*f)(int)) {
    char *line = v->file_strarr[v->i];
    int rslt = v->j;
// mx_printchar(DELIM);
// mx_printstr(line);
// mx_printchar('\t');
// mx_printint(v->j);
// mx_printchar('\t');
// mx_printint(v->i);
// mx_printchar(DELIM);
    for ( ; line[rslt] && line[rslt] != delim; rslt++) {

        if (f(line[rslt])  == FALSE) {
            mx_line_error((1 + v->i), &(v->file_strarr));
        }
    }
    if (delim && line[rslt] != delim) {
        mx_line_error((1 + v->i), &(v->file_strarr));
    }
    rslt++;
    return rslt;
}
