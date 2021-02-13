#include <bits/stdc++.h>

using namespace std;

using ll=long long;
using ld=long double;
using pac=pair<ld, int>;
void solve(int d)
{
	int n, m; cin >> n >> m;
	vector<ll> a(n+1), b(m+1);
	for(int i = 0; i < n; i++) cin >> a[i];
	for(int i = 0; i < m; i++) cin >> b[i];
	a[n] = -1;
	b[m] = -1;
	// package a into ap
	vector<pac> ap;
	for(int i = 0; i < n; i++)
	{
		pac cu = {a[i], 1};
		while(!ap.empty() && ap.back().first*cu.second < cu.first*ap.back().second)
		{
			cu.first += ap.back().first;
			cu.second += ap.back().second;
			ap.pop_back();
		}
		ap.push_back(cu);
	}
	int np = ap.size();
	ap.push_back({-1, 1});
	// package b into bp
	vector<pac> bp;
	for(int i = 0; i < m; i++)
	{
		pac cu = {b[i], 1};
		while(!bp.empty() && bp.back().first*cu.second < cu.first*bp.back().second)
		{
			cu.first += bp.back().first;
			cu.second += bp.back().second;
			bp.pop_back();
		}
		bp.push_back(cu);
	}
	int mp = bp.size();
	bp.push_back({-1, 1});
	// run 2p on ap and bp
	int i = 0, j = 0;
	vector<ll> c;
	int _ = 0, __ = 0;
	while(i < np || j < mp)
	{
		if(i < np && ap[i].first*bp[j].second > bp[j].first*ap[i].second)
		{
			int ___ = _;
			_ += ap[i].second;
			for(int k = ___; k < _; k++)  c.push_back(a[k]);
			i++;
		} else if(j < mp)
		{
			int ___ = __;
			__ += bp[j].second;
			for(int k = ___; k < __; k++) c.push_back(b[k]);
			j++;
		}
	}
	ll sm = 0;
	for(int i = 0; i < c.size(); i++)
	{
		sm += c[i]*(i+1ll);
		// cerr << c[i] << " ";
	}
	// cerr << endl;
	cout << "Case " << d << ": " << sm << endl;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);
	int t; cin >> t; for(int i = 0; i < t; i++)
	{
		solve(i+1);
	}
}