// 1. 인풋 전부 받아온다.
// 2. 각각 비교하여 A의 스코어, B 의 스코어를 컨트롤한다.
// 3. 최종승자를 기록한다. 
// 4. 만약 최종 승자가 없다면, 무승부 인 것이다.

#include<stdio.h>

int A[10], B[10], A_score, B_score, winner;
int main() {
	for (int i = 0; i < 20; i++) {
		if (i < 10) {
			scanf("%d", &A[i]);
		}
		else {
			scanf("%d", &B[i - 10]);
		}
	}
	for (int i = 0; i < 10; i++) {
		if (A[i] > B[i]) {
			A_score += 3;
			winner = 1;
		}
		else if (A[i] < B[i]) {
			B_score += 3;
			winner = 2;
		}
		else {
			A_score += 1;
			B_score += 1;
		}
	}

	printf("%d %d\n", A_score, B_score);
	if (winner == 1) {
		printf("A\n");
	}
	else if (winner == 2) {
		printf("B\n");
	}
	else if (winner == 0) {
		printf("D\n");
	}
	return 0;
}