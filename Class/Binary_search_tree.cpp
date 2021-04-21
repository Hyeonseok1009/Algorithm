#include <iostream>

using namespace std;

struct Node {
	int data;
	Node *left;
	Node *right;
};

Node *root = nullptr;

Node * makeNode(int value) {
	Node * newnode = new Node;
	if (newnode != nullptr) {
		newnode->data = value;
		newnode->left = nullptr;
		newnode->right = nullptr;
	}
	return newnode;
}

Node *searchBST(Node *node, int key) {
	if (node == nullptr) {
		return nullptr;
	}
	if (node->data == key)
		return node;
	else if (node->data > key)
		return searchBST(node->left, key);
	else if (node->data < key)
		return searchBST(node->right, key);
	return node;
}
Node *insertBST(Node *node, int value) {
	//삽입하고자 하는 노드를 탐색하고 탐색 실패위치에 추가한다.
	if (node == nullptr) {
		Node *newnode = makeNode(value);
		return newnode;
	}
	if (node->data < value)
		node->right = insertBST(node->right, value);
	else if (node->data > value)
		node->left = insertBST(node->left, value);
	else {
		//중복값이 들어온 경우는 허용하지 않음
		cout << "Duplicate key";
	}
	return node; //  <--- 반드시 해야함!

}

void printTree(Node *node, int level, int depth) {
	if (node == nullptr) return;
	if (level < depth) return;

	printTree(node->left, level, depth + 1);
	printTree(node->right, level, depth + 1);

	if (level == depth) {
		printf("%d ", node->data);
	}
}

void printBST(Node *node) {
	const int depth = 5;

	for (int i = 0; i < depth; i++) {
		printTree(node, i, 0);
		cout << endl;
	}
	cout << endl;
}

Node * findMostBiggestNode(Node *node) {
	while (node->right != nullptr) {
		node = node->right;
	}
	return node;
}


Node *deleteBST(Node *node, int value) {
	if (node == nullptr) return nullptr;

	if (node->data < value)
		node->right = deleteBST(node->right, value);
	else if (node->data > value)
		node->left = deleteBST(node->left, value);
	else {
		//삭제 대상 노드를 찾은 경우
		if (node->left != nullptr && node->right != nullptr) {
			//degree = 2
			Node *replaceNode = findMostBiggestNode(node->left);
			node->data = replaceNode->data;
			node->left = deleteBST(node->left, replaceNode->data);
		}
		else {
			//degree = 1, 0
			Node *delNode = node;

			node = node->left;
			if (node == nullptr) {
				node = delNode->right;
			}
			delete delNode;
		}
	}
	return node;
}
int main() {
	root = insertBST(root, 9);
	root = insertBST(root, 12);
	root = insertBST(root, 4);
	root = insertBST(root, 15);
	root = insertBST(root, 6);
	root = insertBST(root, 3);
	root = insertBST(root, 13);

	Node *node = searchBST(root, 6);
	if (node != nullptr) {
		printf("0x%p = %d \n", node, node->data);
	}
	else {
		printf("Not found!");
	}
	printBST(root);

	root = deleteBST(root, 13);
	printBST(root);


	return 0;
}