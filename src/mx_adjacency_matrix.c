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
/*

void mx_adjacency_matrix(t_validation *v, t_matrix *m) {
    unsigned from;
    unsigned to;
    m->adj_m = (unsigned**)malloc(sizeof(unsigned *) * v->amt);
    m->next_m = (int**)malloc(sizeof(int*) * v->amt);

    for(from = 0; from < v->amt; from++) {
        m->adj_m[from] = (unsigned*)malloc(sizeof(unsigned) * v->amt);
        m->next_m[from] = (int*)malloc(sizeof(int) * v->amt);
        for (to = 0; to < v->amt; to++) {
            m->adj_m[from][to] = (from == to) ? 0 : INT_MAX;
            m->next_m[from][to] = to;
        }
    }

    for(int i = 0; v->islands[i]; i++) {

        v->buf_a = mx_strsplit(v->islands[i], '-');
        from = get_island_index(v->unique_islands, v->buf_a[0]);
        to = get_island_index(v->unique_islands, v->buf_a[1]);
        mx_del_strarr(&v->buf_a);

        m->adj_m[from][to] = (unsigned)mx_atoi(v->distances[i]);
        m->adj_m[to][from] = (unsigned)mx_atoi(v->distances[i]);
    }
}
*/

void mx_adjacency_matrix(t_validation *v, t_matrix *m) {
    int from;
    int to;

    m->adj_m = (unsigned**)malloc(sizeof(unsigned *) * v->amt);
    m->is_direct = (bool**)malloc(sizeof(bool *) * v->amt);

    for (from = 0; from < v->amt; from++) {
        m->adj_m[from] = (unsigned*)malloc(sizeof(unsigned *) * v->amt);
        m->is_direct[from] = (bool*)malloc(sizeof(unsigned *) * v->amt);
        
        for(to = 0; to < v->amt; to++) {
            m->adj_m[from][to] = (from == to) ? 0 : INT_MAX;
            m->is_direct[from][to] = (from == to) ? TRUE : FALSE;
        }
    }

    for (int i = 0; v->islands[i]; i++) {
        v->buf_a = mx_strsplit(v->islands[i], '-');
        from = get_island_index(v->unique_islands, v->buf_a[0]);
        to = get_island_index(v->unique_islands, v->buf_a[1]);
        mx_del_strarr(&v->buf_a);

        m->adj_m[from][to] = (unsigned)mx_atoi(v->distances[i]);
        m->adj_m[to][from] = (unsigned)mx_atoi(v->distances[i]);
        
        m->is_direct[from][to] = TRUE;
        m->is_direct[to][from] = TRUE;
    }

}
