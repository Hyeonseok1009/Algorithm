#include<stdio.h>
int main() {
	freopen("Text.txt", "rt", stdin);
	for (int k = 0; k < 1; k++) {
		int N;
		scanf("%d", &N);
		int arr[100];
		for (int i = 0; i < N; i++) {
			scanf("%d", &arr[i]);
		}
		for (int i = 1; i < N; i++) {
			for (int j = i; j > 0; j--) {
				if (arr[j-1] > arr[j]) {
					int tmp = arr[j];
					arr[j] = arr[j - 1];
					arr[j - 1] = tmp;
				}
				else {
					break;
				}
			}
		}
		for (int i = 0; i < N; i++) {
			printf("%d ", arr[i]);
		}
		printf("\n");
	}
	return 0;
}