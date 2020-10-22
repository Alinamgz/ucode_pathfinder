#include "pathfinder.h"

int mx_check_line_part(char **arr, int i, int j, char delim, bool (*f)(int)) {
    char *line = arr[i];
    int rslt = j;

    for ( ; line[rslt] && line[rslt] != delim; rslt++) {
        if (f(line[rslt])  == FALSE || line[j] == '0') {
            mx_line_error((1 + i), &arr);
        }
    }
    if (delim && line[rslt] != delim) {
        mx_line_error((1 + i), &arr);
    }
    rslt++;
    return rslt;
}
