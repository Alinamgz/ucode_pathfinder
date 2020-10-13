#include "pathfinder.h"

bool mx_file_validation(char *file, char *file_name) {
    bool rslt = TRUE;
    char *trimmed = NULL;
    int err = 0;

    if (file == NULL) {
        err = 1;
        /*rslt = FALSE;
        mx_printerr(FILE_ERR);
        mx_printerr(file_name);
        mx_printerr(NONEXISTENT); */
    }
    else if (mx_strlen(trimmed = mx_strtrim(file)) <= 0) {
        mx_strdel(&trimmed);
        err = 2;
        /*rslt = FALSE;
        mx_printerr(FILE_ERR);
        mx_printerr(file_name);
        mx_printerr(EMPTY); */
    }

    if (err) {
        rslt = FALSE;
        mx_printerr(FILE_ERR);
        mx_printerr(file_name);
        err == 1 ? mx_printerr(NONEXISTENT) : mx_printerr(EMPTY);

    }
	return rslt;
}

