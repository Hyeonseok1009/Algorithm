#include<cstring>
#include<vector>
#include<algorithm>	

using namespace std;
int main() {
	freopen("Text.txt", "rt", stdin);
	for (int tc = 0; tc < 5; tc++) {
		int S, N;
		scanf("%d %d", &S, &N);
		vector<int> cache(S);

		char check[1001] = { 0, };
		int count = 0;
		for (int n = 0; n < N; n++) {
			int query;
			scanf("%d", &query);

			if (check[query] == 0) {// miss
				check[query] = 1;
				if (count >= S) {
					check[cache[0]] = 0;
					for (int i = 1; i < S; i++) {
						cache[i - 1] = cache[i];
					}
					count = S - 1;
				}
				cache[count++] = query;
			}
			else {						//hit
				int tmp = 0;
				for (tmp = 0; tmp < count; tmp++) {
					if (cache[tmp] == query) break;
				}
				for (int i = tmp + 1; i < count; i++) {
					cache[i - 1] = cache[i];
				}
				cache[count - 1] = query;
			}
			/*for (int i = 0; i < S; i++) {
				printf("%d ", cache[i]);
			}
			printf("\n");*/
		}

		for (int i = S - 1; i >= 0; i--) {
			printf("%d ", cache[i]);
		}
		printf("\n");
	}

	return 0;
}