#include "pathfinder.h"

bool mx_file_validation(const char *file) {
    bool rslt = TRUE;

    if (file == NULL) {
        rslt = FALSE;
        mx_printerr(NONEXISTENT);
    }
    else if (mx_strlen(mx_strtrim(file)) <= 0) {
        rslt = FALSE;
        mx_printerr(FILE_ERR);
        mx_printerr(arv[1]);
        mx_printerr(EMPTY);
    } 

	return rslt;
}

bool mx_validation(char **arr) {
    bool rslt = 1;

    if(arr){
        write(1, "\nkeke\n",6);
//        write(1, arr[0], mx_strlen(arr[0]));
    }
    return rslt;
}
