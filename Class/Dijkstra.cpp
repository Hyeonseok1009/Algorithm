#include <iostream>
using namespace std;

const int VERTEX = 10;
const int INFINITI = 987654321;

int A[VERTEX][VERTEX] = { 0 }; //인접행렬
int D[VERTEX] = { 0 };		//거리 갱신
bool U[VERTEX] = { false };  //선택정점 집합
int V; //정점의 총수

int extractMin() {
	int minVertex = 0;
	int minDistance = INFINITI;

	for (int i = 1; i <= V; i++) {
		if (U[i] == false && minDistance > D[i]) {
			minVertex = i;
			minDistance = D[i];
		}
	}
	return minVertex;
}

int dijkstra(int s) {
	U[s] = true;

	for (int v = 1; v <= V; v++) {
		D[v] = A[s][v];
	}
	D[s] = 0;

	for (int i = 1; i <= V; i++) {
		int w = extractMin();
		U[w] = true;
		for (int v = 1; v <= V; v++) {
			if (!U[v]) {   // 방문한체크한 노드는 다시 쳐다볼 필요가 없기 때문. //https://yabmoons.tistory.com/364 // 하단에 설명 참조
				if (A[w][v] != INFINITI && D[v] > D[w] + A[w][v]) {
					D[v] = D[w] + A[w][v];
				}
			}
		}
	}
	return D[V];  // 처음 넣은 정점과 마지막 넣은 정점의 거리를 리턴( 안그래도 )
}

void printDistance() {
	for (int i = 0; i < V; i++) {
		printf("%3c", 'A' + i);
	}
	printf("\n");

	for (int i = 1; i <= V; i++) {
		printf("%3d", D[i]);
	}

	printf("\n");
}


int main() {
	freopen("Dijkstra.txt", "r", stdin);
	cin >> V;

	for (int i = 1; i <= V; i++) {
		for (int j = 1; j <= V; j++) {
			cin >> A[i][j];

			if (i != j && A[i][j] == 0) {
				A[i][j] = INFINITI;
			}
		}
	}
	int distance = dijkstra(1);

	cout << "dijkstra : " << distance << endl;
	printDistance();

	return 0;
}
