//inflearn 8
//입력 받아 온뒤,처리하자. 끝 문자를 알수 있어야 하므로.
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