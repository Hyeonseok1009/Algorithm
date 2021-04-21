//Floyd-Warshall Algorithm
#include <stdio.h>
#define swap(a, b) { int tmp; tmp = a; a = b; b = tmp; }
int TC;
int dist[1001][1001] = { 0, };
int D[1001] = { 0, };
int U[1001] = { 0, };
int V;

int main() {
	freopen("input.txt", "r", stdin);

	scanf("%d", &TC);
	for (int tc = 1; tc <= TC; tc++) {
		scanf("%d", &V);

		int i, j, k;
		for (i = 1; i <= V; i++) {
			for (j = 1; j <= V; j++) {
				scanf("%d", &dist[i][j]);
				if (i != j && dist[i][j] == 0) {
					dist[i][j] = 9999;
				}
			}
		}

		//Floyd-Warshall Algorithm
		for (k = 1; k <= V; k++) {
			for (i = 1; i <= V; i++) {
				for (j = 1; j <= V; j++) {
					if (dist[i][k] + dist[k][j] < dist[i][j]) {
						dist[i][j] = dist[i][k] + dist[k][j];
					}
				}
			}
		}
		int res = 9999;
		
		for (i = 1; i <= V; i++) {
			int tmp = 0;
			for (j = 1; j <= V; j++) {
				tmp += dist[i][j];
			}
			if (tmp < res) res = tmp;
		}

		printf("#%d %d\n", tc, res);
	}
	return 0;
}