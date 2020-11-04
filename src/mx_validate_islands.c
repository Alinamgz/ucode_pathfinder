#include "pathfinder.h"

void mx_validate_islands(t_validation *v) {
    v->amt = mx_atoi(v->file_strarr[0]);
    v->u_islands = (char**)malloc(sizeof(char*) * (1 + v->amt));
    v->islands = (char**)malloc(sizeof(char*) * v->lines);
    bool unique = 1;

    for(v->j = 1 + v->amt; v->j > 0; v->j-- ) {
        v->u_islands[v->j] = NULL;
    }
    v->u_islands[v->j] = NULL;

    for (int k = 0; k <= v->lines; k++) {
        v->islands[k] = NULL;
    }

    for(v->i = 1;v->i < v-> lines; v->i++) {
        v->buf_a = mx_strsplit(v->file_strarr[v->i], ',');
        v->buf_b = mx_strsplit(v->buf_a[0], '-');
        v->dist_tot += mx_atoi(v->buf_a[1]);
        v->islands[v->i-1] = mx_strdup(v->buf_a[0]);
        for (int a = 0; v->buf_b[a]; a++) {
            unique = 1;
            for(int b = 0; v->u_islands[b]; b++) {
                if(mx_strcmp(v->u_islands[b], v->buf_b[a]) == 0) {
                    unique = 0;
                    break;
                }
            }
            if (unique) {
                if (v->j < v->amt) {
                v->u_islands[v->j] = mx_strdup(v->buf_b[a]);
                }
                   v->j++;
            }
        }
        mx_del_strarr(&v->buf_a);
        mx_del_strarr(&v->buf_b);
    }

    if (v->j != v->amt) {
        mx_printerr(ISLANDS_AMT_ERR);
        exit(1);
    }
}
