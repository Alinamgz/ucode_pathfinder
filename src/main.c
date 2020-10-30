#include "pathfinder.h"

int main(int arc, char *arv[]) {
    t_validation *valid = (t_validation*)malloc(sizeof(t_validation));
    valid->i = 0;
    valid->j= 0;
    valid->dist_tot = 0;
    // valid->amt = 0;
    // valid->file_str = NULL;
    // valid->file_strarr = NULL;
    // valid->islands = NULL;
    // valid->buf_isl = NULL;
    // valid->buf_dist = NULL;
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

  mx_validation(arc, arv[1], valid);
  mx_printchar(DELIM);
    system("leaks -q pathfinder");
    return 0;
}
