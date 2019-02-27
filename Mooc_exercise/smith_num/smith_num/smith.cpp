#include<iostream>
#include<cmath>
using namespace std;
//本身逐位相加之和
int self_sum(int num)
{
	int sum = 0;
	while (num != 0)
	{
		sum = sum + num % 10;
		num /= 10;
	}
	return sum;
}
//数字分解质因数后求和
int pri_sum(int num) 
{
	int sum = 0, m = 2;
	while (m <= sqrt(num))
	{
		if (num%m == 0)
		{
			num = num / m;
			sum += self_sum(m);
		}
		else ++m;
	}
	sum += self_sum(num);
	return sum;
}
int main()
{
	int num;
	int k=0, test[10];
	int sum1, sum2;
	while (cin >> num)
	{
		if (num == 0)break;
		else 
		{
			test[k] = num;
			k++;
		}
	}
	for(int l=0;l<k;l++)
	{
		num = test[l];
		while (true)
		{
			num += 1;
			sum1 = self_sum(num);
			sum2 = pri_sum(num);
			if (sum1 == sum2)
			{
				cout << num<<endl;
				break;
			}
		}
	}
	//system("pause");
	return 0;
}