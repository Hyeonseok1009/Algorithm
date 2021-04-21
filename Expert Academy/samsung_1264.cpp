//samsung_1264

#include <stdio.h>

int LCS(char* str1, char* str2, int length) {
	int LCS[501][501];

	for (int i = 0; i <= length; i++) {
		LCS[i][0] = 0;
		LCS[0][i] = 0;
	}

	for (int i = 1; i <= length; i++) {
		for (int j = 1; j <= length; j++) {
			if (str1[i - 1] == str2[j - 1]) {
				LCS[i][j] = LCS[i - 1][j - 1] + 1;
			}
			else {
				LCS[i][j] = LCS[i - 1][j];
				if (LCS[i][j] < LCS[i][j - 1]) LCS[i][j] = LCS[i][j - 1];
			}
		}
	}

	/*for (int i = 1; i <= length; i++) {
		for (int j = 1; j <= length; j++) {
			printf("%2d ", LCS[i][j]);
		}
		printf("\n");
	}*/

	return LCS[length][length];
}

int main() {
	freopen("Text.txt", "r", stdin);

	int TC;
	scanf("%d", &TC);

	for (int tc = 1; tc <= TC; tc++) {
		int length = 0;
		char str1[501] = { 0, };
		char str2[501] = { 0, };

		scanf("%d", &length);
		scanf(" %s", str1);
		scanf(" %s", str2);
		
		int similarity = LCS(str1, str2,length);
		//printf("#%d %d\n", tc, similarity);
		
		printf("#%d %.2lf\n", tc, (double)similarity / length * 100);
	}
}