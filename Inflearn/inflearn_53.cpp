/*#include<stdio.h>
#include<vector>
#include<algorithm>

using namespace std;
int main() {
	freopen("Text.txt", "r", stdin);
	for (int i = 0; i < 5; i++){
		int N, K;
		scanf("%d %d", &N, &K);

		vector<int> stack;
		int top = -1;
		while (N != 0){
			stack.push_back(N%K);
			N /= K;
			top++;
		}

		while (top != -1){
			printf("%X", stack[top--]);
		}
		printf("\n");
		
	}
	return 0;
}*/

#include<stdio.h>
#include<stack>
#include<algorithm>

using namespace std;
int main() {
	freopen("Text.txt", "r", stdin);
	for (int i = 0; i < 5; i++){
		int N, K;
		scanf("%d %d", &N, &K);

		stack<int> s;
		while (N != 0){
			s.push(N%K);
			N /= K;
		}

		while (!s.empty()){
			printf("%X", s.top());
			s.pop();
		}
		printf("\n");

	}
	return 0;
}