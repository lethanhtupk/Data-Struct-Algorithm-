// 3 cach duyet cay su dung de quy 
#include<iostream>
#include<string>
using namespace std;
typedef struct node {
	int data;
	struct node *Left;
	struct node *Right;
} node;
node *newNode(int data)
{
	node *newNode = new node;
	newNode->data = data;
	newNode->Left = NULL;
	newNode->Right = NULL;
	return newNode;
}
/*
Duyet tai node goc
Duyet cay con trai 
Duyet cay con phai
*/
void PreOrder(node *t) {
	if (t) {
		cout << t->data << "  ";
		PreOrder(t->Left);
		PreOrder(t->Right);
	}
}
/* 
Duyet tai vi tri cay con trai 
Duyet node goc 
Duyet cay con phai
*/
void InOrder(node *t) {
	if (t) {
		InOrder(t->Left);
		cout << t->data << "  ";
		InOrder(t->Right);
	}
}
/*
Duyet cay con phai 
Dyet node goc 
Duyet cay con trai
*/
void PostOrder(node *t) {
	if (t) {
		PostOrder(t->Left);
		PostOrder(t->Right);
		cout << t->data << "  ";
		
	}
}
int CountNode(node *t)
{
	int count = 1;
	if (t == NULL)
		return 0;
	else {
		count += CountNode(t->Left);
		count += CountNode(t->Right);
		return count;
	}
	
}
int main()
{
	node *root = newNode(1);
	root->Left = newNode(2);
	root->Right = newNode(3);
	root->Left->Left = newNode(4);
	root->Left->Right = newNode(5);
	root->Right->Left = newNode(6);
	root->Right->Right = newNode(7);
	PreOrder(root);
	cout << endl;
	InOrder(root);
	cout << endl;
	PostOrder(root);
	int n = CountNode(root);
	cout << "\nSo node cua cay la " << n << endl;
	system("pause");
	return 0;
}