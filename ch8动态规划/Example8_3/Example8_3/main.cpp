#include<iostream>
#include<string>
using namespace std;
int main()
{
	string str;
	int dp[100];
	int max = -1;
	cin >> str;
	int length =str.length();
	if ('0' <= str[0] && str[0] <= '9')
		dp[0] = 1;
	else
		dp[0] = 0;

	for (int i = 1; i < length; i++)
		if ('0' <= str[i] && str[i] <= '9')
			dp[i] = dp[i - 1] + 1;
		else
			dp[i] = 0;

	for (int i = 0; i < length; i++)
		if (dp[i] > max)
			max = dp[i];


	cout << max << endl;

	system("pause");
	return 0;
}