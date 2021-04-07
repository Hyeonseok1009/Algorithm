//Inflearn #33
//계수정렬(내림차순)
#include <stdio.h>

int main() {
	int N;
	scanf("%d", &N);

	int nums[101] = { 0, }; // 0점 ~ 100점까지

	int score = 0;
	for (int i = 0; i < N;i++) {
		scanf("%d", &score);
		nums[score]++;
	}

	int rank=0;
	int j;
	for (j = 100; j >= 0;j--) {
		if (nums[j] != 0) rank++;

		if (rank == 3) break;

	}

	printf("%d", j);

	return 0;
}