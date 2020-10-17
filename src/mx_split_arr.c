#include "pathfinder.h"

char ***mx_split_arr(char **file_arr) {
    char ***rslt = NULL;
    char del_a = '-';
    char del_b = ',';
    int size = 0;
    int row_sz = 0;
    char **buf_a = NULL;
    char **buf_b = NULL;

    while(file_arr[size]){
        size++;
    }

    rslt = (char***)malloc(sizeof(char**) * (1 + size));
    rslt ? mx_printstr("\ngoed\n") : mx_printstr("\nniet\n");

    for (int i = 0; i <= size; i++) {
        if (i == size) {
            rslt[i] = 0;
        }
        else if (i == 0) {
            row_sz = 2;
            rslt[i] = (char **)malloc(sizeof(char *) * row_sz);
            for (int j = 0; j < row_sz - 1; j++){
                if(j == row_sz-1){
                    rslt[i][j] = 0;
                }
                else {
                    mx_strdup(file_arr[j]);
                }
            }
        }
        else {
            row_sz = 4;
            rslt[i] = (char**)malloc(sizeof(char*) * row_sz);
            for (int j = 0; j < row_sz - 1; j++) {
                if (j == row_sz-1) {
                    rslt[i][j] = 0;
                }
                else {
 buf_a = mx_strsplit(file_arr[i], del_a);
                    buf_b = mx_strsplit(buf_a[1], del_b);
                    for (int j = 0; j < row_sz - 1; j++){
                        switch (j) {
                            case 0:
                                rslt[i][j] = mx_strdup(buf_a[j]);
                                break;
                            case 3:
                                rslt[i][j] = 0;
                                break;
                            default:
                                rslt[i][j] = mx_strdup(buf_b[j - 1]);
                                break;
                        }
                    }
                }
            }
        }
    }

mx_printchar(DELIM);
    mx_printint(size);
mx_printchar(DELIM);
    return rslt;
}
