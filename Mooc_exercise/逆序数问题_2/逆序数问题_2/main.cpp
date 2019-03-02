#include<iostream>
using namespace std;
//判断一个两个数组成的序列是否构成逆序对 
void judge_two(int a[],int i,int j,int &count)
{
	if (i<j&&a[i]>a[j])
		count++;
}
//将一个序列拆分为为两个元素的逆序对进行判断
int judge(int a[],int n)
{
	int i =0, j = 0, count = 0;
	for (i = 0; i < n; i++)
		for (j = 0; j < n; j++)
			judge_two(a, i, j, count);
	return count;
}
int main()
{
	//input
	int n, count = 0, a[100];
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	//output
	cout << judge(a, n)<<endl;

	//system("pause");
	return 0;
}