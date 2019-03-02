#include<iostream>
using namespace std;
int findMinK(int a[], int s, int t, int k)
{
	int i = s, j = t,tmp;
	if (s >= t)
	{
		if (s == t && s == k - 1)
			return a[k - 1];
	}
	else
	{
		tmp = a[s];
		while (i != j)
		{
			while (j > i&&a[j] >= tmp)
				j--;
			a[i] = a[j];
			while (j > i&&a[i] <= tmp)
				i++;
			a[j] = a[i];
		}
		a[i] = tmp;

		if (k - 1 == i)
			return a[i];
		else if (k - 1 < i)
			return findMinK(a, s, i - 1, k);
		else
			return findMinK(a, i + 1, t, k);
	}
}
int main()
{
	int n = 12;
	int a [] = { 12,3,4,12,34,567,1,67,35,134,597,235 };
	for (int k = 1; k <= n; k++)
	{
		cout << "第" << k << "小的元素为:" << findMinK(a, 0, n - 1, k) << endl;
	}
	//system("pause");
	return 0;
}