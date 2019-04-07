#include<iostream>
using namespace std;
int power(int a, int n)
{
	if (n == 1)return a;
	else
	{
		if (n % 2 == 0)
			return power(a, n / 2)*power(a, n / 2);
		else 
			return power(a, n / 2)*power(a, n / 2)*a;
	}
}
int main()
{
	int a, n;
	cin >> a >> n;
	cout << power(a, n) << endl;
	system("pause");
	return 0;
}