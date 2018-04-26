// chuong trinh thuc hien cac phep toan tren queue = linked list
#include<iostream>
#include<string>
using namespace std;
typedef struct ListNode {
	int data;
	struct ListNode *next;
} ListNode;
typedef struct Queue {
	ListNode *front;
	ListNode *rear;
}Queue;
Queue *CreateQueue()
{
	Queue *Q = new Queue;
	if (!Q)
		cout << "Memory Eror";

	Q->front = Q->rear = NULL;
	return Q;
}
bool IsEmptyQueue(Queue *Q)
{
	if (Q->front == NULL)
		return true;
	else
		return false;
}
void Enqueue(Queue *Q, int data)
{
	ListNode *newNode = new ListNode;
	newNode->data = data;
	newNode->next = NULL;
	if (Q->front == NULL)
		Q->front = Q->rear = newNode;
	else {
		Q->rear->next = newNode;
		Q->rear = newNode;
		Q->rear->next = NULL;
	}

}
int Dequeue(Queue *Q)
{
	ListNode *temp;

	int data;
	if (Q->front == NULL) {
		cout << "Queue is empty";
		return 0;
	}
	else {
		temp = Q->front;
		data = Q->front->data;
		Q->front = Q->front->next;
		delete(temp);
	}
	return data;
}
typedef struct Stack {
	Queue *Q1;
	Queue *Q2; 
} Stack;
void push(Stack *S, int data) {
	if (S->Q1->front == NULL)
		Enqueue(S->Q2, data);
	else
		Enqueue(S->Q1, data);
}
int pop(Stack *S)
{
	if (S->Q1->front == NULL)
	{
		ListNode *temp = S->Q2->front;
		while (temp->next != NULL)
		{
			Enqueue(S->Q1, temp->data);
			temp = temp->next;
		}
		return temp->data;
	}
	else {
		ListNode *temp = S->Q1->front;
		while (temp->next != NULL)
		{
			Enqueue(S->Q2, temp->data);
			temp = temp->next;
		}
		return temp->data;
	}
}
int main()
{
	Stack *S = new Stack;
	S->Q1 = CreateQueue();
	S->Q2 = CreateQueue();
	push(S, 1);
	push(S, 2);
	push(S, 3);
	push(S, 4);
	int x= pop(S);
	cout << x << endl;
	system("pause");
	return 0;
}