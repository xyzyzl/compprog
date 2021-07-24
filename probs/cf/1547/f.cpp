
#include <bits/stdc++.h>

using namespace std;

const int MAXA = 1e6;
int vis[MAXA+1];
vector<int> ps;

void solve()
{
	int n; cin >> n;
	vector<int> a(n);
	int g = __gcd(a[0], a[1]);
	for(int i = 0; i < n; i++) 
	{
		cin >> a[i];
		g = __gcd(a[i], g);
	}
	vector<set<int> > factors(n);
	for(int i = 0; i < n; i++)
	{
		int norm = a[i] / g;
		while(norm != 1)
		{
			factors[i].insert(vis[norm]);
			norm /= vis[norm];
		}
	}
	
	int ans = 0;
	for(int i = 0; i < n; i++)
	{
		for(int p : factors[i])
		{
			int l = (i-1+n)%n, r = i;
			int ct = 0;
			while(factors[l].count(p))
			{
				factors[l].erase(p);
				--l; ++ct;
				if(l < 0) l += n;
			}
			while(factors[r].count(p))
			{
				if(r != i) factors[r].erase(p);
				++r; ++ct;
				if(r > n-1) r -= n;
			}
			ans = max(ans, ct);
		}
	}
	cout << ans << endl;
}

int main()
{
	vis[1] = 1;
	for(int i = 2; i <= MAXA; i++)
	{
		if(vis[i] == 0)
		{
			vis[i] = i;
			ps.push_back(i);
			for(int j = i; j <= MAXA; j += i)
			{
				vis[j] = i;
			}
		}
	}
	int t; cin >> t;
	while(t--) solve();
}
