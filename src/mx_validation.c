#include "pathfinder.h"

void mx_file_validation(char *file_name) {
    int err = 0;
    int file = open(file_name, O_RDONLY);
    char buf[1];

    if (file < 0) {
        err = 1;
    }
    else {
        read(file, buf, 1);
        err = *buf ? err : 2;
    }
    close(file);

    if (err) {
        mx_printerr(FILE_ERR);
        mx_printerr(file_name);
        err == 1 ? mx_printerr(NONEXISTENT) : mx_printerr(EMPTY);
        mx_err_exit(NULL, NULL);
    }
}

void mx_line_err(int line_num, char ***arr) {
    char *line = mx_itoa(line_num);

    mx_printerr(LINE_ERR);
    mx_printerr(line);
    mx_printerr(INVALID);
    mx_err_exit(&line, arr);
}

void mx_lines_val(char **arr) {
    char *line = NULL;
    int j;

    for (int i = 0; arr[i]; i++) {
        line = arr[i];

        for (j = 0; i > 0 && line[j] && line[j] != '-'; j++) {
            if (mx_isalpha(line[j]) == FALSE) {
                mx_line_err((1 + i), &arr);
            }
        }
        if (i > 0) {
            if (line[j++] != '-') {
                mx_line_err((1 + i), &arr);
            }
        }
        for (; i > 0 && line[j] && line[j] != ','; j++) {
            if (mx_isalpha(line[j]) == FALSE) {
                mx_line_err((1 + i), &arr);
            }
        }
        if (i > 0){
            if ( line[j++] != ',') {
                mx_line_err((1 + i), &arr);
            }
        }
        for (; line[j] && line[j] != '\n'; j++) {
            if (mx_isdigit(line[j]) == FALSE) {
                mx_line_err((1 + i), &arr);
            }
        }
    }
}
