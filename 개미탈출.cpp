#include <stdio.h>

int dir[4][2] = { {0,1},{0,-1},{-1,0},{1,0} }; // 상하좌우

struct zum {
	int x;
	int y;
	int dir;
	int visited;
}zums[5001];

int main() {
	freopen("Text.txt", "r", stdin);
	int TC;
	scanf("%d", &TC);
	for (int tc = 0; tc < TC; tc++) {
		int M, N, K;
		scanf("%d %d %d", &M, &N, &K);
		for (int n = 1; n <= N; n++) {
			scanf("%d %d %d", &zums[n].x, &zums[n].y, &zums[n].dir);
			zums[n].dir -= 1;
			zums[n].visited = 0;
		}
		int count = 0;
		int time = 0;
		int answer = 0;
		while (count < K) {
			time++;
			// 한발짝 이동
			for (int n = 1; n <= N; n++) {
				if (zums[n].visited == 0) {
					int zum_dir = zums[n].dir;
					zums[n].x += dir[zum_dir][0];
					zums[n].y += dir[zum_dir][1];
				}
			}
			// 충돌여부 확인 후 방향 세팅
			for (int n = 1; n < N; n++) {
				for (int p = n + 1; p <= N; p++) {
					if (zums[n].visited == 0 && zums[p].visited == 0) {
						if (zums[n].x == zums[p].x && zums[n].y == zums[p].y) {
							int tmp = zums[n].dir;
							zums[n].dir = zums[p].dir;
							zums[p].dir = tmp;
						}
					}
				}
			}
			int answer_idx[5001] = { 0, };
			// 도달체크
			for (int n = 1; n <= N; n++) {
				if (zums[n].visited == 0) {
					if (zums[n].x == M) {
						count++;
						zums[n].visited = 1;
						answer_idx[n] = 1;
						answer = n;
						//printf("%d %d\n", time, n);
					}
				}
			}

			/*printf("##time: %d\n", time);
			for (int n = 1; n <= N; n++) {
				printf("#num : %d x: %d y: %d dir : %d\n", n, zums[n].x, zums[n].y, zums[n].dir);
			}*/



			// 정답인경우. 
			if (count >= K) {
				//printf("%d",answer);
				for (int n = 1; n <= N; n++) {
					if (answer_idx[n] == 1 && zums[n].y<zums[answer].y) {
						answer = n;
						//printf("A%dA", n);
					}
				}
			}
		}

		printf("#%d %d %d\n", tc+1, time, answer);
		for (int n = 1; n <= N; n++) {
			zums[n].x = zums[n].y = zums[n].dir = zums[n].visited = 0;
		}
	}
	return 0;
}