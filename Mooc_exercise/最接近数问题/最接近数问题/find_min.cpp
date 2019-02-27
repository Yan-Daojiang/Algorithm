#include<iostream>
#include<cmath>
using namespace std;
int main()
{
	int test[10], count, diff=INT32_MAX;
	cin >> count;
	for (int m = 0; m < count; m++)
	{
		cin >> test[m];
	}
	for (int i = 0; i < count; i++)
		for (int j = i + 1; j < count; j++)
			if (abs(test[i] - test[j]) < diff)
				diff = abs(test[i] - test[j]);
	cout << diff<<endl;
	return 0;
}