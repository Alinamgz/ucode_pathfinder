#include "pathfinder.h"

static void print_path (int start, int end, t_validation *v, t_matrix *m) {

    mx_printstr(START_BOUNDARY);
    mx_printstr(PATH);
    mx_printstr(v->unique_islands[start]);
    mx_printstr(ARROW);
    mx_printstr(v->unique_islands[end]);
    mx_printstr(ROUTE);
    for (int j = 0; m->path[j] != -1; j++){
        mx_printstr(v->unique_islands[m->path[j]]);
        if (m->path[1+j] >= 0) {
            mx_printstr(ARROW); 
        }
    }
    mx_printstr(DISTANCE);
//TODO: fix output
    for (int d = 0; m->path[d] != -1; d++) {
        m->from = m->path[1 + d] != -1 ? m->path[d] : start;
        m->to = m->path[1 + d] != -1 ? m->path[1 + d] : end;

        if (d > 0) {
            m->from == m->path[0] ? mx_printstr(EQUALS) : mx_printstr(PLUS);
        }
        mx_printint(m->adj_m[m->from][m->to]);
    }
    mx_printstr(END_BOUNDARY);
}

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
    }

    // outup draft
    mx_printchar(DELIM);
    mx_printchar(DELIM);

    print_path(start, end, v, m);

}
