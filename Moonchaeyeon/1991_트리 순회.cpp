#include <iostream>
#include <vector>;
using namespace std;
int N;

template <typename T>
class Node {
private:
	T value;
	Node* left;
	Node* right;
	Node* root;
public:
	Node() : value(NULL), left(nullptr), right(nullptr), root(nullptr) {};
	Node(T _value) : value(_value), left(nullptr), right(nullptr), root(nullptr) {};
	Node(T _value, Node* _left, Node* _right) : value(_value), left(_left), right(_right), root(nullptr) {
		if (_left != nullptr)
			_left->root = this;
		if (_right != nullptr)
			_right->root = this;
	};

	void SetValue(T _value) { this->value = _value; }
	void SetLeft(Node* node) { 
		this->left = node; 
		if (node != nullptr)
			node->SetRoot(this);
	}
	void SetRight(Node* node) { 
		this->right = node;
		if (node != nullptr)
			node->SetRoot(this);
	}
	void SetRoot(Node* node) { this->root = node; }
	Node* GetLeft() { return left; }
	Node* GetRight() { return right; }
	T GetValue() { return value; }
};

// Node 찾기
template <typename T>
void FindNode(Node<T>* node, T value, Node<T>*& result, bool& found) {
	if (node != nullptr && !found) {
		if (node->GetValue() == value) {
			result = node;
			found = true;
		}
		else {
			FindNode(node->GetLeft(), value, result, found);
			FindNode(node->GetRight(), value, result, found);
		}
	}
}

// 전위 순회 (루트) (왼쪽 자식) (오른쪽 자식)
template <typename T>
void Preorder(Node<T>* node) {
	if (node != nullptr) {
		cout << node->GetValue();
		Preorder(node->GetLeft());
		Preorder(node->GetRight());
	}
}

// 중위 순회 (왼쪽 자식) (루트) (오른쪽 자식)
template <typename T>
void Inorder(Node<T>* node) {
	if (node != nullptr) {
		Inorder(node->GetLeft());
		cout << node->GetValue();
		Inorder(node->GetRight());
	}
}

// 후위 순회 (왼쪽 자식) (오른쪽 자식) (루트)
template <typename T>
void Postorder(Node<T>* node) {
	if (node != nullptr) {
		Postorder(node->GetLeft());
		Postorder(node->GetRight());
		cout << node->GetValue();
	}
}

int main() {
	cin >> N;

	Node<char>* root = nullptr;
	char root_v, left_v, right_v;

	for (int i = 0; i < N; i++) {
		Node<char>* currNode;
		Node<char>* left;
		Node<char>* right;

		cin >> root_v >> left_v >> right_v;

		left = ((left_v != '.') ? new Node<char>(left_v) : nullptr);
		right = ((right_v != '.') ? new Node<char>(right_v) : nullptr);

		if (i == 0) // 첫번째 순서일 때
			root = new Node<char>(root_v, left, right);
		else { // 첫번째 순서가 아닐 때
			bool found = false;
			FindNode(root, root_v, currNode, found);
			currNode->SetLeft(left);
			currNode->SetRight(right);
		}
	}

	Preorder(root);
	cout << '\n';
	Inorder(root);
	cout << '\n';
	Postorder(root);
	cout << '\n';

	return 0;
}