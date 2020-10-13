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
    else if (mx_strlen(mx_strtrim(file)) <= 0) {
        mx_printerr(FILE_ERR);
        mx_printerr(arv[1]);
        mx_printerr(EMPTY);
        mx_strdel(&file);
        exit(1);
    } 
    
mx_printint(mx_strlen(file));

    file_arr = mx_strsplit(file, '\n');
    mx_strdel(&file);

    mx_validation(file_arr);

    system("leaks -q pathfinder");
    return 0;
}
