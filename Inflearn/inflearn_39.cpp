//Inflearn 38 : Inversion Sequence
#include <stdio.h>

int main() {
	freopen("Text.txt", "rt", stdin);
	for (int k = 1; k <= 5; k++) {
		int N, M;
		int a[101] = { 0, };
		int b[101] = { 0, };
		int total[201] = { 0, };
		scanf("%d", &N);
		for (int i = 1; i <= N; i++) {
			scanf("%d", &a[i]);
		}
		scanf("%d", &M);
		for (int i = 1; i <= M; i++) {
			scanf("%d", &b[i]);
		}
		int topos = 1;
		int apos = 1;
		int bpos = 1;
		while (apos <= N && bpos <= M) {
			if (a[apos] < b[bpos]) {
				total[topos++] = a[apos++];
			}
			else if (a[apos] > b[bpos]) {
				total[topos++] = b[bpos++];
			}
			else if (a[apos] == b[bpos]) {
				total[topos++] = a[apos++];
				total[topos++] = b[bpos++];
			}
			if (apos > N) {
				while (bpos <= M) {
					total[topos++] = b[bpos++];
				}
			}
			else if (bpos > M) {
				while (apos <= N) {
					total[topos++] = a[apos++];
				}
			}
		}
		for (int i = 1; i <= N + M; i++) {
			printf("%d ", total[i]);
		}
		printf("\n");
	}

}