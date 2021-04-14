#include <cstdio>

bool isPrime(int x) {
	bool result = true;

	for (int i = 2; i*i < x; i++) {
		if (x%i == 0) {
			result = false;
			break;
		}
	}
	return result;
}

int reverse(int x) {
	int res = 0;
	int tmp = 0;

	while (x > 0) {
		tmp = x % 10;
		res = res * 10 + tmp;
		x /= 10;
	}

	return res;
}

int main() {
	//for (int k = 0; k < 5; k++) {
		int N;
		scanf("%d", &N);


		int num = 0;
		for (int i = 0; i < N; i++) {
			scanf("%d", &num);
			if (isPrime(reverse(num))) {
				printf("%d ", reverse(num));
			}
		}
	//}

	return 0;
}