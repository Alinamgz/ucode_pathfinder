#include "pathfinder.h"

void mx_validation(int arc, char *file_name){
    char *file = NULL;
    char **file_arr = NULL;

    mx_validate_file(arc, file_name);
    file = mx_file_to_str(arv[1]);
    file_arr = mx_strsplit(file, '\n');
    mx_strdel(&file);

    mx_validate_lines(file_arr);
    mx_validate_isl_amt(file_arr);
}
