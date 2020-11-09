#include "pathfinder.h"

static int get_island_index(char **arr, char *str) {
    int rslt = 0;
    for(rslt = 0; arr[rslt]; rslt++) {
        if (mx_strcmp(arr[rslt], str) == 0) {
            return rslt;
        }
    }

    return -1;
}

void mx_adjacency_matrix(t_validation *v, t_matrix *m) {
    m->amt = v->amt;
    m->adj_m = (unsigned**)malloc(sizeof(unsigned *) * m->amt);
    m->next_m = (int**)malloc(sizeof(int*) * m->amt);

    for(m->from = 0; m->from < v->amt; m->from++) {
        m->adj_m[m->from] = (unsigned*)malloc(sizeof(unsigned) * m->amt);
        m->next_m[m->from] = (int*)malloc(sizeof(int) * m->amt);
        for (m->to = 0; m->to < v->amt; m->to++) {
            m->adj_m[m->from][m->to] = (m->from == m->to) ? 0 : INT_MAX;
            m->next_m[m->from][m->to] = m->to;
        }
    }

    for(int i = 0; v->islands[i]; i++) {
        v->buf_a = mx_strsplit(v->islands[i], '-');
        m->from = get_island_index(v->unique_islands, v->buf_a[0]);
        m->to = get_island_index(v->unique_islands, v->buf_a[1]);
        mx_del_strarr(&v->buf_a);

        m->adj_m[m->from][m->to] = (unsigned)mx_atoi(v->distances[i]);
        m->adj_m[m->to][m->from] = (unsigned)mx_atoi(v->distances[i]);
    }
}
