#include <iostream>	

using namespace std;

const int TREE_SIZE = 50;

int tree[TREE_SIZE] = { 0, };
int V;
int E;

void preoder(int node) {
	if (node < 1 || node >= TREE_SIZE) return;
	if(tree[node] == 0) return;

	cout << tree[node] << " ";    // V
	preoder(node << 1);			 //L
	preoder(node << 1 | 1);

}

void inoder(int node) {
	if (node < 1 || node >= TREE_SIZE) return;
	if (tree[node] == 0) return;

	inoder(node << 1);			 //L
	cout << tree[node] << " ";    // V
	inoder(node << 1 | 1);
}

void postoder(int node) {
	if (node < 1 || node >= TREE_SIZE) return;
	if (tree[node] == 0) return;

	postoder(node << 1);			 //L
	postoder(node << 1 | 1);
	cout << tree[node] << " ";    // V
}

void leveloder(int node) {
	int pow2[] = { 1,2,4,8,16,32,64 };
	int nextLevel = 1;

	for (int i = 1; i < TREE_SIZE; i++) {
		if (i == pow2[nextLevel]) {
			cout << endl;
			nextLevel++;
		}
		if (tree[i]) {
			cout << tree[i]<<" ";
		}
	}
}

int findNode(int node) {
	for (int i = 1; i < TREE_SIZE; i++) {
		if (tree[i] == node)
			return i;
	}
	return -1;
}
int main() {
	freopen("test.txt", "r", stdin);

	cin >> V >> E;
	for (int i = 0; i < E; i++) {
		int parent, child;
		cin >> parent >> child;

		int pidx = findNode(parent);
		if (pidx < 1) {
			pidx = 1;
			tree[pidx] = parent;
		}
		if (tree[2 * pidx] == 0)
		{
			tree[2 * pidx] = child;
		}
		else {
			tree[2 * pidx + 1] = child;
		}
	}
	cout << "전위순회 : ";
	preoder(1);
	cout << "\n";

	cout << "중위순회 : ";
	inoder(1);
	cout << "\n";

	cout << "후위순회 : ";
	postoder(1);
	cout << "\n";

	cout << "level순회 : \n";
	leveloder(1);
	cout << "\n";

}