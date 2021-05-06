//Inflearn 38 : Inversion Sequence
#include <stdio.h>

int main() {
	freopen("Text.txt", "rt", stdin);
	int N;
	scanf("%d", &N);
	int a[101] = { 0, }; int b[101] = { 0, };
	for (int i = 1; i <= N; i++) {
		scanf("%d",&a[i]);
	}
	for (int i = 1; i <= N; i++) {
		int count = 0;
		int answer = 1;
		for (int j = 1; j <= N; j++) {
			if (b[j] == 0) count++;
			if (count == a[i]) answer = j+1;
		}
		/*int j = 1;
		while (count != a[i]) {
			if (b[j] == 0) {
				count++;
			}
			j++;
		}*/
		b[answer] = i;
	}

	for (int i = 1; i <= N; i++) {
		printf("%d ", b[i]);
	}
}