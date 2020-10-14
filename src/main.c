#include "pathfinder.h"

// int main(int arc, char *arv[]) {
//     char *file = NULL;
//     char **file_arr = NULL;
//     bool is_valid = FALSE;

//     if (arc != 2) {
//         mx_printerr(USAGE_ERR);
//         exit(1);
//     }

//     file = mx_file_to_str(arv[1]);
//     is_valid = mx_file_validation(file, arv[1]);

//     if (is_valid == FALSE) {
//         mx_err_exit(&file, &file_arr);
//     }

// //    file_arr = mx_strsplit(file, '\n');
//  //   mx_strdel(&file);
//     system("leaks -q pathfinder");
//     return 0;
// }

int main(int arc, char *arv[]) {
    char *file = NULL;
    char **file_arr = NULL;
    bool is_valid = FALSE;

    if (arc != 2) {
        mx_printerr(USAGE_ERR);
        exit(1);
    }

    is_valid = mx_file_validation(arv[1]);

    if (is_valid == FALSE) {
        mx_err_exit(&file, &file_arr);
    }
    file = mx_file_to_str(arv[1]);
    file_arr = mx_strsplit(file, '\n');

 //   mx_strdel(&file);
    system("leaks -q pathfinder");
    return 0;
}
