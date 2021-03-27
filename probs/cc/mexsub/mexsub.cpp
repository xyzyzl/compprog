#include <bits/stdc++.h>

const int MOD = 1000000007;
using namespace std;

void solve()
{
	int N;
	cin >> N;
	vector<int> a(N+1), f(N+5), id(N+5);
	vector<int> dp(N+5), pdp(N+5); // dp[i] = # of ways to divide up to a[i] such that MEX = m.
	multiset<int> ind;
	for(int i = 1; i <= N; i++)
	{
		cin >> a[i];
		f[a[i]]++;
		id[a[i]] = 0;
	}
	int M = 0;
	while(f[M]) M++;
	if(M == 0)
	{
		int x = 1;
		for(int i = 1; i < N; i++)
		{
			x = (x*2)%MOD;
		}
		cout << x << endl;
		return;
	}
	dp[0] = 1;
	pdp[0] = 1;
	for(int i = 0; i < M; i++) ind.insert(0);
	for(int i = 1; i <= N; i++)
	{
		if(a[i] < M)
		{
			auto it = ind.find(id[a[i]]);
			ind.erase(it);
			id[a[i]] = i;
			ind.insert(id[a[i]]);
		}
		int pid = (*ind.begin());
		if(pid != 0)
		{
			dp[i] = pdp[pid-1];
		}
		pdp[i] = (pdp[i-1]+dp[i])%MOD;
	}
	cout << dp[N] << endl;
}

int main()
{
	int t; cin >> t;
	while(t--) solve();
}
