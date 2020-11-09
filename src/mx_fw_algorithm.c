#include "pathfinder.h"

void mx_fw_algorithm(t_matrix *m) {
	// TODO
	mx_printstr("\n===\n\tfloyd-warshall algorithm\n===\n");

	for (int k = 0; k < m->amt; k++) {
		for (int i= 0; i < m->amt; i++) {
			for (int j = 0; j < m->amt; j++) {
				if (m->adj_m[i][j] > m->adj_m[i][k] + m->adj_m[k][j]) {
					m->adj_m[i][j] = m->adj_m[i][k] + m->adj_m[k][j];
                    m->next_m[i][j] = k;
				}
			}
		}
	}
}
