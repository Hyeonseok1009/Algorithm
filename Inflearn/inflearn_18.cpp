//Inflearn 18
// max��
// M�Ʒ��̸�  count 0���� �ʱ�ȭ
// M���� ���̸� count �ø���, max�� �� 

#include <stdio.h>

int main() {
	freopen("Text.txt", "r", stdin);
	for (int i = 0; i < 4; i++) {
		int N, M;
		scanf("%d %d", &N, &M);

		int max = -1, count = 0, value;
		for (int i = 1; i <= N; i++) {
			scanf("%d", &value);

			if (value > M) {
				count++;
				if (max < count) max = count;
			}
			else {
				count = 0;
			}
		}

		printf("%d\n", max);
	}
}
