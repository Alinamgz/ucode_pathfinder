#include "pathfinder.h"

int main(int arc, char *arv[]) {
/*
    char *file = NULL;
    char **file_arr = NULL;
    char ***fin_arr = NULL;
    mx_file_validation(arc, arv[1]);

    file = mx_file_to_str(arv[1]);
    file_arr = mx_strsplit(file, '\n');

    mx_strdel(&file);

    mx_lines_val(file_arr);
  */

  mx_validation(arc, arv[1]);
  mx_printchar(DELIM);
    system("leaks -q pathfinder");
    return 0;
}
