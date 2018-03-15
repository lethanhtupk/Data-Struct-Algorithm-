#include<iostream>
using namespace std;
int main()
{
	int s1, s2, s3;
	s1 = 3;
	s2 = 2;
	s3 = 3;
	int sum;
	int a[100];
	// khai báo mảng để giữ giá trị và số lần xuất hiên của tổng 3 mặt xúc xắc
	int sum_max = s1 + s2 + s3;
	int sum_arr[9]; // sum_max là tổng giá trị của 3 mặt xúc xắc
	// vòng lặp gán giá trị 0 cho sum_arr
	for (int index = 0; index <= sum_max; index++)
	{
		sum_arr[index] = 0;
	}

	// 3 vòng lặp để vét cạn 
	for (int i = 1; i <= s1; i++)
	{
		for (int j = 1; j <= s2; j++)
		{
			for (int k = 1; k <= s3; k++)
			{
				sum = i + j + k;
				sum_arr[sum] += 1;
			}
				
				
		}
	}
	// tìm giá trị nhỏ nhất xuất hiện nhiều nhất. ưu tiên xuất hiện nhiều nhất 
	int max = 0;
	int max_value;
	for (int t = 0; t <= sum_max; t++)
	{
		if (max < sum_arr[t]) {
			max = sum_arr[t];
			max_value = t;
		}
	}
	cout << "gia tri xua hien nhieu nhat la " << max_value;
	cout << "\nSo lan xuat hien" << sum_arr[max];

	system("pause");
	return 0;
}
