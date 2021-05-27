#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;
int main() {
	freopen("Text.txt", "r", stdin);
	int N, M;
	scanf("%d %d", &N, &M);
	vector<int> arr(N + 1);
	for (int i = 1; i < N + 1; i++){
		scanf("%d", &arr[i]);
	}
	sort(arr.begin() + 1, arr.end());

	int start = 1;
	int end = N;
	int answer = -1;
	while (start <= end){
		int middle = (start + end) / 2;

		if (arr[middle] > M){
			end = middle - 1;
		}
		else if (arr[middle] < M){
			start = middle + 1;
		}
		else if (arr[middle] == M){
			answer = middle;
			break;
		}
	}

	printf("%d\n", answer);
}