#include <iostream>
using namespace std;

template <typename T>
struct Node {
	Node* left;
	Node* right;
	T value;
};

template <typename T>
class BinarySearchTree {
private:
	Node<T>* root;
public:
	BinarySearchTree() : root(nullptr) {};

	void AddNode(T _value) {
		Node<T>* newNode = new Node<T>(); // ���� �߰��� ���
		newNode->value = _value;

		if (root == nullptr)
			root = newNode;
		else {
			Node<T>* findRoot = root; // ��� �θ��� �ڽ����� ���ԵǾ�� �ϴ���
			Node<T>* tempRoot = root; // findRoot���� ���� ������ �������� �˻����ִ� ��

			while (tempRoot != nullptr) {
				findRoot = tempRoot;
				if (_value < tempRoot->value)
					tempRoot = tempRoot->left;
				else tempRoot = tempRoot->right;
			}

			if (_value < findRoot->value)
				findRoot->left = newNode;
			else findRoot->right = newNode;
		}
	}

	Node<T>* GetRoot() { return root; }

	void Postorder(Node<T>* node) {
		if (node != nullptr) {
			Postorder(node->left);
			Postorder(node->right);
			cout << node->value << '\n';
		}
	}
};

int main() {
	BinarySearchTree<int>* BST = new BinarySearchTree<int>();
	int k;
	while (cin >> k)
		BST->AddNode(k);

	BST->Postorder(BST->GetRoot());

	return 0;
}