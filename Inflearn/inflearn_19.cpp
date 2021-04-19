//Inflearn 19 분노 유발자.
// 처음인덱스부터 시작하여 끝까지 간다.
// 각각의 인덱스에서 부터 맨뒤까지의 값을 비교하여 한명이라도 큰 사람이 잇으면 브레이크 브레이크가 안되면 분노유발자인것


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
