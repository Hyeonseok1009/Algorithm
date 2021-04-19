//Inflearn #35
#include <stdio.h>

int main() {
	int N;
	scanf("%d", &N);

	int positive[100] = { 0, };
	int negative[100] = { 0, };
	int p_counter = 0;
	int n_counter = 0;

	int tmp, i;
	for (i = 0; i < N; i++) {
		scanf("%d", &tmp);
		if (tmp < 0) {
			negative[n_counter++] = tmp;
		}
		else {
			positive[p_counter++] = tmp;
		}
	}

	for (i = 0;i < n_counter;i++) {
		printf("%d ", negative[i]);
	}
	for (i = 0;i < p_counter;i++) {
		printf("%d ", positive[i]);
	}
	printf("\n");
}
