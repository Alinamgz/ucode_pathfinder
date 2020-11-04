#include "pathfinder.h"

int main(int arc, char *arv[]) {
    t_validation *validation = (t_validation*)malloc(sizeof(t_validation));

  mx_init_validation(validation);
  mx_validation(arc, arv[1], valid);
  mx_printchar(DELIM);
    system("leaks -q pathfinder");
    return 0;
}
