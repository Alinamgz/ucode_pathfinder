#include "pathfinder.h"

int main(int arc, char *arv[]) {
    t_validation *validation = (t_validation *)malloc(sizeof(t_validation));
    mx_init_validation(validation);

    mx_validation(arc, arv[1], validation);

    t_matrix *matrix = (t_matrix *)malloc(sizeof(t_matrix));
    matrix->adj_m = NULL;
    matrix->is_direct = NULL;
    matrix->route = NULL;

    mx_build_matrix(validation, matrix);

    mx_run_fw_algorithm(validation->amt, matrix);
    mx_reconstruct_path(validation, matrix);

    return 0;
}
