#include<stdio.h>

int postorder(int node, int arr[][4]) {
	
	if (arr[node][3]) {
		double left = postorder(arr[node][1], arr);
		double right = postorder(arr[node][2], arr);
		if (arr[node][0] == '+') {
			//printf("%d : %lf %lf %c\n", node, left, right, arr[node][0]);
			return left + right;
		}
		else if (arr[node][0] == '-') {
			//printf("%d : %lf %lf %c\n", node, left, right, arr[node][0]);
			return left - right;
		}
		else if (arr[node][0] == '*') {
		//	printf("%d : %lf %lf %c\n", node, left, right, arr[node][0]);
			return left * right;
		}
		else if (arr[node][0] == '/') {
		//	printf("%d : %lf %lf %c\n", node, left, right, arr[node][0]);
			return left / right;
		}
	}
	return arr[node][0];
}




int main() {
	freopen("Text.txt", "r", stdin);
	int V;
	for (int tc = 1; tc <=10; tc++) {
		scanf("%d", &V);
		int arr[1001][4] = { 0, };
		int vtnum;
		for (int i = 0; i < V; i++) {
			scanf("%d", &vtnum);
			char num = 0;
			scanf(" %c", &num);

			int leftchild = 0;
			int rightchild = 0;
			if (num == '+' || num == '-' || num == '*' || num == '/') {
				{
					scanf("%d %d", &leftchild, &rightchild);
					arr[vtnum][0] = num;
					arr[vtnum][1] = leftchild;
					arr[vtnum][2] = rightchild;
					arr[vtnum][3] = 1; //연산자인경우 기호 1로 표기.
				}
				//printf("A : vtnum: %d, %c %d %d %d\n", vtnum, arr[vtnum][0], arr[vtnum][1], arr[vtnum][2], arr[vtnum][3]);

			}
			else {
				int result = num - '0';
				char tmp = 0;
				scanf("%c", &tmp);
				while (tmp != '\n') {
					result = result * 10 + tmp - '0';
					scanf("%c", &tmp);
				}
				arr[vtnum][0] = result;
				//printf("B : vtnum: %d, %d %d %d %d\n", vtnum, arr[vtnum][0], arr[vtnum][1], arr[vtnum][2], arr[vtnum][3]);
			}
		}
		int answer = (int)postorder(1, arr);
		printf("#%d %d\n", tc,answer);
	}
	return 0;
}