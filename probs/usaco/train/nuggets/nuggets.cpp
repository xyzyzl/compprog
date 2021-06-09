/*
ID: albert.28
LANG: C++14
TASK: nuggets
*/
#include <bits/stdc++.h>

using namespace std;

const int MAXN = 10;
int n, a[MAXN], dp[1000005];
int main()
{
	freopen("nuggets.in", "r", stdin);
	freopen("nuggets.out", "w", stdout);
	cin >> n;
	for(int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	// unbounded
	if(n==1) { cout << 0 << endl; return 0; }
	int g = a[0];
	for(int i = 1; i < n; i++)
	{
		g = __gcd(g, a[i]);
	}
	// unbounded
	if(g != 1)
	{
		cout << 0 << endl;
		return 0;
	}
	sort(a, a+n);
	int mx = a[n-1]*a[n-2]*__gcd(a[n-1], a[n-2]);
	dp[0] = 1;
	for(int i = 0; i < n; i++)
	{
		for(int j = a[i]; j <= mx; j++)
		{
			if(dp[j-a[i]]) dp[j] = 1;
		}
	}
	for(int i = mx; i > 0; i--)
	{
		if(!dp[i])
		{
			cout << i << endl;
			return 0;
		}
	}
	cout << 0 << endl;
	return 0;
}
