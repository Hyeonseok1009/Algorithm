#include <stdio.h>

int dir[4][2] = { { -1, 0 }, { 1, 0 }, { 0, -1 }, { 0, 1 } };
int main() {
	freopen("Text.txt", "r", stdin);
	for (int i = 1; i <=5; i++){
		int H, W;
		scanf("%d %d", &H, &W);
		char arr[701][701] = { 0, };
		for (int row = 1; row <= H; row++){
			for (int col = 1; col <= W; col++){
				scanf("%d", &arr[row][col]);
			}
		}
		int t_H, t_W;
		scanf("%d %d", &t_H, &t_W);

		int prev = 0;
		int max = -1;
		for (int row = 1; row <= H - t_H + 1; row++){
			for (int col = 1; col <= W - t_W + 1; col++){
				int ans = prev;
				if (col == 1){
					ans = 0;
					for (int y = row; y <= row + (t_H - 1); y++){
						for (int x = col; x <= col + (t_W - 1); x++){
							ans += arr[y][x];
						}
					}
				}
				else{
					for (int y = row; y <= row + (t_H - 1); y++){
						ans = ans -  arr[y][col - 1];
						ans = ans + arr[y][col + (t_W - 1)];
					}
				}
				//printf("%d ", ans);
				if (max < ans) max = ans;
				prev = ans;
			}
		}
		printf("%d\n", max);
	}
}