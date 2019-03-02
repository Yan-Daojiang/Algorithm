#include<iostream>
using namespace std;
void disp(char a[],int n)
{
	for (int i = 0; i < n; i++)
		cout << a[i];
	cout << endl;
}
//将长度为n的数组元素左移一位
void move(char a[], int n)
{
	a[n] = a[0];
	for (int i = 1; i <= n; i++)
		a[i - 1] = a[i];
}
//将长度为n的数组元素左移k位
void move_k(char a[], int n, int k)
{
	for (int i = 0; i < k; i++)
		move(a, n);
}
int main()
{
	int n, k;//n为数组的长度，m为左移的位数
	char a[100];
	cin >> n >> k>> a;
	move_k(a, n, k);
	disp(a, n);
	//system("pause");
	return 0;
}