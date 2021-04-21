void InsertionSort(int * arr) {
	int i, j;
	int key;

	for (i = 1; i < 10; i++) {
		key = arr[i];

		for (j = i - 1; j >= 0; j--) {

			if (arr[j] > key) {       //key의 앞자리를 하나씩 보면서 비교
				arr[j + 1] = arr[j];  //앞자리 값이 key값보다 크다면 하나씩 이동
			}
			else {                  //key보다 작은 값이 나오면 break;
				break;
			}

		}

		arr[j + 1] = key;             //그 자리에 key값을 넣는다.
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