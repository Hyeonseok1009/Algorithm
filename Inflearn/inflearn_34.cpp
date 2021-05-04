#include <stdio.h>

int main() {
	freopen("Text.txt", "rt", stdin);
	int N;
	scanf("%d", &N);
	int arr[100];
	for (int n = 0; n < 100; n++) {
		scanf("%d", &arr[n]);
	}

	for (int i = 0; i < N-1; i++) {
		for (int j = 0; j < N -1 - i; j++) {
			if (arr[j] > arr[j + 1]) {
				int tmp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = tmp;
			}
		}
	}
	for (int i = 0; i < N; i++) {
		printf("%d ", arr[i]);
	}
	return 0;
}