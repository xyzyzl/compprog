#include <bits/stdc++.h>

using namespace std;

void solve()
{
	int n; cin >> n;
	vector<int> a(n), b(n);
	for(int i = 0; i < n; i++) cin >> a[i];
	for(int j = 0; j < n; j++) cin >> b[j];
	// now the cost of the ai^2's will always be the same regardless
	// of how we swap t, the only thing that changes now is the cost
	// of a_i*a_j terms.
	int sa = 0, smn = 0, smx = 0;
	for(int i = 0; i < n; i++)
	{
		if(a[i] > b[i]) swap(a[i], b[i]);
		sa += a[i]*a[i] + b[i]*b[i];
		smn += a[i];
		smx += b[i]; 
	}
	bitset<10005> dp;
	dp[0] = 1;
	for(int i = 0; i < n; i++)
	{
		dp |= dp << (b[i] - a[i]);
	}
	int ans = smn*smn + smx*smx;
	for(int i = 0; i <= smx - smn; i++)
	{
		if(dp[i])
		{
			ans = min(ans, (smn+i)*(smn+i) + (smx-i)*(smx-i));
		}
	}
	cout << sa * (n-2) + ans << endl;
}

int main()
{
	int t; cin >> t;
	while(t--)
	{
		solve();
	}
}