#include <stdio.h>
#define swap(a, b) { int tmp; tmp = a; a = b; b = tmp; }
int TC;
int dist[1001][1001] = { 0, };
int D[1001] = { 0, };
int U[1001] = { 0, };
int V;


int extractMin() {
	int minVertex = 0;
	int minDistance = 9999;
	for (int i = 1; i <= V; i++) {
		if (U[i] == false && minDistance > D[i]) {
			minVertex = i;
			minDistance = D[i];
		}
	}
	return minVertex;
}

//Heap 
const int HEAP_SIZE = 1001;
int heap[1001] = { 0, };
int heapCount = 0;

void push(int value) {
	heap[++heapCount] = value;

	int child = heapCount;
	int parent = child >> 1;

	// Up Heap
	while (parent > 0 && D[heap[parent]] > D[heap[child]]) {
		swap(heap[parent], heap[child]);

		child = parent;
		parent = child >> 1;
	}
}

int pop() {
	int parent = 1;
	int ret = heap[parent];

	heap[parent] = heap[heapCount];
	heap[heapCount--] = 0;

	int child = parent << 1;	   // left child
	if (child + 1 <= heapCount) {  // if right child exists
		child = (D[heap[child]] < D[heap[child + 1]]) ? child : child + 1;
	}

	// Down Heap
	while (child <= heapCount && D[heap[parent]] > D[heap[child]]) {
		swap(heap[parent], heap[child]);

		parent = child;
		child = parent << 1;

		if (child + 1 <= heapCount) {  // if right child exists
			child = (D[heap[child]] < D[heap[child + 1]]) ? child : child + 1;
		}
	}

	return ret;
}

int dijkstra(int s) {
	for (int i = 1; i <= V; i++) {
		D[i] = 0;
		U[i] = 0;
	}

	U[s] = 1;
	for (int v = 1; v <= V; v++) {
		D[v] = dist[s][v];
	}
	D[s] = 0;
	for (int i = 1; i <= V; i++) {
		int w = extractMin();
		U[w] = 1;
		for (int v = 1; v <= V; v++) {
			if (!U[v]) {
				if ((dist[w][v] != 9999) && D[v] > D[w] + dist[w][v]) {
					D[v] = D[w] + dist[w][v];
				}
			}
		}
	}
	// 다익스트라 합 구해서 출력
	int result = 0;
	for (int i = 1; i <= V; i++) {
		result += D[i];
	}

	return result;
}

int dijkstra_pq(int s) {
	
	for (int i = 1; i <= V; i++) {
		D[i] = 9999;
		U[i] = 0;
	}

	D[s] = 0;
	push(s);

	while (heapCount > 0) {		// !pq.empty()
		int w = pop();

		if (U[w] == false) {
			U[w] = true;

			for (int v = 1; v <= V; v++) {
				// w와 v가 연결되어 있고, s에서 가는 것보다 w 경우하는게 더 짧으면
				if (dist[w][v] != 9999 && D[v] > D[w] + dist[w][v]) {
					D[v] = D[w] + dist[w][v];
					push(v);
				}
			}
		}
	}

	int result = 0;
	for (int i = 1; i <= V; i++) {
		result += D[i];
	}

	return result;
}


int main() {
	freopen("input.txt", "r", stdin);

	scanf("%d", &TC);
	for (int tc = 1; tc <= TC; tc++) {
		scanf("%d", &V);

		int i, j;
		for (i = 1; i <= V; i++) {
			for (j = 1; j <= V; j++) {
				scanf("%d", &dist[i][j]);
				if (i != j && dist[i][j] == 0) {
					dist[i][j] = 9999;
				}
			}
			D[i] = 9999;
			U[i] = false;
		}
		// 입력받기 완료
		// 각각의 노드에 대해서 다익스트라 적용 후 합 구하기
		int res = 9999;
		int tmp = 0;
		int k; 
		for (k = 1; k <= V; k++) {
			tmp = dijkstra_pq(k);
			if (tmp < res) res = tmp;
		}
		printf("#%d %d\n", tc, res);

		for (i = 1; i <= V; i++) {
			for (j = 1; j <= V; j++) {
				dist[i][j] = 0;
			}
		}
	}
	return 0;
}