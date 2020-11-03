#include "pathfinder.h"

void mx_validation(int arc, char *file_path, t_validation *v){
//    char *file = NULL;
//    char **file_arr = NULL;
    mx_validate_file(arc, file_path);
    v->file_str = mx_file_to_str(file_path);
    v->file_strarr = mx_strsplit(v->file_str, '\n');

    mx_validate_lines(v);

    mx_validate_isl_amt(v);
//    mx_validate_bridges(v);
//'mx_del_strarr(&file_arr);
//    mx_validate_isl_amt(file_arr);
}
