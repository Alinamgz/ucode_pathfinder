#include "pathfinder.h"

static void bridges_error(t_validation *v, bool lng_err) {
    lng_err ? mx_printerr(BRIDGES_LNG_ERR) : mx_printerr(BRIDGES_AMT_ERR);
    if (v->buf_a)
        mx_del_strarr(&(v->buf_a));
    if (v->buf_b)
        mx_del_strarr(&(v->buf_b));
    exit(1);
}

void mx_validate_bridges(t_validation *v) {
    for (v->i = 0; v->islands[v->i]; v->i++) {
        v->buf_a = mx_strsplit(v->islands[v->i], '-');
        for (v->j = 1 + v->i; v->islands[v->j]; v->j++) {
            v->buf_b = mx_strsplit(v->islands[v->j], '-');
            if (!mx_strcmp(v->buf_a[0], v->buf_b[0]) &&
                !mx_strcmp(v->buf_a[1], v->buf_b[1])) {
                bridges_error(v, 0);
            }
            if (!mx_strcmp(v->buf_a[0], v->buf_b[1]) &&
                !mx_strcmp(v->buf_a[1], v->buf_b[0])) {
                bridges_error(v, 0);
            }
            mx_del_strarr(&v->buf_b);
        }
        mx_del_strarr(&v->buf_a);
    }

    if (v->total_dist > INT_MAX)
        bridges_error(v, 1);
}
