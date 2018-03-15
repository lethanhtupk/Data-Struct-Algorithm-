// stack sử dụng array để chứa dữ liệu 
#include<iostream>
#include<stdlib.h>
#define MAXSIZE 10
using namespace std;
typedef struct ArraySTack 
{
	int top;
	int capacity;
	int *array;
}  ArrayStack;
// khởi tạo stack
ArraySTack *create(ArraySTack *S)
{
	 S= new ArraySTack;
	if (!S)
		return NULL;
	S->top = -1;
	S->capacity = MAXSIZE;
	S->array = (int *)malloc(S->capacity * sizeof(int));
	if (!S->array)
		return NULL;
	return S;
}
// hàm kiểm tra stack có trống ko 
int IsStackEmpty(ArraySTack *S)
{
	if (S->top == -1)
		return 1;
	else
		return 0;
}
// hàm kiểm tra stack đã đầy??
int IsStackFull(ArraySTack *S)
{
	if (S->top == S->capacity - 1)
		return 1;
	else
		return 0;
}
// hàm push 
void push(ArraySTack *S, int data)
{
	if (IsStackFull(S) == 1)
		cout << "Stack OverFolow";
	else
	{
		S->array[++S->top] = data;
	}
}
// hàm pop
int pop(ArraySTack *S)
{
	if (IsStackEmpty(S) == 0)
		cout << "Stack UnderFlow";
	else
	{
		return (S->array[--S->top]);
	}
}
// hàm display 
void Display(ArraySTack *S)
{
	for(int i=0; i<= S->top; i++)
		cout << S->array[i] << endl;
}
int main()
{	
	ArrayStack *S;
	S = new ArraySTack; 
	S->top = -1;
	S->capacity = MAXSIZE;
	S->array = (int *)malloc(S->capacity * sizeof(int));
	for (int i = 0; i < MAXSIZE; i++)
	{
		int x; 
		cout << "\nnhap x ";
		cin >> x;
		push(S, x);
	}
	Display(S);
	system("pause");
	return 0;
}