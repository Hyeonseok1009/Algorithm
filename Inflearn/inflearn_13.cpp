#include <stdio.h>

int main() {
	for (int k = 0; k < 5; k++) {
		int count[10] = { 0, };

		char nums[101];
		scanf("%s", nums);

		int length = 0;
		while (nums[length] != '\0') {
			count[nums[length] - '0']++;
			length++;
		}

		int i, max = 0;
		for (i = 0; i <= 9; i++) {
			if (count[i] >= count[max]) {
				max = i;
			}
		}

		printf("%d\n", max);
	}
}