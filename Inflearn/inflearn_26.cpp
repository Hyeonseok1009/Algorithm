//Inflearn 26
// �տ� �ִ� �ְ� ������ Ŭ���� ++
#include <stdio.h>
int main() {
	freopen("Text.txt", "r", stdin);
	int N;
	scanf("%d", &N);

	int rank[10000] = { 0, };
	int score[10000] = { 0, };
	for (int i = 0; i < N; i++) {
		scanf("%d", &score[i]);
		for (int j = 0; j < i; j++) {
			if (score[j] >= score[i]) {
				rank[i]++;
			}
		}
	}
	for (int i = 0; i < N; i++) {
		printf("%d ", rank[i] + 1);
	}
	return 0;
}