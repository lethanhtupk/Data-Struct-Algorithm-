// chương trình stack sử dụng dynamic array 
#include<iostream>
#include<stdlib.h>
using namespace std;
// cấu trúc dữ liệu của stack sử dụng mảng động
typedef struct DynStack {
	int top;
	int capacity;
	int *Arr;
} DynStack;
int IsArrayFull(DynStack *S)
{
	if (S->top == S->capacity-1)
		return 1;
	else
		return 0;
}
int IsArrayEmpty(DynStack *S)
{
	if (S->top == -1)
		return 1;
	else
		return 0;
}
// hàm gấp đôi sức chưa của array 
void DouleArray(DynStack *S)
{
	S->capacity = S->capacity*2;
	S->Arr = (int *)realloc(S->Arr, S->capacity* sizeof(int)); // cấp phát bộ nhớ cho mảng mới 
}
void push(DynStack *S, int data)
{
	if (IsArrayFull(S) == 1)
		DouleArray(S);
	
		S->top++;
		S->Arr[S->top] = data;
	
		

}
void pop(DynStack *S)
{
	if (IsArrayEmpty(S) == 1)
		cout << "Stack is empty ";
	else
		S->top--;
}
void Display(DynStack *S)
{
	for(int i=0; i<= S->top; i++)
		cout << S->Arr[i] << endl;
	system("pause");
}
int main()
{
	DynStack *S = new DynStack;
	S->top = -1;
	S->capacity = 1;
	S->Arr = (int *)malloc( S->capacity * sizeof(int));
	int n;
	cout << "\nNhap so phan tu ";
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int x; 
		cout << "\nNhap gia tri ";
		cin >> x;
		push(S, x);
	}
	Display(S);
	return 0;
}