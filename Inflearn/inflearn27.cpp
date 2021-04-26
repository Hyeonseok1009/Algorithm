//Inflearn 27 
//2021-04-26

#include <stdio.h>

int N;	
int arr[1000];
int main() {
	scanf("%d", &N);

	for (int i = N; i >= 2; i--) {
		int tmp = i;
		while (tmp != 1) {
			int tmp2 = tmp;
			for (int j = 2; j <= tmp2; j++) {
				while (tmp%j == 0) {
					arr[j]++;
					tmp /= j;
				}
			}
		}
	}
	printf("%d! = ", N);
	for (int j = 1; j <= N; j++) {
		if (arr[j] != 0) {
			printf("%d ", arr[j]);
		}
	}
}