#include <stdio.h>

#define MAX 101

int N, M;
int arr[MAX][MAX] = { 0, }; // �������.
int D[MAX] = { 0, }; // �Ÿ�
bool U[MAX] = { false }; 
int dijkstra(int n); // ��������
int extractMin();

int parent[MAX] = { 0, };
int main() {
	freopen("Text.txt", "rt", stdin);
	scanf("%d %d", &N, &M);

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			scanf("%d", &arr[i][j]);
			if (i != j && arr[i][j] == 0) {
				arr[i][j] = 987654321;
			}
		}
	}
	// parent�迭�� �������Ѿ��� �� ����.
	for (int i = 1; i <= N;i++) {
		parent[i] = 1;
	}



	int answer = dijkstra(M);
	printf("%d\n", answer);
	int answerarr[MAX] = { 0, };
	int tmp = M;
	int count = 0;
	while (tmp != 1) {
		answerarr[count++] = tmp;
		tmp = parent[tmp];
		//printf("%d ", tmp);
	}
	answerarr[count++] = 1;
	for (int j = count - 1; j >= 0; j--) {
		printf("%d ", answerarr[j]);
	}
	printf("\n");
}

int extractMin() {
	int minVertex = 0;
	int minDistance = 987654321;
	for (int i = 1; i <= N; i++) {
		if (U[i] == false && minDistance > D[i]) {
			minVertex = i;
			minDistance = D[i];
		}
	}
	return minVertex;
}
int dijkstra(int n) {
	int s = 1;
	U[s] = true;

	for (int v = 1; v <= N; v++) {
		D[v] = arr[s][v];
	}

	D[s] = 0;

	for (int i = 1; i <= N; i++) {
		int w = extractMin(); 
		U[w] = true;
		// ���� ���� ���� ������ ���ϰ�, �װͿ� ������ �������� �Ÿ�(D)�� ��ȭ��Ų��. 
		for (int v = 1; v <= N; v++) {
			if (!U[v]) {
				if (D[v] > D[w] + arr[w][v]) {
					D[v] = D[w] + arr[w][v];
					parent[v] = w;
				}
			}
		}
	}
	return D[M];
}