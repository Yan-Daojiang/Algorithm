#include<iostream>
#include<cstdlib>
using namespace std;
void disp(int a[], int n)
{
	for (int i = 0; i < n; i++)
		cout << a[i] << " ";
	cout << endl;
}
void merge(int a[], int low, int mid, int high)
{
	int i = low, j = mid + 1, k = 0, *temp;
	temp = (int *)malloc(sizeof(int)*(high - low + 1));
	while (i <= mid && j <= high)
	{
		if (a[i] <= a[j])
		{
			temp[k] = a[i];
			i++;
			k++;
		}
		else
		{
			temp[k] = a[j];
			j++;
			k++;
		}
	}
	while (i <= mid)
	{
		temp[k] = a[i];
		i++;
		k++;
	}
	while (j <= high)
	{
		temp[k] = a[j];
		j++;
		k++;
	}
	for (k = 0, i = low; i <= high; k++, i++)
		a[i] = temp[k];
	free(temp);
}
void merge_sort(int a[],int low,int high)
{
	int mid;
	if (low < high)
	{
		mid = (low + high) / 2;
		merge_sort(a, low, mid);
		merge_sort(a, mid+1, high);
		merge(a, low, mid, high);
	}
}
int main()
{
	int n = 10;
	int a[10] = { 12,12,23,45,44,98,1,4,27,88 };
	cout << "before:" << endl;
	disp(a, n);
	cout << "after sort:" << endl;
	merge_sort(a,0,n-1);
	disp(a, n);
	//system("pause");
	return 0;
}