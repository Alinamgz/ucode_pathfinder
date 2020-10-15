#include "pathfinder.h"

bool mx_file_validation(char *file_name) {
    int err = 0;
    int file = open(file_name, O_RDONLY);
    char *buf = NULL;

    if (file < 0) {
        err = 1;
    }
    else {
        read(file, &buf, BUF_SIZE);
        err = buf ? err : 2;
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

bool mx_fstline_val(char *file, char *file_name) {
    int i;

    for (i = 0; file[i] != '\0' && file[i] != DELIM; i++) {
        if (mx_isdigit(file[i]) == FALSE) {
            mx_printerr(FIRST_LINE_ERR);
            return FALSE;
        }
    }
        return TRUE;
}
