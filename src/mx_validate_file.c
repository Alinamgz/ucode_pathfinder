#include "pathfinder.h"

void mx_validate_file(int arc, char *file_path) {
    char err = 0;
    int file = -1;
    char buf[1];

    if (arc != 2) {
        mx_printerr(USAGE_ERR);
        exit(1);
    }
    file = open(file_path, O_RDONLY);
    err = file < 1 ? 'n' : err;
    if (err == 0) {
        read(file, buf, 1);
        err = *buf ? err : 'e';
    }
    close(file);
    if (err) {
        mx_printerr(FILE_ERR);
        mx_printerr(file_path);
        err == 'n' ? mx_printerr(NONEXISTENT) : mx_printerr(EMPTY);
        exit(1);
    }
}
