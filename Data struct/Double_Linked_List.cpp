// chương trình double linked list và các phép toán 
#include<iostream>
#include<stdlib.h>
using namespace std;
// khai báo cấu trúc 
typedef struct DLLNode
{
	int data; // dữ liệu của node 
	struct DLLNode* next; // con trỏ trỏ đến node tiếp theo 
	struct DLLNode* prev; // con trỏ trỏ đến node trước đó 
} Node;

// hàm insert node ở đầu  
void InsertNodeAtBeginning(Node **head, int data)
{
	Node *temp = new Node;
	temp->data = data;
	temp->prev = NULL;
	temp->next = *head;
	if ((*head) != NULL)
		(*head)->prev = temp;
	*head = temp;
}
// hàm insert node ở cuối
void InsertNodeAtEnd(Node **head, int data)
{
	Node *temp = new Node;
	Node *temp1 = new Node;
	temp1 = *head;
	temp->data = data;
	if ((*head) == NULL)
	{
		
		temp->next = NULL;
		temp->prev = NULL;
		*head = temp;
	
	}
	else
	{
		while (temp1->next != NULL)
			temp1 = temp1->next;

		temp->next = NULL;
		temp->prev = temp1;
		temp1->next = temp;
	}
	


}
// hàm insert node ở vị trí bất kì 
void InsertNode(Node **head,int position, int data)
{
	int k = 1;
	Node *temp1, *temp, *temp2;
	temp = new Node;
	temp1 = new Node;
	temp2 = new Node;
	temp1 = *head;
	while (temp1->next != NULL && k < position-1)
	{
		temp2 = temp1;
		temp1 = temp1->next;
		k++;
	}
	temp->data = data;
	temp->next = temp1->next;
	temp->prev = temp1;
	temp1->next = temp;
	temp2->prev = temp;

}
// hàm xóa node ở đầu 
void DeleteNodeAtFront(Node **head)
{
	Node *temp;
	temp = new Node;
	temp = *head;
	*head = (*head)->next;
	(*head)->prev = NULL;
	delete temp;
}
// hàm xóa node ở cuối 
void DeleteNodeAtEnd(Node **head)
{
	Node *temp1, *temp;
	temp1 = new Node;
	temp = new Node;
	temp1 = *head;
	while (temp1->next != NULL)
	{
		temp1 = temp1->next;
	}
	temp = temp1->prev;
	temp->next = NULL;
	delete temp1;
}
// hàm xóa node ở vị trí bất kì 
void DeleteNode(Node **head, int position)
{
	Node *temp1, *temp, *temp2;
	temp1 = new Node;
	temp = new Node;
	temp2 = new Node;
	int k = 1;
	temp1 = *head;
	while ((temp1->next != NULL) && (k < position))
	{
		temp1 = temp1->next;
		k++;
	}
	temp2 = temp1->next;
	temp = temp1->prev;
	temp->next = temp2;
	
	delete temp1;
	
}
//Hàm hiển thị double linked list 
void Display(Node **head)
{
	Node* temp;
	temp = new Node;
	temp = *head;
	while (temp != NULL)
	{
		if (temp->next != NULL)
		{
			cout << temp->data << " ";
		}
		else
			cout << temp->data << " ";
		temp = temp->next;
	}
}
// ham menu 
void Menu(Node **head)
{
	while (true)
	{
		system("cls");
		cout << "\n\n\t\t\t=================MENU=================";
		cout << "\n1.Tao double linked list";
		cout << "\n2.Chen node vao cuoi";
		cout << "\n3.Chen node vao dau";
		cout << "\n4.Chen node vao vi tri bat ki";
		cout << "\n5.Xoa node o cuoi";
		cout << "\n6.Xoa node o dau";
		cout << "\n7.Xoa node o vi tri bat ki";
		cout << "\n8.Hien thi danh sach";
		cout << "\n0.Thoat chuong trinh";
		cout << "\n\n\t\t\t======================================";
		int choose;
		cout << "\nNhap lua chon ";
		cin >> choose;
		if (choose == 1) // tạo linked list 
		{
			int n;
			cout << "\nNhap so node can tao ";
			cin >> n;
			for (int i = 0; i < n; i++)
			{
				int x;
				cout << "\nNhap gia tri cua node ";
				cin >> x;
				InsertNodeAtEnd(head, x);
			}
		}
		else if (choose == 2)// chèn node vào cuối 
		{
			int x;
			cout << "\nNhap gia tri cua node ";
			cin >> x;
			InsertNodeAtEnd(head, x);
		}
		else if (choose == 3) // chèn node vào đầu 
		{
			int x;
			cout << "\nNhap gia tri cua node ";
			cin >> x;
			InsertNodeAtBeginning(head, x);
		}
		else if (choose == 4) // chèn node vào vị trí bất kì 
		{
			int x, k;
			cout << "\nNhap vi tri can chen ";
			cin >> k;
			cout << "\nNhap gia tri cua node ";
			cin >> x;
			InsertNode(head, k, x);
		}
		else if (choose == 5) // xóa node ở cuối 
		{
			DeleteNodeAtEnd(head);
		}
		else if (choose == 6) // xóa node ở đầu 
		{
			DeleteNodeAtFront(head);
		}
		else if (choose == 7) //xóa node ở vị trí bất kì 
		{
			int k;
			cout << "\nNhap vi tri node can xoa ";
			cin >> k;
			DeleteNode(head, k);
		}
		else if (choose == 8)
		{
			Display(head);
			system("pause");
		}
		else
			break;

	}
	
}

		
int main()
{
	Node *head = NULL;
	Menu(&head);
	return 0;
}
// hoàn thành, ngại ko viết menu :)) 