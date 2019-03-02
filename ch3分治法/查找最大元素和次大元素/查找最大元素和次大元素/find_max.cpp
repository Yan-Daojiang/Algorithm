#include<iostream>
using namespace std;
void find_max1_max2(int a[],int low,int high,int &max1,int &max2)
{
	if (low == high)//序列中只有一个元素
	{
		max1 = a[low];
		max2 = -INFINITY;
	}
	else if (low = high - 1)
	{
		if (a[low] >= a[high])
		{
			max1 = a[low];
			max2 = a[high];
		}
		else
		{
			max1 = a[high];
			max2 = a[low];
		}
	}
	else
	{
		int mid = (high + low) / 2;
		int lmax1, lmax2;
		find_max1_max2(a,low,mid,lmax1,lmax2);

		int rmax1, rmax2;
		find_max1_max2(a, mid + 1, high, rmax1, rmax2);

		if (lmax1 >= rmax1)
		{ 
			max1 = lmax1;
			if (lmax2 >= rmax1)
				max2 = lmax2;
			else
				max2 = rmax1;
		}
		else
		{
			max1 = rmax1;
			if (rmax2 >= lmax1)
				max2 = rmax2;
			else
				max2 = lmax1;
		}	
	}
}
int main()
{
	int max1, max2;
	int n = 12;
	int a[12] = { 1,12,423,14,123,333,45,56,78,76,999,1000 };
	find_max1_max2(a, 0, n - 1, max1, max2);
	cout << max1 << " " << max2 << endl;
	system("pause");
	return 0;
}