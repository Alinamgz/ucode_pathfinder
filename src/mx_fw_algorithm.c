#include "pathfinder.h"

/*
void mx_fw_algorithm(t_matrix *m) {
	for (int k = 0; k < m->amt; k++) {
		for (int i= 0; i < m->amt; i++) {
			for (int j = 0; j < m->amt; j++) {
				if (m->adj_m[i][j] > m->adj_m[i][k] + m->adj_m[k][j]) {
					m->adj_m[i][j] = m->adj_m[i][k] + m->adj_m[k][j];
					m->adj_m[j][i] = m->adj_m[i][k] + m->adj_m[k][j];
                    m->next_m[i][j] = m->next_m[i][k];
                    m->next_m[j][i] = m->next_m[i][k];
				}
			}
		}
	}
}
*/

void mx_fw_algorithm(int amt, t_matrix *m) {
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
