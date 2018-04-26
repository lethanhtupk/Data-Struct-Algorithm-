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
	ListNode *temp;
	temp = new ListNode;
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
int main()
{
	Queue *Q = CreateQueue();
	Enqueue(Q, 1);
	Enqueue(Q, 2);
	Enqueue(Q, 3);
	int x=Dequeue(Q);
	cout << "\n" <<x << endl;
	system("pause");
	return 0;
}