#include <bits/stdc++.h>
#define int long long

using namespace std;

int n, x, a[200005];
signed main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n >> x;
	for(int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	int lo = 0;
	long long ct = 0;
	long long sum = 0;
	for(int i = 0; i < n; i++)
	{
		sum += a[i];
		while(lo < n && lo < i && sum > x)
		{
			sum -= a[lo++];
		}
		if(sum == x) ++ct;
	}
	cout << ct << endl;
}