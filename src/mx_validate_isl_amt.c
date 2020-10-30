#include "pathfinder.h"

void mx_validate_isl_amt(t_validation *v) {
    v->amt = mx_atoi(v->file_strarr[0]);
    v->islands = (char**)malloc(sizeof(char*) * (1+ 2 * v->lines));
    
    for(v->j = 2 * v->lines; v->j > 0; v->j-- ) {
        v->islands[v->j] = NULL;
    }
    v->islands[v->j] = NULL;

mx_printint(v->j);

    for( ;v->i > 0; v->i--) {
mx_printstr("\ncheck\n");
        v->buf_dist = mx_strsplit(v->file_strarr[v->i], ',');
        v->buf_isl = mx_strsplit(v->buf_dist[0], '-');
        v->dist_tot += mx_atoi(v->buf_dist[1]);
        for (int a = 0; v->buf_isl[a]; a++) {
            v->islands[v->j] = mx_strdup(v->buf_isl[a]);
            v->j++;
        }
        mx_del_strarr(&v->buf_dist);
        mx_del_strarr(&v->buf_isl);
    }

for(int i = 0; v->islands[i]; i++) {
    mx_printstr(v->islands[i]);
    mx_printchar(DELIM);
}
}
