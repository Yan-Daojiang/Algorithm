#include<iostream>
using namespace std;
int Fib2(int n)		
{
	int dp[3];
	dp[1] = 1; dp[2] = 1;
	for (int i = 3; i <= n; i++)
		dp[i % 3] = dp[(i - 2) % 3] + dp[(i - 1) % 3];
	return dp[n % 3];
}
int main()
{
	cout << Fib2(5) << endl;
	system("pause");
	return 0;
}