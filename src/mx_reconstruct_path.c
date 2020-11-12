#include "pathfinder.h"

static void get_path(int from, int to, int at, t_validation *v, t_matrix *m) {
    if (from == to) {
        mx_print_path(at-1, v, m);
        return;
    }

    at++;
    for (int i = 0; i < v->amt; i++) {
        if (m->is_direct[from][i] && from != i) {
            if (m->adj_m[from][to] == m->adj_m[from][i] + m->adj_m[i][to]) {
                m->route[at - 1] = i;
                get_path(i, to, at, v, m);
            }
        }
    }
}

void mx_reconstruct_path(t_validation *v, t_matrix *m) {
    m->route = (int*)malloc(sizeof(int) * (v->amt + 1));

    for (int i = 0; i <= v->amt; i++) {
        m->route[i] = -1;
    }

    for (int from = 0; from < v->amt; from++) {
        m->route[0] = from;

        for (int to = 1 + from; to < v->amt; to++) {
            get_path(from, to, 1, v, m);
        }
    }

    free(m->route);
}
