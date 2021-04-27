#include <stdio.h>

int N;

int main() {
	scanf("%d", &N);
	int count = 0;

	for (int i = N; i >= 3; i--) {
		int tmp = i;
		while (tmp != 0) {
			if (tmp % 10 == 3) count++;
			tmp /= 10;
		}
	}
	printf("%d", count);
}