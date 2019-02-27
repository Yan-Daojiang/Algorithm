#include<iostream>
#include<cstdlib>
using namespace std;
void disp(int a[], int n)
{
	for (int i = 0; i < n; i++)
		cout << a[i] << " ";
	cout << endl;
}
//归并一次
void merge(int a[],int low,int mid,int high)
{
	int i = low, j = mid + 1, k = 0;
	int *tmpa;
	tmpa=(int *)malloc((high - low + 1) * sizeof(int));
	while (i <= mid && j <= high){
		if (a[i] <= a[j])
		{
			tmpa[k] = a[i];
			i++; 
			k++;
		}
		else
		{
			tmpa[k] = a[j];
			j++;
			k++;
		}
	}
	while (i <= mid)
	{
		tmpa[k] = a[i];
		i++;
		k++;
	}
	while (j <= high)
	{
		tmpa[k] = a[j];
		j++;
		k++;
	}
	for (k = 0, i = low; i <= high; k++, i++)
		a[i] = tmpa[k];
	free(tmpa);
}
//归并一趟
void mergePass(int a[],int length,int n)
{
	int i;
	for (i = 0; i + 2 * length - 1 < n; i += 2 * length)
		merge(a, i, i + length - 1, i + 2 * length - 1);
	if (i + length - 1 < n)//归并剩下的两个子表
		merge(a, i, i + length - 1, n - 1);
}
//归并排序
void mergeSort(int a[], int n)
{
	int length;
	for (length = 1; length < n; length *= 2)
		mergePass(a, length, n);
}
int main()
{
	int n = 10;
	int a[10] = { 12,12,23,45,44,98,1,4,27,88 };
	cout << "before:" << endl;
	disp(a, n);
	cout << "after sort:" << endl;
	mergeSort(a, 10);
	disp(a, n);
	system("pause");
	return 0;
}