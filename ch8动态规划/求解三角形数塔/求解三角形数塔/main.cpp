#include<iostream>
using namespace std;
#define MAX 100
int a[MAX][MAX];
int dp[MAX][MAX];
int n;
int maxSum(int i, int j)
{
	if (dp[i][j] != -1)
		return dp[i][j];
	if (i == n)
		dp[i][j] = a[i][j];
	else
	{
		if (maxSum(i + 1, j) > maxSum(i + 1, j + 1))
			dp[i][j] = maxSum(i + 1, j) + a[i][j];
		else 
			dp[i][j] = maxSum(i + 1, j+1) + a[i][j];
	}
		
	return dp[i][j];
}
int main()
{
	int i, j;
	cin >> n;
	for(i=1;i<=n;i++)
		for (j = 1; j <= i; j++)
		{
			cin >> a[i][j];
			dp[i][j] = -1;
		}
	cout << maxSum(1, 1) << endl;
	system("pause");
	return 0;
}