#include "pathfinder.h"

void mx_init_validation(t_validation *v) {
    v->i = 0;
    v->j = 0;
    v->lines = 0;
    v->amt = 0;
    v->total_dist = 0;
    v->file_str = NULL;
    v->file_strarr = NULL;
    v->unique_islands = NULL;
    v->islands = NULL;
    v->distances = NULL;
    v->buf_a = NULL;
    v->buf_b = NULL;
}
