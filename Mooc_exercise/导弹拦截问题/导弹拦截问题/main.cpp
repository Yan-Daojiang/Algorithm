#include<iostream>
using namespace std;
int max_num(int a[],int n)
{
	int i, j;
	int max = -1;

	int dp[30];

	dp[1] = 1;
	for (i = 2; i <= n; i++)
	{
		dp[i] = 0;

		for (j = 1; j < i; j++)
			if (a[i] <= a[j])
				if (dp[i] > dp[j] + 1)
					dp[i] = dp[i];
				else
					dp[i] = dp[j] + 1;
	}

	for (i = 1; i <= n; i++)
		if (dp[i] > max)
			max = dp[i];

	return max;
}

int main()
{
	int n, i, height[30];
	//input
	cin >> n;
	for (i = 1; i <= n; i++)
		cin >> height[i];
	//output
	cout << max_num(height, n)<<endl;

	system("pause");
	return 0;
}