//inflearn 31
#include <cstdio>
char str[9];
char num1[3];
char num2[3];
int num1_cnt, num2_cnt;
int main() {
	scanf("%s", str);

	int pointer = 1;
	while (str[pointer] != 'H') {
		num1[num1_cnt++] = str[pointer++];
	}
	pointer++;
	while (str[pointer] != '\0') {
		num2[num2_cnt++] = str[pointer++];
	}
	
	int a = 0; 
	int b = 0;
	for (int i = 0; i < num1_cnt; i++) {
		a = a * 10 + num1[i] - '0';
	}

	for (int i = 0; i < num2_cnt; i++) {
		b = b * 10 + num2[i] - '0';
	}

	if (a == 0) a = 1;
	if (b == 0) b = 1;
	printf("%d\n", a * 12 + b * 1);
	return 0;
}