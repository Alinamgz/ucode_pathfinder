#include "pathfinder.h"

int main(int arc, char *arv[]) {
    char *file = NULL;
    char **file_arr = NULL;

    if (arc != 2) {
        mx_printerr(USAGE_ERR);
        exit(1);
    }

    file = mx_file_to_str(arv[1]);
    
    if (file == NULL) {
        mx_printerr(NONEXISTENT);
        exit(1);
    }
    
    file_arr = mx_strsplit(file, '\n');
    mx_strdel(&file);

    mx_validation(file_arr);

    system("leaks -q pathfinder");
    return 0;
}
