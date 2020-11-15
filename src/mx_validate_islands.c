#include "pathfinder.h"

static void prepare_validation(t_validation *v) {
    v->unique_islands = (char **)malloc(sizeof(char *) * (1 + v->amt));
    v->islands = (char **)malloc(sizeof(char *) * v->lines);
    v->distances = (char **)malloc(sizeof(char *) * v->lines);

    for (v->j = 1 + v->amt; v->j > 0; v->j--) {
        v->unique_islands[v->j] = NULL;
    }
    v->unique_islands[v->j] = NULL;

    for (int k = 0; k <= v->lines; k++) {
        v->islands[k] = NULL;
        v->distances[k] = NULL;
    }
}

static void pick_unique_islands(t_validation *v) {
    bool is_unique = 1;

    for (int a = 0; v->buf_b[a]; a++) {
        is_unique = 1;
        for (int b = 0; v->unique_islands[b]; b++) {
            if (!mx_strcmp(v->unique_islands[b], v->buf_b[a])) {
                is_unique = 0;
                break;
            }
        }
        if (is_unique) {
            if (v->j < v->amt) {
                v->unique_islands[v->j] = mx_strdup(v->buf_b[a]);
            }
            v->j++;
        }
    }
}

void mx_validate_islands(t_validation *v) {
    v->amt = mx_atoi(v->file_strarr[0]);

    prepare_validation(v);
    for (v->i = 1; v->i < v->lines; v->i++) {
        v->buf_a = mx_strsplit(v->file_strarr[v->i], ',');
        v->buf_b = mx_strsplit(v->buf_a[0], '-');
        v->islands[v->i - 1] = mx_strdup(v->buf_a[0]);
        v->distances[v->i - 1] = mx_strdup(v->buf_a[1]);
        v->total_dist += mx_atoi(v->buf_a[1]);

        if (mx_strcmp(v->buf_b[0], v->buf_b[1]) == 0) {
            mx_line_error(v->i);
        }

        pick_unique_islands(v);

        mx_del_strarr(&v->buf_a);
        mx_del_strarr(&v->buf_b);
    }

    if (v->j != v->amt) {
        mx_printerr(ISLANDS_AMT_ERR);
        exit(1);
    }
}
