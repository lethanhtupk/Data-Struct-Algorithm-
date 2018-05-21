// chuong trinh sap xep 
#include<iostream>
#include<string>
using namespace std;
// sap xep noi bot (bubble sort)
/*
so sanh 2 phan tu o gan nhau 
neu A[i] >A[i+1] thi swap cho nhau
lap lai den khi sap xep hoan tat
*/
void BubbleSort(int A[], int n)
{
	for (int pass = n - 1; pass >= 0; pass--) {
		for (int i = 0; i <= pass-1; i++) {
			if (A[i] > A[i + 1]) {
				int temp = A[i];
				A[i] = A[i + 1];
				A[i + 1] = temp;
				
			}
		}
	}
}

int main() {
	int A[] = { 2,7,4,1,5,3 };
	BubbleSort(A, 6);
	for (int i = 0; i < 6; i++){
		cout << A[i];
	}
	system("pause");
	return 0;
}