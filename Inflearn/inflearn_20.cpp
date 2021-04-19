//Inflearn 20
//가위 바위보 함수를 만든다. 
//이기지 못했으면 B가 이긴것.

#include <stdio.h>

char game(int a, int b) {
	if (a > b) {
		if (a == 3 && b == 1) {
			return 'B';
		}
		return'A';
	}
	else if (a == b) {
		return 'D';
	}
	else {
		if (a == 1 && b == 3) {
			return 'A';
		}
		return 'B';
	}
}

int main() {
	freopen("Text.txt", "r", stdin);
	for (int tc = 0; tc < 5; tc++) {
		int N;
		scanf("%d", &N);

		int a[100] = { 0, };
		int b[100] = { 0, };

		for (int i = 0; i < N; i++) {
			scanf("%d", &a[i]);
		}
		for (int i = 0; i < N; i++) {
			scanf("%d", &b[i]);
		}

		for (int i = 0; i < N; i++) {
			printf("%c\n", game(a[i], b[i]));
		}
		printf("\n");
	}
	return 0;
}
