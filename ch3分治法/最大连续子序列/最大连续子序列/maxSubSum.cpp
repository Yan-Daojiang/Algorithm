#include<iostream>
using namespace std;
long max3(long a, long b, long c)
{
	if (a < b)
		a = b;
	if (a > c)
		return  a;
	else
		return c;
}
long maxSubSum(long a[],long left,long right)
{
	long maxLeftSum, maxRightSum;
	long maxLeftBorderSum=0, leftBorderSum=0;
	long maxRightBorderSum=0,rightBorderSum=0;

	if (left == right)
	{
		if (a[left] > 0)
			return a[left];
		else
			return 0;
	}

	int mid = (right + left) / 2;

	maxLeftSum = maxSubSum(a, left, mid);

	maxRightSum = maxSubSum(a, mid + 1, right);

	for (int i = mid; i >= left; i--)
	{
		leftBorderSum += a[i];
		if (leftBorderSum > maxLeftBorderSum)
			maxLeftBorderSum = leftBorderSum;
	}
	for (int j = mid+1; j <= right; j++)
	{
		rightBorderSum += a[j];
		if (rightBorderSum > maxRightBorderSum)
			maxRightBorderSum = rightBorderSum;
	}

	return max3(maxLeftSum, maxRightSum, maxLeftBorderSum + maxRightBorderSum);

}
int main()
{
	int n = 6;
	long a[] = { -2,11,-4,13,-5,-2 };

	cout << maxSubSum(a, 0, n - 1)<<endl;

	//system("pause");
	return 0;
}