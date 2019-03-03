#include<iostream>
using namespace std;
int find(int a[],int n,int b[],int m,int k)
{
	if (k < 0)
		return -1;
	if (n > m)
		return find(b, m, a, n, k);//保证前面序列的元素较少
	if (n == 0)
		return b[k - 1];
	if (k == 1)
		return (a[0] >= b[0] ? b[0] : a[0]);

	int numa = (n >= k / 2) ? k / 2 : n;
	int numb = k - numa;

	if (a[numa - 1] == b[numb - 1])
		return a[numb - 1];
	else if (a[numa - 1] > b[numb - 1])
		return find(a, n, &b[numb], m - numb, k - numb);
	else
		return find(&a[numa], n - numa, b, m, k - numa);
}
int main()
{
	int n = 3, m = 5;
	int a[] = { 1,5,8 };
	int b[] = { 2,3,4,6,7 };
	for (int i = 1; i <= m + n; i++)
		cout << "第" << i << "小的元素为:" << find(a, n, b, m, i)<<endl;

	system("pause");
	return 0;
}