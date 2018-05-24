// chuong trinh avl tree 
#include<iostream>
#include<algorithm>
using namespace std;
typedef struct node {
	struct node *left;
	int data;
	struct node *right;
	int height;
}Node;
int Height(Node *root) {
	if (!root)
		return -1;
	else
		return root->height;
}
Node *SingleRotateLeft(Node *X) {
	Node *W = X->left;
	X->left = W->right;
	W->right = X;
	X->height = max(Height(X->left), Height(X->right)) +1;
	W->height = max(Height(W->left), Height(X)) + 1;
	return W;
}
Node *SingleRotateRight(Node *X) {
	Node *W = X->right;
	X->right = W->left;
	X->left = W;
	X->height = max(Height(X->left), Height(X->right))+1;
	W->height = max(Height(W->right), Height(X)) + 1;
	return W;
}
Node *DoubleRotateLeft(Node *Z) {
	Z->left = SingleRotateRight(Z->left);
	return SingleRotateLeft(Z);
}
Node *DoubleRotateRight(Node *Z) {
	Z->right = SingleRotateLeft(Z->right);
	return SingleRotateLeft(Z);
}
Node *Insert(Node *root, int value) {
	if (root == nullptr) {
		root = new Node;
		root->left = root->right = nullptr;
		root->height = 0;
		}
	else if (value < root->data) {
		root->left = Insert(root->left, value);
		if (Height(root->left) - Height(root->right) == 2) {
			if (value < root->left->data)
				root = SingleRotateLeft(root);
			else
				root = DoubleRotateLeft(root);
		}
	}
	else if (value > root->data) {
		root->right = Insert(root->right, value);
		if (Height(root->right) - Height(root->left) == 2) {
			if (value > root->right->data)
				root = SingleRotateRight(root);
			else
				root = DoubleRotateRight(root);
		}
	}
	root->height = max(Height(root->left), Height(root->right))+1;
	return root;
}
void PreOrder(Node *root) {
	cout << root->data << "  ";
	PreOrder(root->left);
	PreOrder(root->right);
}
int main() {
	Node *root = nullptr; 
	root = Insert(root, 2);
	PreOrder(root);
	system("pause");
	return 0;
}