//플로이드 와샬알고리즘
#include <stdio.h>
#define INFINIT 987654321
#define MIN(A,B) (((A)>(B)) ? B: A)
#define MAX(A,B) (((A)<(B)) ? B: A)
int arr[501][501] = { 0, };
int D[501][501] = { 0, };
int main() {
	freopen("Text.txt", "rt", stdin);
	int N;
	scanf("%d", &N);

	int lastpage = 0;
	int start, dest;
	int tmp = 0;
	for (int i = 1; i <= N; i++) {
		scanf("%d %d", &start, &dest);
		tmp = MAX(start, dest);
		lastpage = MAX(lastpage, tmp);
		D[start][dest] = arr[start][dest] = 1;
	}

	for (int i = 1; i <= lastpage; i++) {
		for (int j = 1; j <= lastpage; j++) {
			if (i == j) {
				D[i][j] = arr[i][j] = 0;
			}
			else if (arr[i][j] != 1) {
				D[i][j] = arr[i][j] = INFINIT;
			}
		}
	}

	/*for (int i = 1; i <= lastpage; i++) {
		for (int j = 1; j <= lastpage; j++) {
			printf("%d ", arr[i][j]);
		}
		printf("\n");
	}*/

	for (int k = 1; k <= lastpage; k++) {
		for (int i = 1; i <= lastpage; i++) {
			for (int j = 1; j <= lastpage; j++) {
				D[i][j] = MIN(D[i][j], D[i][k] + D[k][j]);
			}
		}
	}
	int answer = 0;
	for (int i = 1; i <= lastpage; i++) {
		for (int j = 1; j <= lastpage; j++) {
			answer += D[i][j];
		}
	}
	int bunmo = (lastpage*(lastpage - 1));

	printf("%.3lf",(double)answer / bunmo);
}