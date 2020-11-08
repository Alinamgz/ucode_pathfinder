#include "pathfinder.h"

int main(int arc, char *arv[]) {
    t_validation *validation = (t_validation *)malloc(sizeof(t_validation));

    mx_init_validation(validation);
    mx_validation(arc, arv[1], validation);
    
    t_matrix *matrix = (t_matrix *)malloc(sizeof(t_matrix));
    void mx_adjacency_matrix(t_validation v, t_matrix m);
    // TODO: delete printchar && system leaks
    mx_printchar(DELIM);
    system("leaks -q pathfinder");
    return 0;
}
