#include "pathfinder.h"

void mx_err_exit(char **file, char ***file_arr) {
    if (file) {
        mx_strdel(file);
    }
    
    if (file_arr && *file_arr) {
        mx_del_strarr(file_arr);
    }
system("leaks -q pathfinder");
    exit(1);
}
