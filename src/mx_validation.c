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

bool mx_lines_val(char **arr) {
    bool rslt = FALSE;
    char *line = NULL;
    int j;

    for (int i = 1; arr[i]; i++) {
        line = arr[i];
        for (j = 0; line[j] && line[j] != '-'; j++) {
            rslt = mx_isalpha(line[j]) ? TRUE : FALSE;
            if (rslt == FALSE) {
                mx_printerr(LINE_ERR);
                mx_printerr(mx_itoa(1 + i));
                mx_printerr(INVALID);
                mx_err_exit(NULL, &arr);
                exit(1);
            }
        }
        rslt = line[j] == '-' ? TRUE : FALSE;
        j++;
        if (rslt == FALSE) {
                mx_printerr(LINE_ERR);
                mx_printerr(mx_itoa(1 + i));
                mx_printerr(INVALID);
                mx_err_exit(NULL, &arr);
                exit(1);
        }
        for ( ; line[j] && line[j] != ','; j++){
            rslt = mx_isalpha(line[j]);
            if (rslt == FALSE) {
                mx_printerr(LINE_ERR);
                mx_printerr(mx_itoa(1 + i));
                mx_printerr(INVALID);
                mx_err_exit(NULL, &arr);
                exit(1);
            }
        rslt = line[j] == ',' ? TRUE : FALSE;
        j++;
        if (rslt == FALSE) {
                mx_printerr(LINE_ERR);
                mx_printerr(mx_itoa(1 + i));
                mx_printerr(mx_itoa(j));
                mx_printerr(line);
                mx_printerr(INVALID);
                mx_err_exit(NULL, &arr);
                exit(1);
            }
        for ( ; line[j] && line[j] != '\n'; j++) {
            rslt = mx_isdigit(line[j]);
            if(rslt == FALSE) {
                mx_printerr(LINE_ERR);
                mx_printerr(mx_itoa(1 + i));
                mx_printerr(INVALID);
                mx_err_exit(NULL, &arr);
                exit(1);
            }
        }
        }
    }

    return rslt;
}
