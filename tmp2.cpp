//Inflearn 29 
//2021-04-26

#include <stdio.h>

int N;	
int arr[1000];
int main() {
	scanf("%d", &N);
	int count = 0;
	for (int i = 1; i <= N; i++) {
		int tmp = i;

		if (tmp % 10 == 3) count++;
		else tmp /= 10;
	}

	printf("%d\n", min);
}