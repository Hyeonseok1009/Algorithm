#include <stdio.h>

// �������� ������ �ƴ϶� �ʼ���. �ݵ�� �Ű�Ἥ ����Ͽ����Ѵ�.

int number = 10;
int data[] = { 9,4,5,8,7,6,2,10,1,3};

void quicksort(int data[], int start, int end) {
	if (start >= end) { return; }

	int pivot = start;
	int left = start + 1;
	int right = end;
	int tmp = 0;
	while (left <= right) {			/* �����ϱ� ������*/
		//printf("A");
		while (left <= end && data[left] <= data[pivot]) { left++; 
		}
		while (right > start && data[right] >= data[pivot]) {
			right--;
		}
		if (left >right) {
			tmp = data[right];
			data[right] = data[pivot];
			data[pivot] = tmp;
		}
		else {
			tmp = data[left];
			data[left] = data[right];
			data[right] = tmp;
		}

		quicksort(data, start, right - 1);
		quicksort(data, right + 1, end);
	}
}

int main() {
	quicksort(data, 0, number - 1);
	for (int i = 0; i < number; i++) {
		printf("%d ", data[i]);
	}
	return 0;
}