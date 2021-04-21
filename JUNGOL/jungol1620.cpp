#include <stdio.h>

int main() {
	freopen("Text.txt", "rt", stdin);
	char phone[101] = { 0, };
	int plus = 0;
	int dumy = 0;

	scanf("%s %d %d", phone, &plus, &dumy);

	int hipeun = 0;
	int length = 0;
	int index = 0;
	int flag = 1;
	int check = 0;
	while (phone[length] != '\0') {
		check++;
		if (dumy == 1) {
			flag = 0;
			index = 0;
		}
		if (phone[length] == '-') {
			//printf("%d ", check);
			check = 0;
			//printf("%d ", check);
			hipeun++;
			if (hipeun == dumy-1) {
				flag = 0;
				index = length + 1;
			}
		}
		if (check > 4) {
			//printf("%d ", check);
			flag = 1;
			break;
		}
		//printf("%d ", check);
		length++;
	}

	if (flag) {
		printf("INPUT ERROR!\n");
		return 0;
	}
	flag = 1;
	int count = 1;
	int num = 0;
	while (phone[index] != '-' && phone[index] != '\0') {
		if (count > 4) {
			printf("INPUT ERROR!\n");
			return 0;
		}
		num = num * 10 + (phone[index] - '0');
		count++;
		index++;
	}

	int answer[4] = { 0, };
	
	for (int i = 3; i >= 0; i--) {
		answer[i] = ((num % 10) + plus) % 10;
		num /= 10;
	}

	for (int i = 0; i < 4; i++) {
		printf("%d", answer[i]);
	}
	printf("\n");

	return 0;
}