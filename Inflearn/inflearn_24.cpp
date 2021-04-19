//Inflearn 24

#include <stdio.h>
#include <vector>
#define abs(a) ((a>0) ? (a) : (-a))

int main() {
	freopen("Text.txt", "r", stdin);
	int N;
	scanf("%d", &N); 
	//printf("%d \n", N);
	int nums[101] = { 0, };
	int jolly[101] = { 0, };
	for (int i = 0; i < N; i++) {
		scanf("%d",&nums[i]);
	}

	for (int i = 0; i < N - 1; i++) {
		int tmp = nums[i] - nums[i + 1];
		//printf("%d ", abs(tmp));
		if (abs(tmp) <= N - 1) {
			jolly[abs(tmp)]++;
		}

		//printf("%d ", jolly[abs(tmp)]);
	}
	int flag = 0;
	for (int i = 1; i < N ; i++) {
		//printf("%d ", jolly[i]);
		if (jolly[i] != 1) flag = 1;
	}
	if (flag) printf("NO\n");
	else printf("YES\n");

	return 0;
}