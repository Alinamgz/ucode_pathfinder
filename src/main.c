#include "pathfinder.h"

int main(int arc, char *arv[]) {
    char *file = NULL;
    char **file_arr = NULL;
//    char ***fin_arr = NULL;

    // if (arc != 2) {
    //     mx_printerr(USAGE_ERR);
    //     exit(1);
    // }
    mx_file_validation(arc, arv[1]);
    
    file = mx_file_to_str(arv[1]);
    file_arr = mx_strsplit(file, '\n');

    mx_strdel(&file);

    mx_lines_val(file_arr);

    // fin_arr = mx_split_arr(file_arr);
    // if(fin_arr) {
    //     for(int i = 0; fin_arr[i]; i++){
    //         mx_printstr("\n----------\n");
    //         mx_print_strarr(fin_arr[i], "\n");
    //         mx_printstr("----------\n");
    //     }
    // }
    // else {
    //     mx_printstr("\nblinn");
    // }
 //   mx_strdel(&file);
 mx_printchar(DELIM);
    system("leaks -q pathfinder");
    return 0;
}
