// 1. 인풋 전부 받아온다.
// 2. 수열이 유지되면 count++, 아니면 count 0; 그리고 max값과비교.

#include<iostream>
#include<vector>

using namespace std;
int main() {
	freopen("Text.txt", "r", stdin);
	int N;
	cin >> N;

	vector<int> a(N);
	for (int i = 0; i < N; i++) {
		scanf("%d", &a[i]);
	}
	int max = 0, count = 1;
	for (int i = 1; i < N; i++) {
		if (a[i - 1] <= a[i]) {
			count++;
			if (max < count) max = count;
		}
		else count = 1;
	}

	printf("%d", max);
	
	return 0;
}