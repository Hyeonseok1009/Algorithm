#include <stdio.h>

int N;
int prime[1000] = { 0, };
int pr_count=0;
int bindo[1000];

int is_Prime(int N) {
	bool prime = 1;
	for (int i = 2; i*i <= N; i++) {
		if (N%i == 0) {
			prime = 0;
			break;
		}
	}
	return prime;
}

void make_prime(int N) {
	for (int i = 2; i <= N; i++) {
		if (is_Prime(i)) {
			prime[pr_count++] = i;
		}
	}
}

int main() {
	//1. 주어진 값보다 작은 소수들을 담은 배열을 만든다.
	//2. 그것과 똑같은 size의 배열을 만든다.
	//3. 주어진 값을 1씩 줄여가며, 소수들로 나누고, 나누어떨어지면 2번배열+1 한다.
	 // 	안나눠지면 값 유지. 
	//4. 전역에서 놀자.
	scanf("%d", &N);
	make_prime(N);
	for (int i = 0; i < pr_count; i++) {
		printf("%d ", prime[i]);
	}
	return 0;

}