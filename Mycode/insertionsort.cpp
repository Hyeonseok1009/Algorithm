void InsertionSort(int * arr) {
	int i, j;
	int key;

	for (i = 1; i < 10; i++) {
		key = arr[i];

		for (j = i - 1; j >= 0; j--) {

			if (arr[j] > key) {       //key�� ���ڸ��� �ϳ��� ���鼭 ��
				arr[j + 1] = arr[j];  //���ڸ� ���� key������ ũ�ٸ� �ϳ��� �̵�
			}
			else {                  //key���� ���� ���� ������ break;
				break;
			}

		}

		arr[j + 1] = key;             //�� �ڸ��� key���� �ִ´�.
	}
}

void InsertionSort2(){
	int danji[10] = { 2,1,3,4,5,6,7,8,9,10 };
	for (int i = 1; i < 10; i++) {
		int idx = i;
		for (int j = i - 1; j >= 0; j--) {
			if (danji[idx] < danji[j]) {
				int tmp = danji[idx];
				danji[idx] = danji[j];
				danji[j] = tmp;
				idx--;
			}
			else break;
		}
	}
}