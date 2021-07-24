#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve()
{
	int n; cin >> n;
	vector<ll> x(n), ans(n);
	vector<int> cbits(31);

	for(int i = 0; i < n; i++) cin >> x[i];
	ll now = x[0];
	int k = 0;
	while(now > 0)
	{
		cbits[k] = now % 2;
		now /= 2;
		k++;
	}
	for(int i = 1; i < n; i++)
	{
		now = x[i];
		for(int k = 0; k <= 30; k++)
		{
			int bt = now % 2;
			if(!bt && cbits[k]) 
			{
				// add the current bit
				ans[i] += (1ll << k);
			}
			cbits[k] = max(cbits[k], bt);
			now /= 2;
		}
	}
	for(int i = 0; i < n; i++) cout << ans[i] << ' ';
	cout << endl;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t; cin >> t; while(t--) solve();
}
