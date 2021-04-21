//samsung_1260
#include <stdio.h>

#define MIN(A,B) ((A)>(B)?(B):(A))
#define MAX_VALUE 9999999
#define MAX_SIZE 101

int M[MAX_SIZE][MAX_SIZE];
int d[MAX_SIZE];

int count = 0;

int col_return(int row, char(*arr)[2]) {
	for (int i = 1; i <= count; i++) {
		if (arr[i][0] == row) {
			return arr[i][1];
		}
	}
	return 0;
}

int main() {
	//freopen("Text.txt", "r", stdin);
	int TC;
	scanf("%d", &TC);
	int size;
	for (int tc = 1; tc <= TC; tc++) {
		scanf(" %d", &size);

		//일단 인풋 받아오자.
		char arr[101][101] = { 0, };

		for (int i = 0; i < size; i++) {
			for (int j = 0; j < size; j++) {
				scanf("%d", &arr[i][j]);
				//printf("%d ", arr[i][j]);
			}
			//printf("\n");
		}
		char submat_size[21][2] = { 0, }; // 0: row 1: col
		int kkkk[101] = { 0, };
		// 전체 count수 를 유지하고, 그것을 이용하여 부분매트릭스를 구한다.
		count = 0;
		for (int i = 0; i < size; i++) {
			for (int j = 0; j < size; j++) {
				int col = 0;
				int row = 0;
				int tmp_row = i;
				int tmp_col = j;
				if (arr[i][j] != 0) {
					//row
					while (arr[tmp_row][j] != 0) {
						tmp_row++;
					}
					row = tmp_row - i;
					//col
					while (arr[i][tmp_col] != 0) {
						tmp_col++;
					}
					col = tmp_col - j;

					++count;
					submat_size[count][0] = row;
					submat_size[count][1] = col;
					kkkk[row]++;
					kkkk[col]++;
					for (int r = tmp_row - 1; r > tmp_row - 1 - row; r--) {
						for (int c = tmp_col - 1; c > tmp_col - 1 - col; c--) {
							arr[r][c] = 0;
						}
					}
				}
			}
		}


		/*for (int i = 0; i < 21; i++) {
			printf("row: %d col: %d\n", submat_size[i][0], submat_size[i][1]);
		}*/
		// 1. 핵심은 D 배열을 만드는것/
		// row 값을 넣으면 col 값을반환 하는 함수를 찾자.  없으면 0반환/

		int start;
		for (int i = 0; i < 101; i++) {
			if (kkkk[i] == 1) {
				start = i;
				if (col_return(start, submat_size) != 0) {
					break;
				}
			}
		}

		/*printf(" %d ",start);*/
		//D 만들기
		d[0] = start;
		for (int i = 0; i <= count; i++) {
			int col = col_return(d[i], submat_size);
			d[i + 1] = col;
		}

		/*for (int i = 0; i <= count; i++) {
			printf(" %d ", d[i]);
		}
		printf("\n");*/


		for (int i = 1; i <= count; i++) M[i][i] = 0;
		for (int length = 2; length <= count; length++) {
			for (int i = 1; i <= count - length + 1; i++) {
				int j = i + length - 1;
				M[i][j] = MAX_VALUE;
				for (int k = i; k < j; k++) {
					M[i][j] = MIN(M[i][j], M[i][k] + M[k + 1][j] + d[i - 1] * d[k] * d[j]);
				}
			}
		}

		printf("#%d %d\n", tc, M[1][count]);

		for (int i = 0; i <= count; i++) {
			d[i] = 0;
			for (int j = 0; j <= count; j++) {
				M[i][j] = 0;
			}
		}
	}
	return 0;
}