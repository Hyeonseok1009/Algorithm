#include <stdio.h>
#include <algorithm>
#include <vector>

int main() {
	int N; 
	scanf("%d", &N);
	int count = 0;
	for (int i = 2; i <= N / 2; i++){
		int sum = 0;
		int j = 1;
		for (j = 1; j <= i; j++){
			sum += j;
		}
		j--;
		if ( (N - sum) >= 0 && (N - sum) % j == 0 ){
			int k = 1;
			for (k = 1; k <= i - 1; k++){
				printf("%d + ", k + (((N - sum) / j)));
			}
			printf("%d = %d\n", k + (((N - sum) / j)), N);
			count++;
		}
	}
	printf("%d\n", count);
	return 0;

}