//inflearn 8
//�Է� �޾� �µ�,ó������. �� ���ڸ� �˼� �־�� �ϹǷ�.
//1. stack 

#include <stdio.h>

int main() {
	freopen("Text.txt", "r", stdin);
	for (int i = 0; i < 5; i++) {
		char stack[31] = { 0, };
		scanf("%s", stack);
		printf("%s", stack);

		char chr = 0;
		int top = 0;
		int ptr = 0;
		while (stack[ptr] != '\0') {
			chr = stack[ptr];

			if (chr == '(') {
				top++;
			}
			else {
				if (top > 0) {
					top--;
				}
				else {
					top = -1;
					break;
				}
			}
			ptr++;
		}

		//printf("%d\n", top);
		if (top == 0) {
			printf("YES\n");
		}
		else if (top != 0) {
			printf("NO\n");
		}
	}
}