//Inflearn 16¹ø¹®Ç×
#include <stdio.h>

int main() {
	char str1[101];
	char str2[101];
	scanf("%s %s", str1, str2);

	printf("%s ", str1);
	printf("%s ", str2);

	int leng = 0;
	char arr1[123] = { 0, };
	char arr2[123] = { 0, };
	while (str1[leng] != '\0') {
		arr1[str1[leng]]++;
		arr2[str2[leng]]++;
		leng++;
	}
	int same = 1;

	for (int i = 65; i <= 122; i++) {
		if (arr1[i] != arr2[i]) {
			same = 0;
			break;
		}
		printf("%d ", arr1[i]);
		printf("%d ", arr2[i]);
	}

	if (same) {
		printf("YES");
	}
	else {
		printf("NO");
	}
	return 0;
}