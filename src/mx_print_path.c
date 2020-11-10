#include "pathfinder.h"

static void print_route(t_validation *v, t_matrix *m) {
    mx_printstr(ROUTE);
    for (int j = 0; m->path[j] != -1; j++){
        mx_printstr(v->unique_islands[m->path[j]]);
        if (m->path[1+j] >= 0) {
            mx_printstr(ARROW);
        }
    }
}

static void print_distance(int start, int end, t_matrix *m) {
    mx_printstr(DISTANCE);

    for (int d = 0; m->path[d] != -1; d++) {
        m->from = m->path[1 + d] != -1 ? m->path[d] : start;
        m->to = m->path[1 + d] != -1 ? m->path[1 + d] : end;

        if (d > 0) {
            m->from == start ? mx_printstr(EQUALS) : mx_printstr(PLUS);
        }
        mx_printint(m->adj_m[m->from][m->to]);

        if (m->path[2] == -1) 
            break;
    }
}

void mx_print_path (int start, int end, t_validation *v, t_matrix *m) {
    mx_printstr(START_BOUNDARY);
    mx_printstr(PATH);
    mx_printstr(v->unique_islands[start]);
    mx_printstr(ARROW);
    mx_printstr(v->unique_islands[end]);
    print_route(v, m);
    print_distance(start, end, m);
    mx_printstr(END_BOUNDARY);
}

