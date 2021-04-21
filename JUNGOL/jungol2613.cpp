#include <stdio.h>

#define MAX 1000
int M; // 열(col)
int N; // 행(row)
struct toma {
	int data;
	int level;
};
struct queue{
	int x;
	int y;
	int visited;
};

int dir_x[4] = { 0, 0, -1, 1 };       // 상하좌우
int dir_y[4] = { 1, -1, 0, 0 };		  // 상하좌우	
int BFS(toma ** tomato,int size);
int main() {
	freopen("Text.txt", "rt", stdin);
	scanf("%d %d", &M, &N);
	
	toma ** tomato = new toma*[N];
	for (int i = 0; i < N; i++) {
		tomato[i] = new toma[M];
	}

	int flag = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			scanf("%d", &tomato[i][j].data);
			if (tomato[i][j].data == 1) {
				tomato[i][j].level = 1;
			}
			else if(tomato[i][j].data == 0){
				flag = 1;  // 안익어 있는 토마토 있음!
				tomato[i][j].level = 0;
			}
		}
	}
	int answer = BFS(tomato,M*N);
	if (flag == 0) 
		printf("0\n");
	
	else
		printf("%d\n", answer);
	return 0;
}

int BFS(toma ** tomato,int size) {
	// queue자료구조
	// queue의 타입은 toma 이다.
	int front = -1;
	int rear = -1; 
	queue *q = new queue[size];
	// 순회하면서 data가 1인게 있으면 push 한다.
	for (int i = 0; i < size; i++) {
		q[i].visited = 0;
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (tomato[i][j].data == 1) {
				rear = rear +1;
				q[rear].y = i;
				q[rear].x = j;
				q[rear].visited = 1;
			}
		}
	}

	//printf("%d", rear);
	// 이제 push 및 pop 진행해야함/
	while (front != rear) {
		front = front + 1;
		int tmp_y = q[front].y;
		int tmp_x = q[front].x;
		q[front].visited = 1;
		toma tmp_tom = tomato[tmp_y][tmp_x];
		for (int i = 0; i < 4; i++) {
			int yy = tmp_y + dir_y[i];
			int xx = tmp_x + dir_x[i];
			if ((yy >= 0 && yy < N) && (xx >= 0 && xx < M)) {
				if (tomato[yy][xx].data == 0) {
					tomato[yy][xx].data = 1;
					tomato[yy][xx].level = tmp_tom.level + 1;
					rear = rear + 1;
					q[rear].y = yy;
					q[rear].x = xx;
				}
			}
		}
	}
	int max = -1;
	int flag = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			int tmp1 = tomato[i][j].level;
			int tmp2 = tomato[i][j].data;
			if (tmp2 == 0 && tmp1 == 0) {
				flag = 1;
			}
			if (tmp1 > max) max = tmp1;
		}
	}

	if (flag) return -1;
	else return max-1;
}

