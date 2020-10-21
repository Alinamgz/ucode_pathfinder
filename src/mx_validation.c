#include "pathfinder.h"

void mx_validation(int arc, char *file_path){
    char *file = NULL;
    char **file_arr = NULL;

    mx_validate_file(arc, file_path);
    file = mx_file_to_str(file_path);
    file_arr = mx_strsplit(file, '\n');
    mx_strdel(&file);

    mx_validate_lines(file_arr);
//'mx_del_strarr(&file_arr);
//    mx_validate_isl_amt(file_arr);
}
