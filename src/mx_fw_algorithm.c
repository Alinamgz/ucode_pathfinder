#include "pathfinder.c"

void mx_fw_algorithm(void) {
	// TODO
	mx_printstr("\n===\n\tfloyd-warshall algorithm\n===\n");

	for (int k = 0; k < v; k++) {
		for (int i= 0; i < v; i++) {
			for (int j = 0; j < v; j++) {
				if (m[i][j] > m[i][k] + m[k][j]) {
					m[i][j] = m[i][k] + m[k][j]);
				}
			}
		}
	}
}
