// 1. 인풋 전부 받아온다.
// 2. 몇일간의 합을 구한다.(1회)
// 3. 그 다음부터는 첫 숫자를 빼고 마지막 숫자를 더한다.
// 4. 맥스값과 sum 두개의 변수면 충분하다.

#include<stdio.h>

int ondo[100001], max ,sum;
int main() {
	freopen("Text.txt", "r", stdin);
	int N, k;
	scanf("%d %d", &N, &k);

	for (int i = 1; i <= N; i++) {
		scanf("%d", &ondo[i]);
	}

	for (int i = 1; i <= k; i++) {
		sum += ondo[i];
	}
	max = sum;
	for (int i = 2; i <= N - k + 1; i++) {
		sum = sum - ondo[i - 1] + ondo[i + -1 + k];
		if (max < sum) max = sum;
	}

	printf("%d", max);

	return 0;
}