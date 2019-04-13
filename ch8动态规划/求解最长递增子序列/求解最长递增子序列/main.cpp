#include<iostream>
#include<cstdlib>
using namespace std;
#define MAX 50
int a[] = {2,1,5,3,6,4,8,9,7};
int n = sizeof(a) / sizeof(a[0]);
int slove(int a[], int n)
{
	int dp[MAX];
	int i, j,maxlen;
	//求解dp数组
	for (i = 0; i < n; i++)
	{
		dp[i] = 1;
		for (j = 0; j < i; j++)
		{
			if (a[i] > a[j])
			{
				if (dp[i] < dp[j] + 1)
					dp[i] = dp[j] + 1;
			}
		}
	}
	//find maxlen
	maxlen = dp[0];
	for (i = 1; i < n; i++)
	{
		if (dp[i] > maxlen)
			maxlen = dp[i];
	}
	return maxlen;
}
int main()
{
	cout << slove(a, n) << endl;
	//system("pause");
	return 0;
}