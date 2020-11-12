#include "pathfinder.h"

void mx_run_fw_algorithm(int amt, t_matrix *m) {
	for (int k = 0; k < amt; k++) {
		for (int i= 0; i < amt; i++) {
			for (int j = 0; j < amt; j++) {
				if (m->adj_m[i][j] > m->adj_m[i][k] + m->adj_m[k][j]) {
					m->adj_m[i][j] = m->adj_m[i][k] + m->adj_m[k][j];
                    m->is_direct[i][j] = FALSE;
				}
			}
		}
	}
}
