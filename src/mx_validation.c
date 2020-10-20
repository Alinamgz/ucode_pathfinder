#include "pathfinder.h"

bool mx_file_validation(char *file_name) {
    int err = 0;
    int file = open(file_name, O_RDONLY);
    char buf[1];

    if (file < 0) {
        err = 1;
    } else {
        read(file, buf, 1);
        err = *buf ? err : 2;
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

void mx_line_err(int line_num, char ***arr) {
    mx_printerr(LINE_ERR);
    mx_printerr(mx_itoa(line_num));
    mx_printerr(INVALID);
    mx_err_exit(NULL, arr);
    system("leacs -q pathfinder");
    exit(1);
}

bool mx_lines_val(char **arr) {
    bool rslt = FALSE;
    char *line = NULL;
    int j;

    for (int i = 1; arr[i]; i++) {
        line = arr[i];
        mx_printstr("\n==============\n");
        mx_printstr(line);
        mx_printchar(DELIM);

        for (j = 0; line[j] && line[j] != '-'; j++) {
            if (mx_isalpha(line[j]) == FALSE) {
                mx_line_err((1 + i), &arr);
            }
        }
        rslt = line[j++] == '-' ? TRUE : FALSE;
        if (rslt == FALSE) {
            mx_line_err((1 + i), &arr);
        }
        for (; line[j] && line[j] != ','; j++) {
            if (mx_isalpha(line[j]) == FALSE) {
                mx_line_err((1 + i), &arr);
            }
        }
        rslt = line[j++] == ',' ? TRUE : FALSE;
        if (rslt == FALSE) {
            mx_line_err((1 + i), &arr);
        }
        for (; line[j] && line[j] != '\n'; j++) {
            if (mx_isdigit(line[j]) == FALSE) {
                mx_line_err((1 + i), &arr);
            }
        }
    }

    return rslt;
}
