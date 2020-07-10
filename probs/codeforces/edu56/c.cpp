#include <bits/stdc++.h>

using namespace std;

int n;
long long b[100005], a[200005];
int main()
{
	cin >> n;
	for(int i = 0; i < n/2; i++)
	{
		cin >> b[i];
	}
	long long w = 0, l = LLONG_MAX;
	for(int i = 0; i < n/2; i++)
	{
		if(b[i] - w > l) w = b[i] - l;
		a[i] = w;
		a[n-1-i] = b[i] - w;
		l = a[n-i-1];
	}
	for(int i = 0; i < n; i++) cout << a[i] << ' ';
	cout << endl;
}
