// implement a queue use two stacks
#include<iostream>
#include<string>
#include<stack>
using namespace std;
typedef struct Queue {
	stack <int> S1; // for enqueue
	stack <int> S2; // for dequeue
} Queue;
Queue *CreateQueue()
{
	Queue *Q = new Queue;
	return Q;
}
void EnQueue(Queue *Q,int data)
{
	Q->S1.push(data);
}
/*neu S1, S2 deu trong -> bao loi
neu s2 empty, chuyen phan tu trong s1 sang s2. return s2.top
*/
int Dequeue(Queue *Q)
{
	int x; // giu gia tri top cua s1
	if (Q->S1.empty() && Q->S2.empty()) {
		cout << "Queue is empty";
		return 0;
	}

	else if(Q->S2.empty()){
		while (!Q->S1.empty()) {
			x = Q->S1.top();
			Q->S2.push(x);
			Q->S1.pop();
		}
		return Q->S2.top();
	}
}
int main()
{
	Queue *Q = CreateQueue();
	EnQueue(Q, 1);
	EnQueue(Q,2);
	EnQueue(Q,3);
	EnQueue(Q, 4);
	int n = Dequeue(Q); // n giu gia tri dau tien cua QUeue
	cout << n << endl;
	
	system("pause");
	return 0;
}