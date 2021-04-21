//#1871 줄세우기

#include <stdio.h>
#include <stdlib.h>

int N;
int nums[201] = { 0, };

int findLis(int length);


int main() {
	//freopen("input.txt", "r", stdin);
	scanf("%d", &N);

	for (int i = 1; i <= N; i++) {
		scanf("%d", &nums[i]);
	}

	int result = N - findLis(N);
	printf("%d", result);
}

int findLis(int length) {
	int Lis[201] = { 0, };
	int Lis_len = 0;
	for (int i = 1; i <= length; i++) {
		Lis[i] = 1;
		for (int j = 1; j < i; j++) {
			if (Lis[j] + 1 > Lis[i] && nums[j] < nums[i]) {
				Lis[i] = Lis[j] + 1;
			}
		}
		if (Lis_len < Lis[i]) {
			Lis_len = Lis[i];
		}
	}

	int max = -1;

	for (int i = 1; i <= length; i++) {
		//printf("%d ", Lis[i]);
		if (max <= Lis[i]) max = Lis[i];
	}

	return Lis_len;
}