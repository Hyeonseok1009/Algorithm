//Inflearn #5 version C-language
#include <stdio.h>

char nums[15];

int main() {
	scanf("%s", nums);
	char standard;
	standard = nums[7];
	char sex = 0;
	int age;
	switch (standard) {
	case '1' :
		age = (nums[0] - '0') * 10 + (nums[1] - '0') + 1900;
		sex = 'M';
		break;
	case '2':
		age = (nums[0] - '0') * 10 + (nums[1] - '0') + 1900;
		sex = 'W';
		break;
	case '3':
		age = (nums[0] - '0') * 10 + (nums[1] - '0') + 2000;
		sex = 'M';
		break;
	case '4': 
		age = (nums[0] - '0') * 10 + (nums[1] - '0') + 2000;
		sex = 'W';
		break;
	}

	printf("%d %c", 2019-age+1, sex);

	return 0;
}
