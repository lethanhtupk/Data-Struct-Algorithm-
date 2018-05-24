// chuong trinh sap xep su dung thuat toan insertion sort 
#include<iostream>
using namespace std;
void Insertion(int *A, int n) {
	for (int i = 0; i < n; i++) {
		int min = i;
		for (int j = i + 1; j < n; j++) {
			if (A[j] < A[min])
				min = j;
		}
		// swap phan tu 
		int temp = A[i];
		A[i] = A[min];
		A[min] = temp;
	}
}
int main()
{
	int A[] = { 12, 11, 13, 5, 6 };
	Insertion(A, 5);
	for (int i = 0; i < 5; i++)
		cout << A[i] << "  ";
	system("pause");
	return 0;
}