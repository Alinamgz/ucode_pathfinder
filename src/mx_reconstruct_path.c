#include "pathfinder.h"

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
