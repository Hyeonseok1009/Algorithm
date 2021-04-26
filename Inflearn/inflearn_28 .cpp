//Inflearn 28 
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
	int min = arr[5];
	if (arr[5] > arr[2]) min = arr[2];

	printf("%d\n", min);
}