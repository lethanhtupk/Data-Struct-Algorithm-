// chương trình thực hiện các phép toán trên linked list
#include<iostream>
#include<stdlib.h>
using namespace std;
// cấu trúc của 1 node trong linked list
struct node
{
	int data; // data chứa dữ liệu
	struct node *next; // biến con trỏ next trỏ đến node tiếp theo
};
typedef struct node Node;
Node* head= NULL; // khai báo linked list trống
int ListLength(Node *current)
{
	
	int count = 0;
	current = head;
	while (current != NULL)
	{
		count++;
		current = current->next;
	}
	return count;
}
// hàm chèn node vào sau cùng
void InsertFromBack(int data)
{
	Node* temp;
	temp = new Node;
	if (head == NULL) {
		temp->data = data;
		temp->next = NULL;
		head = temp;
	}
	else {
		Node* temp1 = head;
		while (temp1->next != NULL)
			temp1 = temp1->next;
		temp->data = data;
		temp->next = NULL;
		temp1->next = temp;
	}
}
// hàm insert node cho link list
void InsertNode( int data, int position)
{
	Node  *temp1,*temp;
	temp1 = new Node;
	temp = new Node;
	temp1 = head;
	temp->data = data;
	for (int i = 1; i<position - 1; i++)
	{
		temp1 = temp1->next;
		if (temp1->next = NULL)
		{
			cout << "\nNode ko ton tai";
			break;

		}

	}
	temp->next = temp1->next;
	temp1->next = temp;


}
// Insert vào đầu linked list
void InsertFromFront(Node *temp,int data)
{
	
	temp = new Node;
	temp->data = data;
	temp->next = head;
	head = temp;

}
// duyệt linked list
void DuyetNode(Node* temp1)
{
	
	temp1 = head;
	while (temp1 != NULL)
	{
		cout << temp1->data << "  ";
		temp1 = temp1->next;
	}
}
// hàm xóa node ở đầu 
void DeleteNodeInFront(Node* temp)
{
	temp = new Node;
	temp= head;
	head = temp->next;
	delete temp;

}
// hàm xóa node ở cuối 
void DeleteNodeInBack()
{
	Node* temp1;
	Node* temp;
	temp1 = new Node;
	temp = new Node;
	temp1 = head;
	while (temp1->next != NULL)
	{
		temp = temp1;
		temp1 = temp1->next;
	}
	temp->next = NULL;
	delete temp1;
	
}
// hàm xóa node ở vị trí bất kì 
void DeleteNode(int k)
{
	Node* temp1;
	Node* temp;
	temp = new Node;
	temp1 = new Node;
	temp1 = head;
	for (int i = 1; i < k; i++)
	{
		temp = temp1;
		temp1 = temp1->next;
	}
	temp->next = temp1->next;
	delete temp1;

}
void Menu(Node* &t)
{

	while (true)
	{
		system("cls");
		cout << "\n\n\t\t\t============MENU============";
		cout << "\n1.Nhap linked list";
		cout << "\n2.Chen vao dau";
		cout << "\n3.Chen vao vi tri bat ki";
		cout << "\n4.Chen vao cuoi";
		cout << "\n5.Tinh do dai cua list";
		cout << "\n6.Duyet list";
		cout << "\n7.Xoa node o dau";
		cout << "\n8.Xoa node o cuoi";
		cout << "\n9.Xoa node o vi tri bat ki";
		cout << "\n0.Thoat chuong trinh";
		cout << "\n============END============";
		int choose;
		cout << "\nNhap lua chon : ";
		cin >> choose;
		if (choose == 1)
		{
			int n;
			cout << "Nhap so node can nhap ";
			cin >> n;
			for (int i = 0; i<n; i++)
			{
				int x;
				cout << "\nNhap du lieu ";
				cin >> x;
				InsertFromBack(x);
			}

		}
		else if (choose == 2)
		{
			int x;
			cout << "\nNhap du lieu ";
			cin >> x;
			InsertFromFront(t,x);
		}
		else if (choose == 3)
		{
			int x, k;
			cout << "\nNhap vi tri can chen ";
			cin >> k;
			cout << "\nNhap du lieu ";
			cin >> x;
			InsertNode(x, k);

		}
		else if (choose == 4)
		{
			int x;
			cout << "\nNhap du lieu ";
			cin >> x;
			InsertFromBack(x);
		}
		else if (choose == 5)
		{
			cout << "\nDo dai cua list bang " << ListLength(t);
			system("pause");
		}
		else if (choose == 6)
		{
			DuyetNode(t);
			system("pause");
		}
		else if (choose == 7)
		{
			DeleteNodeInFront(t);
		}
		else if (choose == 8)
		{
			DeleteNodeInBack();
		}
		else if (choose == 9)
		{
			int k; 
			cout << "\nNhap vi tri node k can xoa ";
			cin >> k;
			DeleteNode(k);
		}
		else
			break;
	}
}
int main()
{
	Node *t;
	Menu(t);
	return 0;
}
