// chương trình stack sử dụng linked list 
#include<iostream>
#include<stdlib.h>
using namespace std;

typedef struct ListNode {
	int data;
	struct ListNode *next;
}ListNode;

int IsEmptyStack(ListNode *head)
{
	if (head == NULL)
		return 1;
	else
		return 0;
}
void Push(ListNode **head, int data)
{
	ListNode *temp = new ListNode;
	temp->data = data;
	temp->next = *head;
	*head = temp;
}
void Pop(ListNode **head)
{
	if (IsEmptyStack(*head) == 1)
		cout << "Stack is empty";
	else
	{
		ListNode *temp = new ListNode;
		temp = *head;
		*head = (*head)->next;
		delete(temp);
	}
	
}
void Display(ListNode **head)
{
	ListNode *temp = new ListNode;
	temp = *head;
	while (temp->next != NULL)
	{
		cout << temp->data << endl;;
		temp = temp->next;
	}
	cout << temp->data << endl;
	
}

int main()
{
	ListNode *head = NULL;
	int n;
	cout << "\nNhap n ";
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int x;
		cout << "\nNhap x ";
		cin >> x;
		Push(&head, x);
	}
	Display(&head);
	system("pause");
	return 0;
}