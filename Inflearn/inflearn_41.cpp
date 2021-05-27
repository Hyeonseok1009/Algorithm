#include <stdio.h>
#include <algorithm>
#include <vector>

int main() {
	int N; 
	scanf("%d", &N);
	int sum;
	int count = 0;
	for (int i = 1; i <= N / 2; i++){
		sum = i;
		int start = i+1;
		int flag = 0;
		while (sum != N){
			sum = sum + start;
			if (sum > N){
				break;
			}
			else if (sum == N){
				for (int j = i; j <= start-1; j++){
					printf("%d + ", j);
				}
				flag = 1; count++;
			}
			else if (sum < N){
				start++;
			}
		}
		if(flag) printf("%d = %d\n", start, N);
	}
	printf("%d\n", count);
	return 0;

}