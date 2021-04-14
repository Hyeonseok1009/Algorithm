//Inflearn #6 version C-language
#include <stdio.h>

int main() {
	char nums[10] = { 0, };
	int count = 0;
	int i = 0;

	char str[51] = { 0, };
	scanf("%s", str);

	while (*(str + i) != '\0') {
		if (*(str + i) >= '0' && *(str + i) <= '9') {
			nums[count++] = *(str + i);
		}
		i++;
	}
	
	int result = 0;
	for (int i = 0; i < count; i++) {
		result = result * 10 + (nums[i] - '0');
	}

	printf("%d\n", result);
	count = 0;
	for (int i = 1; i <= result; i++) {
		if (result % i == 0) {
			count++;
		}
	}
	printf("%d", count);
}