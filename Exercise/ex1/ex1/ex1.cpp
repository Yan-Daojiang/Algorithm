#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstdio>
using namespace std;
//返回两个等长有序序列的中位数
int slove(int a[], int b[], int lowa, int higha, int lowb, int highb)
{
	//序列中只有一个元素时返回较小的元素
	if (lowa == higha && lowb == highb)
		return a[lowa] < b[lowb] ? a[lowa] : b[lowb];
	else
	{
		int mida, midb;
		mida = (lowa + higha) / 2;
		midb = (lowb + highb) / 2;
		
		//两个序列的中位数相等时直接返回这个数为中位数
		if (a[mida] == b[midb])
			return a[mida];

		//分解的子问题
		else if (a[mida] > b[midb])
		{
			if ((lowb + highb) % 2 == 0)
				return slove(a, b, lowa, mida, midb, highb);
			else
				return slove(a, b, lowa, mida, midb + 1, highb);
		}

		else if (a[mida] < b[midb])
		{
			if ((lowa + higha) % 2 == 0)
				return slove(a, b, mida, higha, lowb, midb);
			else
				return slove(a, b, mida + 1, higha, lowb, midb);
		}
	}
}

int main()
{
	//文件重定向输入
	freopen("D://Algorithm//Exercise//data//ex1//input.txt","r",stdin);
	freopen("D://Algorithm//Exercise//data//ex1//output.txt", "w", stdout);
	
	int n, a[300], b[300];

	cin >> n;

	for (int i = 0; i < n; i++)
		cin >> a[i];
	for (int i = 0; i < n; i++)
		cin >> b[i];

	//output
	cout << slove(a, b, 0, n - 1, 0, n - 1)<<endl;

	fclose(stdin);
	fclose(stdout);

	//system("pause");
	return 0;
}