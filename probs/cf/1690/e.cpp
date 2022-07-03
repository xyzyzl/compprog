#include <bits/stdc++.h>

#define int long long

using namespace std;

void solve()
{
	int n, k; cin >> n >> k;
	vector<int> v(n);
	for(int i = 0; i < n; i++)
	{
		cin >> v[i];
	}
	int sm = 0;
	for(int i = 0; i < n; i++) sm += v[i]/k;
	for(int i = 0; i < n; i++)
	{
		v[i] %= k;
	}
	sort(v.begin(), v.end());
	int ext = 0;
	for(int i = 0, j = n-1; i < j; i++, j--)
	{
		while(v[i] + v[j] < k && i < j)
		{
			i++;
		}
		if(i == j) break;
		ext++;
	}
	cout << ext + sm << endl;
}

signed main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	int t; cin >> t;
	while(t--)
	{
		solve();
	}
}
