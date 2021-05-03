#include <stdio.h>

int D[301];

int main() {
	int TC;
	scanf("%d", &TC);

	D[2] = 2;
	D[3] = 4;
	D[4] = 10;
	for (int tc = 0; tc < TC; tc++) {
		int mari;
		scanf("%d", &mari);
		
		for (int i = 5; i <= mari; i++) {
			D[i] = (D[i - 1] * 2) %1000000007;
		}

		printf("%d\n", D[mari]);

		for (int i = 5; i <= mari; i++) {
			D[i] = 0;
		}

	}
	return 0;
}