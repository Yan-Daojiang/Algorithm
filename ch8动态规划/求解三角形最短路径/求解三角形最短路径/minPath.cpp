#include<iostream>
using namespace std;
int FindMinPath(int a[10][10], int n)
{
	int dp[10];
	int i, j;
	int min;
	dp[0] = a[0][0];

	for (i = 1; i <= n; i++)
	{
		min = 1000;
		for (j = 0; j < i; j++)
			if (a[i][j] < min)
				min = a[i][j];
		dp[i] = dp[i - 1] + min;
	}
	return dp[n-1];
}
int main()
{
	int a[10][10], n;
	int i, j;
	cin >> n;
	for (i = 0; i < n; i++)
		for (j = 0; j <= i; j++)
			cin >> a[i][j];
	
	cout << FindMinPath(a,n) << endl;
	system("pause");
	return 0;
}