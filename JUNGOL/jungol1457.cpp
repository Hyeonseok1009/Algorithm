#include <stdio.h>

#define MAX 100

int paper[MAX][MAX];
int visited[MAX][MAX];
int M, N, K;
int s_row, f_row, s_col, f_col;



int dir_x[4] = {0, 0, -1, 1 };       // 상하좌우
int dir_y[4] = {1, -1, 0, 0 };		  // 상하좌우	
int DFS(int i, int j);
int danji[MAX * MAX];
int danjicount = 0;

int main() {
	freopen("Text.txt", "rt", stdin);
	scanf("%d %d %d", &M, &N, &K);

	for (int i = 0; i < K; i++) {
		scanf("%d %d %d %d", &s_col, &s_row, &f_col, &f_row);

		// visit check하자.
		for (int i = s_row; i < f_row; i++) {
			for (int j = s_col; j < f_col; j++) {
				paper[i][j] = 1;
			}
		}
	}

	/*for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			printf("%2d ", paper[i][j]);
		}
		printf("\n");
	}*/

	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			if (paper[i][j] == 0 && visited[i][j] == 0) {
				danji[danjicount++] = DFS(i, j);
			}
		}
	}

	// 이번엔 삽입정렬로 해보잣.
	// 2번째 값부터 시작하여 이미 앞에 있는 것은 정렬 되어 잇는 것으로보고
	// 내가 선택한 것의 위치를 찾는 정렬방법이다. 
	for (int i = 1; i < danjicount; i++) {
		int idx = i;
		for (int j = i - 1; j >= 0; j--) {
			if (danji[idx] < danji[j]) {
				int tmp = danji[idx];
				danji[idx] = danji[j];
				danji[j] = tmp;
				idx--;
			}
			else break;
		}
	}
	printf("%d\n", danjicount);
	for (int i = 0; i < danjicount; i++) {
		printf("%d ", danji[i]);
	}
}

int DFS(int i, int j) {
	//1. 방문처리
	visited[i][j] = 1;
	int count = 1;
	//2. 상하좌우가 0인것을 체크하고 내꺼 포함+1하여 return하면 댐.
	for (int d = 0; d < 4; d++) {
		int y = i + dir_y[d];
		int x = j + dir_x[d];
		// 먼저 index범위 내에 있어야하고,(0~M-1, 0~N-1)
		// 그 다음은,, 방문하지 않아야 하고, 값이 0이어야한다.
		if ((y >= 0 && y < M) && (x >= 0 && x < N)) {
			if (paper[y][x] == 0 && visited[y][x] == 0) {
				count += DFS(y, x);
			}
		}
	}
	return count;
}


