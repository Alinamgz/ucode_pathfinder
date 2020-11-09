#include "pathfinder.h"

int main(int arc, char *arv[]) {
    t_validation *validation = (t_validation *)malloc(sizeof(t_validation));

    mx_init_validation(validation);
    mx_validation(arc, arv[1], validation);

    t_matrix *matrix = (t_matrix *)malloc(sizeof(t_matrix));
    mx_adjacency_matrix(validation, matrix);
    //==============================
    for (int i = 0; i < validation->amt; i++) {
        mx_printchar(DELIM);
        for(int j = 0; j < validation->amt; j++ ){
            mx_printchar('\t');
            mx_printint(matrix->adj_m[i][j]);
        }
    }
    //==============================

    mx_fw_algorithm(matrix);
    //==============================
    mx_printstr("\n===== AFTER =====\n");
    for(int i = 0; validation->unique_islands[i]; i++){
        mx_printchar('\t');
        mx_printstr(validation->unique_islands[i]);
    }
        mx_printchar(DELIM);
    for (int i = 0; i < matrix->amt; i++) {
        mx_printstr("\n  ");
        mx_printstr(validation->unique_islands[i]);
        for(int j = 0; j < validation->amt; j++ ){
            mx_printchar('\t');
            mx_printint(matrix->adj_m[i][j]);
        }
    }

    mx_printstr("\n----- NEXT -------\n");
    for(int i = 0; i < matrix->amt; i++) {
        mx_printstr("\n  ");
        mx_printstr(validation->unique_islands[i]);
        for(int j = 0; j < matrix->amt; j++) {
            mx_printchar('\t');
            mx_printint(matrix->next_m[i][j]);
        }

    }
    //==============================
    // TODO: delete printchar && system leaks
    mx_printchar(DELIM);
    mx_printchar(DELIM);
    system("leaks -q pathfinder");
    return 0;
}
