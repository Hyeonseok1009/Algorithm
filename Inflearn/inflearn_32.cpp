//inflearn 32 선택정렬
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	freopen("Text.txt", "r", stdin);
		int N;
		scanf("%d", &N);
		vector<int> vec(N);
		for (int i = 0; i < N; i++) {
			scanf("%d", &vec[i]);
		}

		for (int i = 0; i < N - 1; i++) {
			int minidx = i;
			for (int j = i + 1; j < N; j++) {
				if (vec[minidx] > vec[j]) minidx = j;
			}
			int tmp = vec[i];
			vec[i] = vec[minidx];
			vec[minidx] = tmp;
		}
		for (int i = 0; i < N; i++) {
			printf("%d ", vec[i]);
		}
	return 0;
}
