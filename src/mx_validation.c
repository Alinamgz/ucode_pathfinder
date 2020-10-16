#include "pathfinder.h"

bool mx_file_validation(char *file_name) {
    int err = 0;
    int file = open(file_name, O_RDONLY);
    char buf[1];

    if (file < 0) {
        err = 1;
    }
    else {
        read(file, buf, 1);
        err =  *buf ? err : 2;
    }
    close(file);

    if (err) {
        mx_printerr(FILE_ERR);
        mx_printerr(file_name);
        err == 1 ? mx_printerr(NONEXISTENT) : mx_printerr(EMPTY);
        return FALSE;
    }
    return TRUE;
}

bool mx_fstline_val(char *file) {
    int i;
    bool rslt = FALSE;

    for (i = 0; file[i] != '\0' && file[i] != '\n'; i++) {
        rslt = mx_isdigit(file[i]) ? TRUE : FALSE;
        if (rslt == FALSE) {
            break;
        }
    }
    if (rslt == FALSE) {
        mx_printerr(FIRST_LINE_ERR);
    }
    return rslt;

}
