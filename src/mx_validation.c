#include "pathfinder.h"

// bool mx_file_validation(char *file, char *file_name) {
//     bool rslt = TRUE;
//     int err = 0;

//     if (file == NULL) {
//         err = 1;
//     }
//     else if (file[0] == '\0') {
//         err = 2;
//     }

//     if (err) {
//         rslt = FALSE;
//         mx_printerr(FILE_ERR);
//         mx_printerr(file_name);
//         err == 1 ? mx_printerr(NONEXISTENT) : mx_printerr(EMPTY);

//     }
// 	return rslt;
// }

bool mx_file_validation(char *file_name) {
    int err = 0;
    int file = open(file_name, O_RDONLY);
    char *buf = NULL;

    if (file < 0) {
        err = 1;
    }
    else {
        read(file, &buf, 32);
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

