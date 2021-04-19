//Inflearn 25
//숫자를 하나씩 읽어온다.석차 1등으로 시작
//만약 그 전것보다 크면, 석차유지. 나머지는 석차++
// 만약 그 전것과 같으면 석차 유지. 나머지도 유지.
// 만약 그 전것보다 작다면 석차++. 나머지는 유지.

#include <stdio.h>

int main() {
	freopen("Text.txt", "r", stdin);
	int N;
	scanf("%d", &N);
	int rank[100] = { 0, };
	int score[100] = { 0, };

	for (int i = 0; i < N; i++) {
		scanf("%d", &score[i]);
		for (int j = 0; j < i; j++) {
			if (score[j] < score[i]) {
				rank[j]++;
			}
			else if (score[j] > score[i]) {
				rank[i]++;
			}
		}
	}

	for (int i = 0; i < N; i++) {
		printf("%d ", rank[i] + 1);
	}

	return 0;
}