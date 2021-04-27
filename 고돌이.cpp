#include <stdio.h>
#define MAX 26

int N;
int dol_r, dol_c, so_r, so_c;
int dol_h_r, dol_h_c, so_h_r, so_h_c;
int map[MAX][MAX];
int dol_map[MAX][MAX];
int so_map[MAX][MAX];

int dir[8][2] = {{ 0,-1 }, { -1,-1 }, { -1,0 }, { -1,1 }, { 0,1 }, { 1,1 }, { 1,0 }, { 1,-1}}; // 좌, 좌상, 상, 우상, 우, 우하, 하, 좌하

typedef struct _pos {
	int r;
	int c;
}POS;

// queue 자료구조 선언
POS dol_queue[MAX*MAX];
int dol_front = -1; int dol_rear = -1;
POS so_queue[MAX*MAX];
int so_front = -1; int so_rear = -1;

int flag_dol = 0;
int flag_so = 0;

void move_so() {

}

int BFS_DOL() {
	// dol visit & enque
	dol_map[dol_r][dol_c] = 1; // visit & level count.
	dol_rear++;
	dol_queue[dol_rear].r = dol_r;
	dol_queue[dol_rear].c = dol_c;

	// so visit & enque
	so_map[so_r][so_c] = 1; // visit & level count.
	so_rear++;
	so_queue[so_rear].r = so_r;
	so_queue[so_rear].c = so_c;
	
	while (dol_front != dol_rear) {
		// pop
		if (flag_dol) break;
		dol_front++;
		int dol_pop_r = dol_queue[dol_front].r;
		int dol_pop_c = dol_queue[dol_front].c;

		for (int i = 0; i < 8; i++) {
			int dol_mov_r = dol_pop_r + dir[i][0];
			int dol_mov_c = dol_pop_c + dir[i][1];
			if ( (map[dol_mov_r][dol_mov_c] != 1) && (dol_mov_r > 0 && dol_mov_r <= N) && ((dol_mov_c > 0 && dol_mov_c <= N))) {
				dol_map[dol_mov_r][dol_mov_r] = dol_map[dol_pop_r][dol_pop_c] +1;
				// if dol arrived
				if ((dol_mov_r == dol_h_r) && (dol_mov_c == dol_h_c)) {
					flag_dol = dol_map[dol_mov_r][dol_mov_r];
					break;
				}
				// dol push.
				dol_rear++;
				dol_queue[dol_rear].r = dol_mov_r;
				dol_queue[dol_rear].c = dol_mov_c;
			}
		}
	}
}




int main() {
	freopen("Text.txt", "rt", stdin);
	scanf("%d", &N);
	scanf("%d %d %d %d", &dol_r, &dol_c, &dol_h_r, &dol_h_c);
	scanf("%d %d %d %d", &so_r, &so_c, &so_h_r, &so_h_c);

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			scanf("%d", &map[i][j]);
			printf("%d ", map[i][j]);
		}
		printf("\n");
	}
	/*
	int answer = BFS();*/
}