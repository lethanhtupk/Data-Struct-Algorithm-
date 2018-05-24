#include<iostream>
using namespace std;
typedef struct BSTNode {
	int data;
	struct BSTNode *pLeft;
	struct BSTNode *pRight;
}Node;
Node *getNewNode(int value) {
	Node *root = new Node;
	root->data = value;
	root->pLeft = nullptr;
	root->pRight = nullptr;
	return root;
}
Node *InsertNode(Node *root, int value) {
	if (root == nullptr) return getNewNode(value);
	else {
		if (value < root->data) root->pLeft = InsertNode(root->pLeft, value);
		else if (value > root->data) root->pRight = InsertNode(root->pRight, value);
	}
	return root;
}
void PreOrder(Node *root) {
	if (root == nullptr)
		return;
	else {
		cout << root->data << "  ";
		PreOrder(root->pLeft);
		PreOrder(root->pRight);
	}
}
bool Search(Node *root, int value) {
	if (root == nullptr)
		return false;
	else {
		if (value < root->data) Search(root->pLeft, value);
		else if (value > root->data) Search(root->pRight, value);
		else
			return true;
	}
}
Node *FindMax(Node *root) {
	if (root == nullptr)
		return nullptr;
	while (root->pRight != nullptr)
		root = root->pRight;
	return root;
}
Node *FindMin(Node *root) {
	if (root == nullptr)
		return nullptr;
	while (root->pLeft != nullptr)
		root = root->pLeft;
	return root;
}
Node *DeleteNode(Node *root, int value) {
	if (root == nullptr)
		return root;
	else if (value < root->data)
		root->pLeft =DeleteNode(root->pLeft, value);
	else if (value > root->data)
		root->pRight =DeleteNode(root->pRight, value);
	else {
		if (root->pLeft == nullptr && root->pRight == nullptr) {
			Node *temp = root;
			root = root->pLeft;
			delete temp;
		}
		else if (root->pLeft == nullptr) {
			Node *temp = root;
			root = root->pRight;
			delete temp;
		}
		else if (root->pRight == nullptr) {
			Node *temp = root;
			root = root->pLeft;
			delete temp;
		}
		else {
			Node *temp = FindMax(root->pLeft);
			root->data = temp->data;
			DeleteNode(root->pLeft, root->data);
		}
	}
	return root;
}
int main()
{
	Node *root = nullptr;
	root = InsertNode(root, 4);
	root = InsertNode(root, 2);
	root = InsertNode(root, 8);
	root = InsertNode(root, 5);
	root = InsertNode(root, 10);
	root = InsertNode(root, 7);
	root = InsertNode(root, 6);
	root = DeleteNode(root, 6);
	PreOrder(root);
	system("pause");
	return 0;
}