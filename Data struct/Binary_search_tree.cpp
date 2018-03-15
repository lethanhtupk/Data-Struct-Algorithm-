// chương trình thực hiện các phép toán trên cây nhị phân 
#include<iostream>

using namespace std;

// khai báo cấu trúc 1 node 
struct node
{
	int data;
	struct node *pLeft;
	struct node *pRight;
};
typedef struct node Node;

