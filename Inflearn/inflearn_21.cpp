// 1. ��ǲ ���� �޾ƿ´�.
// 2. ���� ���Ͽ� A�� ���ھ�, B �� ���ھ ��Ʈ���Ѵ�.
// 3. �������ڸ� ����Ѵ�. 
// 4. ���� ���� ���ڰ� ���ٸ�, ���º� �� ���̴�.

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