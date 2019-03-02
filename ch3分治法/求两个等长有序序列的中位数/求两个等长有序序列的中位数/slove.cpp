#include<iostream>
using namespace std;
//返回两个等长有序序列的中位数
int slove(int a[],int b[],int lowa,int higha,int lowb,int highb)
{
	if (lowa == higha && lowb == highb)
		return a[lowa] < b[lowb] ? a[lowa] : b[lowb];
	else
	{
		int mida, midb;
		mida = (lowa + higha) / 2;
		midb = (lowb + highb) / 2;
		if (a[mida] == b[midb])
			return a[mida];
		else if (a[mida] > b[midb])
		{
			if ((lowb + highb) % 2 == 0)
				return slove(a, b, lowa, mida, midb, highb);
			else
				return slove(a, b, lowa, mida , midb + 1, highb);
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
	int a[] = { 11,13,15,17,19 };
	int b[] = { 2,4,6,8,20 };
	cout << slove(a, b, 0,4,0,4 )<<endl;
	//system("pause");
	return 0;
}