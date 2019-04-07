#include<iostream>
using namespace std;
int maxSubSum(int a[], int n)
{
	int i, max = 0, sum = 0;
	for (i = 0; i < n; i++)
	{
		sum += a[i];//向右累加
		if (sum < 0) //若当前子序列和为负数，重新开始下一子序列
			sum = 0;
		if (sum > max)//发现更大和则更新当前结果
			max = sum;
	}
	return max;
}
 
int main()
{
	int a[] = { 1,2,-1,8 };
	cout << maxSubSum(a, 4) << endl;
	system("pause");
	return 0;
}