#include<iostream>
using namespace std;
void disp(int a[], int n)
{
	for (int i = 0; i < n; i++)
		cout << a[i] << " ";
	cout << endl;
}
int Partition(int a[], int s, int t)
{
	int i = s, j = t;
	int temp = a[s];
	while (i != j)
	{
		while (j > i&&a[j] >= temp)
			j--;
		a[i] = a[j];
		while (i < j&&a[i] <= temp)
			i++;
		a[j] = a[i];
	}
	a[i] = temp;
	return i;
}
void Quick_sort(int a[], int s, int t)
{
	if (s < t)
	{
		int i = Partition(a, s, t);
		Quick_sort(a, s, i);
		Quick_sort(a, i + 1, t);
	}
}
int main()
{
	int n = 10;
	int a[10] = { 12,12,23,45,44,98,1,4,27,88 };
	cout << "ÅÅÐòÇ°:" << endl;
	disp(a, n);
	cout << "ÅÅÐòºó:" << endl;
	Quick_sort(a, 0, n - 1);
	disp(a, n);
	//system("pause");
	return 0;
}