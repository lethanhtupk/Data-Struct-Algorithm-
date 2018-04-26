// chuong trinh enqueue, dequeue bang dynamic array
#include<iostream>
#include<string>
using namespace std;
// cau truc cua 1 phan tu 
typedef struct DynArray {
	int front, rear;
	int *array;
	int capacity,size;
} DynArray;
// khoi tao Array co capacity =1; front = 0; rear = capacity-1
DynArray *CreateDynArray()
{
	DynArray *Q = new DynArray;
	Q->capacity = 1;
	Q->front =Q->size = 0;
	Q->rear = Q->capacity -1;
	Q->array = (int*)malloc(Q->capacity * sizeof(int));
	return Q;
}
// kiem tra Queue co trong ko ?
bool IsEmptyQueue(DynArray *Q)
{
	if (Q->size = 0)
		return true;
	else
		return false;
}
// ham kiem tra queue da full chua?
bool IsFullQueue(DynArray *Q)
{
	if ((Q->rear + 1) % Q->capacity == Q->front)
		return true;
	else
		return false;
}
// ham thay doi suc chua queue 
void ReSize(DynArray *Q)
{

}
void EnQueue(DynArray *Q, int data)
{
	if (IsFullQueue(Q) == true)
		Q->capacity = Q->capacity * 2;
	Q->rear = (Q->rear + 1) % Q->capacity;
	Q->array[Q->rear] = data;
	Q->size = Q->size + 1;

}
int QueueSize(DynArray *Q)
{
	return Q->size;
}
int DeQueue(DynArray *Q)
{
	int data;
	if (IsEmptyQueue(Q) == true)
		cout << "Queue trong";
	else {
		data = Q->array[Q->front];
		Q->front = (Q->front + 1) % Q->capacity;
		Q->size = Q->size - 1;
	}
	return data;
}
void DeleteQueue(DynArray *Q)
{
	if (Q)
	{
		if (Q->array)
			delete(Q->array);
		delete(Q);
	}
}
void Menu(DynArray *Q)
{
	while (true)
	{
		system("cls");
		cout << "\n\n\t\t\t===========================MENU===========================";
		cout << "\n1.Them phan tu vao Queue";
		cout << "\n2.Xoa phan tu khoi Queue";
		cout << "\n3.Hien thi size cua Queue";
		cout << "\n4.Xoa Queue";
		cout << "\n0.Thoat chuong trinh";
		cout << "\n\n\t\t\t==========================================================";
		int choose; 
		cout << "\nMoi nhap lua chon ";
		cin >> choose;
		if (choose == 1)
		{
			int data;
			cout << "Nhap du lieu ";
			cin >> data;
			EnQueue(Q, data);
		}
		else if (choose == 2)
		{
			int data = DeQueue(Q);
			cout << "\nPhan tu vua duoc dua ra khoi Queue la " << data;
		}
		else if (choose == 3)
		{
			int n;
			n = QueueSize(Q);
			cout << "\nSize cua Queue la " << n;
			system("pause");
		}
		else if (choose == 4)
			DeleteQueue(Q);
		else
			break;
	}
}
int main()
{
	DynArray *Q = CreateDynArray();
	Menu(Q);
	system("pause");
	return 0;
}