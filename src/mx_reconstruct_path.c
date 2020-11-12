#include "pathfinder.h"
/*
   void mx_reconstruct_path(int start, int end, t_validation *v, t_matrix *m) {
   int i = 0;
   int at = 0;

   if (m->adj_m[start][end] != INT_MAX) {
   m->path = (int*)malloc(sizeof(int) * (m->amt + 1));

   for (i = 0; i <= m->amt + 1; i++) {
   m->path[i] = -1;
   }
   i = 0;

   for (at = start; at != end; at = m->next_m[at][end]) {
   m->path[i++] = at;
   }
   m->path[i] = end;

// outup draft

mx_print_path(start, end, v, m);
free(m->path);
}

}
 */

static void get_path(int from, int to, int at, t_validation *v, t_matrix *m) {
    if (from == to) {
    //TODO: del next 3 lines
mx_printchar(DELIM);
mx_printint(at);
mx_printchar(DELIM);
        mx_print_path(at-1, v, m);
        return;
    }

    at++;
    for (int i = 0; i < v->amt; i++) {
        if (m->is_direct[from][i] && from != i) {
            if (m->adj_m[from][to] == m->adj_m[from][i] + m->adj_m[i][to]) {
                m->path[at - 1] = i;
                get_path(i, to, at, v, m);
            }
        }
    }
}

void mx_reconstruct_path(t_validation *v, t_matrix *m) {
    m->path = (int*)malloc(sizeof(int) * (v->amt + 1));

    for (int i = 0; i <= v->amt; i++) {
        m->path[i] = -1;
    }

    for (int from = 0; from < v->amt; from++) {
        m->path[0] = from;

        for (int to = 1 + from; to < v->amt; to++) {
            get_path(from, to, 1, v, m);
        }
    }

    free(m->path);
}
