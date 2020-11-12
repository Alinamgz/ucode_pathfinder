#include "pathfinder.h"

static void print_route(int to, t_validation *v, t_matrix *m) {
    mx_printstr(ROUTE);
    for (int j = 0; j <= to; j++){
        mx_printstr(v->unique_islands[m->route[j]]);
        if ((1 + j) <= to) {
            mx_printstr(ARROW);
        }
    }
}

static void print_distance(int start, int end, int steps, t_matrix *m) {
    int from = -1;
    int to = -1;
    mx_printstr(DISTANCE);

    for (int d = 0; m->route[d] != -1 && d <= steps; d++) {
        from = m->route[1 + d] != -1 && d != steps ? m->route[d] : start;
        to = m->route[1 + d] != -1 && d != steps ? m->route[1 + d] : end;

        if (d > 0) {
            from == start ? mx_printstr(EQUALS) : mx_printstr(PLUS);
        }
        mx_printint(m->adj_m[from][to]);

        if (steps < 2) 
            break;
    }
}

void mx_print_path (int to, t_validation *v, t_matrix *m) {
    int start = m->route[0];
    int end = m->route[to];

    mx_printstr(START_BOUNDARY);
    mx_printstr(PATH);
    mx_printstr(v->unique_islands[start]);
    mx_printstr(ARROW);
    mx_printstr(v->unique_islands[end]);
    print_route(to, v, m);
    print_distance(start, end, to, m);
    mx_printstr(END_BOUNDARY);
}

