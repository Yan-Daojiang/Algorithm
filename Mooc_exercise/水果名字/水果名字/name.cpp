#include <iostream>
#include <cstring>
#include <vector>
#include <string>
using namespace std;

#define max(x,y) ((x)>(y)?(x):(y))
#define MAX 51							//序列中最多的字符个数
//问题表示
int m, n;
string a, b;

//求解结果表示
int dp[MAX][MAX];						//动态规划数组
vector<char> subs;						

void LCSlength()						
{
	int i, j; 
	for (i = 0; i <= m; i++)					
		dp[i][0] = 0;
	for (j = 0; j <= n; j++)					
		dp[0][j] = 0;
	for (i = 1; i <= m; i++)
		for (j = 1; j <= n; j++)				
		{
			if (a[i - 1] == b[j - 1])			
				dp[i][j] = dp[i - 1][j - 1] + 1;
			else						
				dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);

		}
}
void Buildsubs()					
{
	int k = dp[m][n];				
	int i = m;
	int j = n;

	//反向的求出序列
	while (k > 0 && j > 0&&i>0)
	{
		
		if (dp[i][j] == dp[i - 1][j])
		{
			subs.push_back(a[i - 1]);
			i--;
		}
		else if (dp[i][j] == dp[i][j - 1])
		{
			subs.push_back(b[j - 1]);
			j--;
		}
		else
		{
			subs.push_back(a[i - 1]);	
			i--; j--; k--;
		}
	}
	while (i > 0)
	{
		subs.push_back(a[i - 1]);
		i--;
	}
	while (j > 0)
	{
		subs.push_back(b[j - 1]);
		j--;
	}
}

int main()
{
	cin >> a >> b;
	m = a.length();			//m为a的长度
	n = b.length();			//n为b的长度

	LCSlength();			//求出dp
	
	Buildsubs();			//求出序列
	
	vector<char>::reverse_iterator rit;
	for (rit = subs.rbegin(); rit != subs.rend(); ++rit)
		cout << *rit;
	cout << endl;
	
	system("pause");
	return 0;
}