#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> // pbds
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/detail/standard_policies.hpp>

using namespace __gnu_pbds;
using namespace std;
using ll = long long;

typedef pair<ll, ll> pii;
typedef tree<pii, null_type, less<pii>, rb_tree_tag, tree_order_statistics_node_update> os;

void solve()
{
	int n; cin >> n;
	vector<int> V(n), W(n+1), ans;
	for(int i = 0; i < n; i++) cin >> V[i];
	set<ll> S;
	set<pii> O;
	S.insert(0);
	for(int i = 0; i < n; i++)
	{
		int x = (i+1)%n;
		S.insert(x);
		if(__gcd(V[i], V[x]) == 1)
		{
			O.insert({i, x});
		}
	}
	while(O.size())
	{
		// cerr << O.size() << endl;
		set<pii> O2;
		while(O.size())
		{
			ll x = O.begin()->first;
			ll y = O.begin()->second;
			// cerr << x << " " << y << endl;
			if(W[x] || W[y])
			{
				O.erase(O.find({x, y}));
				continue;
			}
			ans.push_back(y);
			O.erase(O.find({x, y}));
			auto it = S.find(y);
			++it;
			W[y] = 1;
			if(S.size() > 1)
			{
				ll z = (it == S.end() ? *S.begin() : *it);
				if(O.find({y, z}) != O.end())
				{
					O.erase(O.find({y, z}));
				}
				if(__gcd(V[x%n], V[z%n]) == 1) if(!W[z]) O2.insert({x, z%n});
			}
			S.erase(S.find(y));
		}
		// insert all new bads after reset
		for(auto i : O2)
		{
			O.insert(i);
		}
	}
	cout << ans.size() << ' ';
	for(auto i : ans) cout << i+1 << ' ';
	cout << endl;
}

int main()
{
	int t; cin >> t; while(t--) solve();
}
