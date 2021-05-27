#include <stdio.h>
#include <algorithm>
#include <vector>

#define _CRT_SECURE_NO_WARNINGS
using namespace std;
int main(){
	freopen("Text.txt", "r", stdin);
	int N, M;
	scanf("%d %d", &N, &M);
	vector<int> a(N+1);

	for (int i = 1; i <= N; i++){
		scanf("%d", &a[i]);
	}

	sort(a.begin() + 1, a.end());
	for (int i = 1; i <= N; i++){
		printf("%d ", a[i]);
	}
	printf("\n");

	
	int start = 1;
	int end = N;
	int middle = 0;
	while (start <= end){
		middle = (start + end) / 2;

		if (a[middle] > M){
			end = middle - 1;
		}
		else if (a[middle] < M){
			start = middle + 1;
		}
		else if (a[middle] == M){
			break;
		}
	}
	printf("%d\n", middle);


}