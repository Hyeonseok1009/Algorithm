//Inflearn 19 �г� ������.
// ó���ε������� �����Ͽ� ������ ����.
// ������ �ε������� ���� �ǵڱ����� ���� ���Ͽ� �Ѹ��̶� ū ����� ������ �극��ũ �극��ũ�� �ȵǸ� �г��������ΰ�


#include <stdio.h>

int main() {
	freopen("Text.txt", "r", stdin);
	for (int tc = 0; tc < 5; tc++) {
		int N;
		scanf("%d", &N);
		int tallest[101] = { 0, };
		for (int j = 1; j <= N; j++) {
			scanf("%d", &tallest[j]);
		}

		int count = 0;
		for (int i = 1; i <= N - 1; i++) {
			int flag = 0;
			for (int j = i + 1; j <= N; j++) {
				if (tallest[i] <= tallest[j]) {
					flag = 1; 
					break;
				}
			}
			if (flag == 0) {
				count++;
			}
		}
		printf("%d\n", count);
	}
}
