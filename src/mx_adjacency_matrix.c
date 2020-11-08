#include "pathfinder.h"

void mx_adjacency_matrix(t_validation v, t_matrix m) {
	m->adj_m = (int**)mx_realloc(sizeof(int *) * v->amt);
	for(int i = 0; i < v->amt; i++) {
		m->adj_m[i] = (int*)malloc(sizeof(int) * v->amt) ;
		for (int j = 0; j < v->amt; i++) {
			m[i][j] = (i == j) ? 0 : INT_MAX;
		}
	}
}
