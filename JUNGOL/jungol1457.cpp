#include <stdio.h>

#define MAX 100

int paper[MAX][MAX];
int visited[MAX][MAX];
int M, N, K;
int s_row, f_row, s_col, f_col;



int dir_x[4] = {0, 0, -1, 1 };       // �����¿�
int dir_y[4] = {1, -1, 0, 0 };		  // �����¿�	
int DFS(int i, int j);
int danji[MAX * MAX];
int danjicount = 0;

int main() {
	freopen("Text.txt", "rt", stdin);
	scanf("%d %d %d", &M, &N, &K);

	for (int i = 0; i < K; i++) {
		scanf("%d %d %d %d", &s_col, &s_row, &f_col, &f_row);

		// visit check����.
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

	// �̹��� �������ķ� �غ���.
	// 2��° ������ �����Ͽ� �̹� �տ� �ִ� ���� ���� �Ǿ� �մ� �����κ���
	// ���� ������ ���� ��ġ�� ã�� ���Ĺ���̴�. 
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
	//1. �湮ó��
	visited[i][j] = 1;
	int count = 1;
	//2. �����¿찡 0�ΰ��� üũ�ϰ� ���� ����+1�Ͽ� return�ϸ� ��.
	for (int d = 0; d < 4; d++) {
		int y = i + dir_y[d];
		int x = j + dir_x[d];
		// ���� index���� ���� �־���ϰ�,(0~M-1, 0~N-1)
		// �� ������,, �湮���� �ʾƾ� �ϰ�, ���� 0�̾���Ѵ�.
		if ((y >= 0 && y < M) && (x >= 0 && x < N)) {
			if (paper[y][x] == 0 && visited[y][x] == 0) {
				count += DFS(y, x);
			}
		}
	}
	return count;
}


