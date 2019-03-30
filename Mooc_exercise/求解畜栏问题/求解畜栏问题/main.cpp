#include<iostream>
#include <algorithm>
using namespace std;
#define MAX 50001
//问题表示
struct Cow								//奶牛的类型声明
{
	int no;								//牛编号
	int b;								//起始时间
	int e;								//结束时间
	bool operator<(const Cow &s) const	//重载<关系函数
	{
		if (e == s.e)						//结束时间相同按开始时间递增排序
			return b <= s.b;
		else							//否则按结束时间递增排序
			return e <= s.e;
	}
};

Cow A[50001] ;	//下标0不用
//求解结果表示
int ans[MAX];								//ans[i]表示第A[i].no头牛的蓄栏编号
void solve(int nums)								//求解最大兼容活动子集
{
	int n = nums;
	
	//memset(ans, 0, sizeof(ans));				//初始化为0	for (int i = 0; i <= MAX; i++)		ans[i] = 0;

	int num = 1;							//蓄栏编号
	for (int i = 1; i <= n; i++)					//i、j均为排序后的下标
	{
		if (ans[i] == 0)					//第i头牛还没有安排蓄栏
		{
			ans[i] = num;					//第i头牛安排蓄栏num
			int preend = A[i].e;				//前一个兼容活动的结束时间
			for (int j = i + 1; j <= n; j++)		//查找一个最大兼容活动子集
			{
				if (A[j].b > preend && ans[j] == 0)
				{
					ans[j] = num;			//将兼容活动子集中活动安排在num蓄栏中
					preend = A[j].e;		//更新结束时间
				}
			}
			num++;						//查找下一个最大兼容活动子集,num增1
		}
	}
}

int main()
{
	//Input
	int nums;
	cin >> nums;
	for (int i = 0; i <= nums; i++)
		if (i == 0)
			A[i].no = 0;
		else
		{
			A[i].no = i;
			cin >> A[i].b >> A[i].e;
		}

	//问题求解
	solve(nums);

	//Output
	int max = ans[1];
	for (int i = 2; i <= nums; i++)
		if (ans[i] > max)
			max = ans[i];
	cout << max<<endl;

	for (int i = 1; i <= nums; i++)
		cout<<ans[i]<<endl;

	system("pause");
	return 0;
}