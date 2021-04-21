#include<stdio.h>
// 9 * 8  * 7 ���� ���ڸ� ������
// ��, ���⼭�� 
// �Ʒ��迭�� ���� 1�� �ʱ�ȭ �Ѵ�. 
// �־��� ���ڿ� strike �� ball ���θ� Ȯ���Ͽ� ��ġ�ϸ� �״�� �ΰ�, ��ġ���� ������ 0���� �ٲ۴�.
// 0�ΰ��� Ȯ���� �ʿ� ����.(�ι�° ����)



int cand[9 * 8 * 7 + 1][4] = { 0, };  // ù��°, �ι�°,����°, flag.

// �־��� ���ڿ� cand�迭�� �ε����� �����Ѵ�.
void check(int inp, int strike, int ball) {
	int str = 0; int ba = 0;

	int number[3] = { 0, };
	number[0] = inp % 10;
	inp = inp / 10;
	number[1] = inp % 10;
	number[2] = inp / 10;
	// �� ���θ� �Ǵ��Ѵ�. 9*8*7�� ��ȸ�ϸ鼭 ball���θ� üũ�Ѵ�.
	
	for (int j = 1; j <= 9 * 8 * 7; j++) {
		if (cand[j][3] != -1) {                      // ������ �������� ���������� ����.
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