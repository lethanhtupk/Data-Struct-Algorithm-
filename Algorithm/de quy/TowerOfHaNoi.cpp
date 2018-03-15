#include<iostream>
using namespace std;
void TowerOfHaNoi(int n, char frompeg, char topeg, char auxpeg)
{
	if (n == 1)
		cout << "\nChyen 1 dia tu " << frompeg << " den " << topeg;
	else
	{
		TowerOfHaNoi(n - 1, frompeg, auxpeg, topeg);
		TowerOfHaNoi(1, frompeg, topeg, auxpeg);
		TowerOfHaNoi(n - 1, auxpeg, topeg, frompeg);
	}
}

int main()
{
	TowerOfHaNoi(3, 'A', 'B', 'C');
	system("pause");
	return 0;
}