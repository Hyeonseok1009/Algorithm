//Inflearn 25
//���ڸ� �ϳ��� �о�´�.���� 1������ ����
//���� �� ���ͺ��� ũ��, ��������. �������� ����++
// ���� �� ���Ͱ� ������ ���� ����. �������� ����.
// ���� �� ���ͺ��� �۴ٸ� ����++. �������� ����.

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