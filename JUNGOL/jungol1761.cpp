#include<stdio.h>
// 9 * 8  * 7 개의 숫자를 비교하자
// 단, 여기서는 
// 아래배열을 각각 1로 초기화 한다. 
// 주어진 숫자와 strike 및 ball 여부를 확인하여 일치하면 그대로 두고, 일치하지 않으면 0으로 바꾼다.
// 0인것은 확인할 필요 없다.(두번째 부터)



int cand[9 * 8 * 7 + 1][4] = { 0, };  // 첫번째, 두번째,세번째, flag.

// 주어진 숫자와 cand배열의 인덱스를 대조한다.
void check(int inp, int strike, int ball) {
	int str = 0; int ba = 0;

	int number[3] = { 0, };
	number[0] = inp % 10;
	inp = inp / 10;
	number[1] = inp % 10;
	number[2] = inp / 10;
	// 볼 여부를 판단한다. 9*8*7번 순회하면서 ball여부를 체크한다.
	
	for (int j = 1; j <= 9 * 8 * 7; j++) {
		if (cand[j][3] != -1) {                      // 이전에 거짓으로 판정난것은 제외.
			for (int i = 0; i < 3; i++) {
				for (int k = 0; k < 3; k++) {
					if (cand[j][i] == number[k]) {
						if (i == k) str++;
						else ba++;
						break;
					}
				}
			}


			if (str == strike && ba == ball) {
				cand[j][3] = 1;
			}
			else cand[j][3] = -1;
			str = 0; ba = 0;
		}
	}
}
int main() {
	freopen("Text.txt", "rt", stdin);
	int N;
	scanf("%d", &N);

	int count = 0;
	for (int i = 1; i <= 9; i++) {
		for (int j = 1; j <= 9; j++) {
			if (j != i) {
				for (int k = 1; k <= 9; k++) {
					if (k != j && k != i) {
						count++;
						cand[count][0] = i;
						cand[count][1] = j;
						cand[count][2] = k;
					}
				}
			}
			
		}
	}
	/*for (int i = 1; i <= 9 * 8 * 7; i++) {
		printf("nums[%d] %d %d %d\n", i, nums[i][0], nums[i][1], nums[i][2]);
	}*/
	int input1, strike, ball;
	for (int i = 0; i < N; i++) {
		scanf("%d %d %d", &input1, &strike, &ball);
		check(input1, strike, ball);
	}
	int answer = 0;
	for (int i = 1; i <= 9 * 8 * 7; i++) {
		if (cand[i][3] == 1) {
			//printf("%d%d%d\n", cand[i][0], cand[i][1], cand[i][2]);
			answer++;
		}
	}

	printf("%d\n", answer);
	
	return 0;
}