#include <stdio.h>

int divider(int n){
	int tmp = n;
	if (n % 2 == 0){
		tmp = divider(n / 2);
	}
	else if (n % 3 == 0){
		tmp = divider(n / 3);
	}
	else if (n % 5 == 0){
		tmp = divider(n / 5);
	}
	else {
		return tmp;
	}
}

int main(){
	freopen("Text.txt", "r", stdin);
	for (int i = 1; i <= 5; i++){
		int N;
		scanf("%d", &N);

		int ans = 0;
		int cnt = 0;
		while (cnt != N){
			ans++;
			if (divider(ans) == 1){
				cnt++;
			}
		}
		printf("%d\n", ans);
	}
}