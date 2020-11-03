#include "pathfinder.h"
static void bridges_error(t_validation *v, bool len_err) {
    len_err ? mx_printerr(BRIDGES_LNG_ERR) : mx_printerr(BRIDGES_AMT_ERR);
    mx_del_strarr(&(v->buf_isl));
    mx_del_strarr(&(v->buf_dist));
system("leaks -q pathfinder");
    exit(1);
}

void mx_validate_bridges(t_validation *v) {
    for (v->i = 0; v->islands[v->i]; v->i++) {
        v->buf_isl = mx_strsplit(v->islands[v->i], '-');
        for (v->j = 1 + v->i; v->islands[v->j]; v->j++) {
            v->buf_dist = mx_strsplit(v->islands[v->j], '-');
            if (!mx_strcmp(v->buf_isl[0], v->buf_dist[0])
                &&
                !mx_strcmp(v->buf_isl[1], v->buf_dist[1])) {
                bridges_error(v, 0);
            }
            if (!mx_strcmp(v->buf_isl[0], v->buf_dist[1])
                &&
                !mx_strcmp(v->buf_isl[1], v->buf_dist[0])) {
                bridges_error(v, 0);
            }
            mx_del_strarr(&v->buf_dist);
        }
        mx_del_strarr(&v->buf_isl);
    }
    if (v->dist_tot > INT_MAX)
        bridges_error(v, 1);
}
