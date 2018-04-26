// chuong trinh thuc hien cac phep toan tren queue su dung circular array 
#include<iostream>
#include<string>
using namespace std;
// cau truc cua queque co array, front rear va capacity 
typedef struct Queue
{
	int front,rear,size;
	int capacity;
	int *array;
} Queue;
// khoi tao queue
// khoi tao ban dau queue rong <=> size= 0;
Queue* CreateQueue(int capacity)
{
	Queue* Q = new Queue;
	if (!Q)
		return NULL;
	Q->front = Q->size = 0;
	Q->capacity = capacity;
	Q->rear = capacity - 1;
	Q->array = (int*)malloc(Q->capacity * sizeof(int));
	if (!Q->array)
		return NULL;
	return Q;
}
// ham kiem tra queue co rong ko 
bool IsEmptyQueue(Queue *Q)
{
	if (Q->size ==0)
		return true;
	else
		return false;
}
// ham kiem tra queue da full ?
bool IsFullQueue(Queue *Q)
{
	if (Q->size == Q->capacity)
		return true;
	else
		return false;
}
// ham insert phan tu vao queue 
void Enqueue(Queue *Q, int data)
{
	if (IsFullQueue(Q) == true)
		cout << "\nQueue da full";
	else
	{
		Q->rear = (Q->rear + 1) % (Q->capacity);
		Q->array[Q->rear] = data;
		Q->size = Q->size + 1;
	}
}
// ham delete phan tu 
int Dequeue(Queue *Q)
{
	int data;
	if (IsEmptyQueue(Q) == true)
		cout << "\nQueue trong";
	else
	{
		data = Q->array[Q->front];
		Q->front = (Q->front + 1) % (Q->capacity); 
		Q->size = Q->size - 1;
	}
	return data;
}
// ham xoa queue 
void DeleteQueue(Queue *Q)
{
	if (Q)
	{
		if (Q->array)
			delete(Q->array);
		delete(Q);
	}
}
// ham tim so phan tu trong queue 
int SizeOfQueue(Queue *Q)
{
	return Q->size;
}
// ham duyet queue
void Display(Queue *Q)
{
	for(int i=0; i< Q->size; i++)
	{
		cout << Q->array[(Q->front+i)%(Q->capacity)] << "  ";	
	}
	
}
void menu(Queue *Q)
{
	
	while (true)
	{
		system("cls");
		cout << "\n\n\n\t\t\t==========================MENU==========================";
		cout << "\n1.Them phan tu vao Queue";
		cout << "\n2.Xoa phan tu khoi Queue";
		cout << "\n3.Hien thi Queue";
		cout << "\n4.Hien thi so phan tu dang co trong Queue";
		cout << "\n5.Delete Queue";
		cout << "\n0.Thoat chuong trinh";
		cout << "\n\n\n\t\t\t========================================================";
		int choose;
		cout << "\nMoi lua chon chuc nang : ";
		cin >> choose;
		if (choose == 1)
		{
			int n;
			cout << "\nMoi nhap so du lieu can nhap ";
			cin >> n;
			for (int i = 0; i < n; i++) {
				int data;
				cout << "\nMoi nhap du lieu ";
				cin >> data;
				Enqueue(Q, data);
			}
		}
		else if (choose == 2)
		{
			int n;
			int data;
			cout << "\nMoi nhap so du lieu can xoa ";
			cin >> n;
			for (int i = 0; i < n; i++)
			{
				data = Dequeue(Q);
				cout << "\nPhan tu vua duoc xoa la " << data;
			}
			system("pause");
		}
		else if (choose == 4)
		{
			int x = SizeOfQueue(Q);
			cout << "\nTrong Queue co " << x << " phan tu";
			system("pause");

		}
		else if (choose = 5)
		{
			DeleteQueue(Q);
		}
		else if (choose == 3)
		{
			cout << "\nDu lieu hien chua trong Queue la : ";
			Display(Q);
			system("pause");
		}
		else
			break;
	}
}
int main()
{
	int capacity;
	cout << "\nMoi nhap vao suc chua cua Queue ";
	cin >> capacity;
	Queue *Q =CreateQueue(capacity);
	menu(Q);
	system("pause");
	return 0;
}