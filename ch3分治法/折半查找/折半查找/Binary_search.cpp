#include<iostream>
using namespace std;
int BinSearch(int a[], int low, int high, int k)
{
	int mid;
	if (low <= high)
	{
		mid = (low + high) / 2;
		if (a[mid] == k)
			return mid;
		else if (a[mid] > k)
			return BinSearch(a, low, mid, k);
		else
			return BinSearch(a, mid + 1, high, k);
	}
	else
		return -1;
}
int main()
{
	int n = 10;
	int k = 7;
	int a[10] = { 1,2,3,4,5,6,7,8,9,10 };
	if (BinSearch(a, 0, 9, k) >= 0)
		cout << "ÕÒµ½" << endl;
	else
		cout << "Î´ÕÒµ½" << endl;
	//system("pause");
	return 0;
}