//inflearn 17¹ø

#include <stdio.h>

int main() {
	int N;
	scanf("%d", &N);

	int number, answer, my_answer;
	for (int i = 0; i < N; i++) {
		scanf("%d %d", &number, &answer);

		my_answer = number * (number + 1) / 2;
		if (answer == my_answer) {
			printf("YES\n");
		}
		else
			printf("NO\n");
	}

	return 0;
}
