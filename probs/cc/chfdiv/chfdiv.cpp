#include <bits/stdc++.h>

using namespace std;
using ll = long long;

ll N, K;
vector<int> ps;
bool vis[1000005];

const int MOD = 1e9+7;
ll mul(ll a, ll b, int mod = MOD) { return (ll)a * b % mod; }
ll po(ll b, ll p, int mod = MOD) { return !p ? 1 : mul(po(mul(b, b, mod), p / 2, mod), p & 1 ? b : 1, mod); }

void solve()
{
	cin >> N >> K;
	ll prod = 1;
	for(int p : ps)
	{
		if(p > N) break;
		if(K%p==0) continue;
		ll cur = p, cum = 0;
		while(cur <= N)
		{
			cum += N/cur;
			cur *= p;
		}
		prod = mul(prod, po(p, cum));
	}
	cout << prod << endl;
}

int main()
{
	for(int i = 2; i <= 1000000; i++)
	{
		if(vis[i]) continue;
		ps.push_back(i);
		for(int j = i; j <= 1000000; j+=i)
		{
			vis[j] = 1;
		}
	}
	int T; cin >> T;
	while(T--) solve();
}