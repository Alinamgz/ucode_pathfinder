#include "pathfinder.h"

int main(int arc, char *arv[]) {
    t_validation *validation = (t_validation *)malloc(sizeof(t_validation));

    mx_init_validation(validation);
    mx_validation(arc, arv[1], validation);

    t_matrix *matrix = (t_matrix *)malloc(sizeof(t_matrix));
    mx_adjacency_matrix(validation, matrix);

    mx_fw_algorithm(validation->amt, matrix);

    mx_printstr("\n-------------\n\n");
    for (int i = 0; i < validation->amt; i++) {
        mx_printchar(DELIM);
        for (int j = 0; j < validation->amt; j++) {
            mx_printchar('\t');
            mx_printint(matrix->adj_m[i][j]);
        }
            mx_printchar('\t');
        mx_printstr(validation->unique_islands[i]);
    }
    mx_printstr("\n-------------\n\n");

    mx_reconstruct_path(validation, matrix);

    /*
    for (int i = 0; validation->unique_islands[i]; i++) {
        for (int j = 1 + i; validation->unique_islands[j]; j++) {
            if (i != j) {
                mx_reconstruct_path(i, j, validation, matrix);
            }
        }
    }
    */
    

    // TODO: delete printchar && system leaks
    mx_printchar(DELIM);
    mx_printchar(DELIM);
    system("leaks -q pathfinder");
    return 0;
}
