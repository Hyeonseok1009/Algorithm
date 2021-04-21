// 1. 이차원배열 설정 K[i,w]
// 2. 쉬운듯

#define max(a,b) (((a)>(b))?(a):(b))

#include <stdio.h>
typedef struct _item {
	int wi;
	int pi;
}item;

int main() {
	//freopen("Text.txt", "rt", stdin);
	int N, W;
	scanf("%d %d", &N, &W);

	item items[20] = { 0, };
	for (int i = 1; i <= N; i++) {
		scanf("%d %d", &items[i].wi, &items[i].pi);
		//printf("%d %d", items[i].wi, items[i].pi);
	}
	//Knapsack 배열 선언//
	int** knap  = new int*[N];

	for (int i = 0; i <= N; i++) {
		knap[i] = new int [W];
		knap[i][0] = 0;
	}

	for (int i = 0; i <= W; i++) {
		knap[0][i] = 0;
	}

	for (int i = 1; i <= N; i++) {
		for (int w = 1; w <= W; w++) {
			if (items[i].wi > w) {
				knap[i][w] = knap[i - 1][w];
			}
			else {
				knap[i][w] = max(knap[i - 1][w - items[i].wi] + items[i].pi, knap[i - 1][w]);
			}
		}
	}
	/*for (int i = 1; i <= W; i++) {
		printf("%3d ", i);
	}
	printf("\n");

	for (int i =1; i <= N; i++) {
		for (int w = 1; w <= W; w++) {
			printf("%3d ", knap[i][w]);
		}
		printf("\n");
	}*/
	printf("%d", knap[N][W]);
}