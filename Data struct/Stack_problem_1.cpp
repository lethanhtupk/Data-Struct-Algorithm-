//Discuss how stacks can be used for checking balancing of symbols.
#include<iostream>
#include<stdlib.h>
#include<string>
using namespace std;
typedef struct node {
	char data;
	struct node *next;
} Node;
Node *head = NULL; 

void push(char data)
{
	Node *temp = new Node;
	temp->data = data;
	temp->next = head;
	head = temp;
}
void pop()
{
	Node *temp = new Node;
	if (head == NULL)
		cout << "\nstack trong";
	temp = head;
	head = head->next;
	delete(temp);

}
void display()
{
	Node *temp = new Node;
	temp = head;
	if (head == NULL)
		cout << "\nstack trong";
	else
	{
		cout << "\nstack hien tai chua :";
		while (temp != NULL)
		{
			cout << temp->data << " ";
			temp = temp->next;
		}
	}
}
void kiemtra(string str)
{
	int k = 0;
	while (str[k] != '\0')
	{
		if (str[k] == '(' || str[k] == '[' || str[k] == '{')
			push(str[k]);
		else if (str[k] == ')')
		{
			if (head->data = '(')
			{
				pop();
			}	
		}
		else if (str[k] == ']')
		{
			if (head->data == '[')
			{
				pop();
			}
			
		}
		else if (str[k] == '}')
		{
			if (head->data == '{')
			{	
				pop();
			}
			
		}
		k++;
	}
	if (head != NULL)
		cout << "khong doi xung";
	else
		cout << "doi xung";
}
int main()
{
	string str = "{()()] ";
	kiemtra(str);
	display();
	system("pause");
	return 0;
}