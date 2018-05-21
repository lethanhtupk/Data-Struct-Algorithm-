// chuong trinh merge sort 
#include<iostream>

using namespace std;
// ham tron 2 mang L, R thanh mang A da sap xep 
// countLeft: so phan tu cua mang con ben trai 
// countRight: so phan tu mang con ben phai 
void Merge(int *A, int countLeft, int *L, int countRight, int *R) {
	int i, j, k;
	// i: index cua L
	// j: index cua R
	// k: index cua A
	i = 0; j = 0; k = 0;
	while (i < countLeft && j < countRight)
	{
		if (L[i] < R[j]) A[k++] = L[i++];
		else A[k++] = R[j++];
	}
	// kiem tra mang con ben trai va ben phai co can phan tu ko ?
	// neu con thi them vao mang A
	while (i < countLeft) A[k++] = L[i++];
	while (j < countRight) A[k++] = R[j++];
}
// ham sap xep mang A vs n la so phan tu trong mang A
void MergeSort(int *A, int n) {
	int mid, *L, *R;
	if (n < 2) return; // neu A co it hon 2 phan tu => ko can lam gi 
	else {
		mid = n / 2;
		// khoi tao bo nho cho mang L va R
		// L tu vi tri 0 den mid-1 
		// R tu mid den n-1
		L = new int[mid - 1];
		R = new int[n - mid];
		// khai bao gia tri cho mang L
		for (int i = 0; i < mid; i++) {
			L[i] = A[i];
		}
		// khai bao gia tri cho mang R
		for (int i = mid; i < n; i++) {
			R[i-mid] = A[i];
		}
		MergeSort(L, mid);
		MergeSort(R, n - mid);
		Merge(A, mid, L, n - mid, R);
		
	}
}
int main() {
	int A[] = { 6,2,3,1,9,10,15,13,12,17 };
	int numOfArray = sizeof(A) / sizeof(A[0]);
	MergeSort(A, numOfArray);
	for (int i = 0; i < numOfArray; i++) {
		cout << A[i] << "  ";
	}
	system("pause");
	return 0;
}