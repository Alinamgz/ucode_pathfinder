#include "pathfinder.h"

char ***mx_split_arr(char **file_arr) {
    char ***rslt = NULL;
    int size = 0;

    while(file_arr[size]){
        size++;
    }

    rslt = (char***)malloc(sizeof(char**) * (1 + size));
    rslt ? mx_printstr("\ngoed\n") : mx_printstr("\nniet\n");

    for (int i = 0; i <= size; i++) {
        if (i == size) {
            rslt[i] = 0;
        }
        else {
            rslt[i] = mx_strsplit(file_arr[i], ',');
        }
    }

mx_printchar(DELIM);
    mx_printint(size);
mx_printchar(DELIM);
    return rslt;
}
