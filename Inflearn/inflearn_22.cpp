// 1. ��ǲ ���� �޾ƿ´�.
// 2. ���ϰ��� ���� ���Ѵ�.(1ȸ)
// 3. �� �������ʹ� ù ���ڸ� ���� ������ ���ڸ� ���Ѵ�.
// 4. �ƽ����� sum �ΰ��� ������ ����ϴ�.

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