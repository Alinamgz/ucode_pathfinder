#include "pathfinder.h"

char ***mx_split_arr(char **file_arr) {
    char del_a = '-';
    char del_b = ',';
    char **buf_a = NULL;
    char **buf_b = NULL;
    char ***rslt = NULL;
    int r_sz = 0;

    while(file_arr[r_sz]){
        r_sz++;
    }

    rslt = (char ***)malloc(sizeof(char **) * (1 + r_sz));

    for (int x = 0; x <= r_sz; x++) {
        if (x == r_sz) {
            rslt[x] = 0;
        }
        else if (x == 0) {
            rslt[x] = mx_strsplit(file_arr[x], del_a);
        }
        else {
            rslt[x] = (char **)malloc(sizeof(char *) * 4);
            buf_a = mx_strsplit(file_arr[x], del_a);
            buf_b = mx_strsplit(buf_a[1], del_b);
            rslt[x][0] = buf_a[0];
            rslt[x][1] = buf_b[0];
            rslt[x][2] = buf_b[1];
            rslt[x][3] = 0;
            mx_del_strarr(buf_a);
            mx_del_strarr(buf_b);
        }
    }
    return rslt;
}
