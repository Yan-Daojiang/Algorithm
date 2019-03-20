#include<iostream>
using namespace std;
#define max(x,y)((x)>(y)?(x):(y))
#define MAXN 20
int n = 6;
int a[] = { 0,-2,11,-4,13,-5,-2 };
int dp[MAXN];

void maxSubSum()
{
	dp[0] = 0;
	for (int i = 1; i <= n; i++)
	{
		dp[i] = max(dp[i - 1] + a[i], a[i]);
	}
	int maxi = 1;
	for (int i = 2; i <= n; i++)
		if (dp[maxi] < dp[i])
			maxi = i;
	cout << "最大连续子序列和为:" << dp[maxi] << endl;
	
	//输出序列
	cout << "最大的连续子序列如下:" << endl;
	for (int i = maxi; i >= 0; i--)
		if (dp[i] > 0)
			cout << a[i] << " ";
	cout << endl;
}
int main()
{
	maxSubSum();
	//system("pause");
	return 0;
}