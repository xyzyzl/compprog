#include <bits/stdc++.h>

using namespace std;
using ll = long long;
#define f first
#define s second

int n;
// d[i][j] is shortest path from i-> j, e[i][j] is the largest difference between the shortest path i -> j and some triple edge weight.
ll d[605][605], e[605][605];
int main()
{
	int m;
	cin >> n >> m;
	vector<pair<ll, pair<int, int> > > V;
	// check for typos/array bounds a lot more. also check and see if you meet the timelimit.
	for(int i = 0; i < n; i++) for(int j = 0; j < n; j++) d[i][j] = 1e15;
	for(int i = 0; i < m; i++)
	{
		int u, v; cin >> u >> v;
		--u; --v;
		int w; cin >> w;
		d[u][v] = w;
		d[v][u] = w;
		V.push_back({w, {u, v}});
	}
	// find the shortest path here w/ floyd
	for(int k = 0; k < n; k++) for(int i = 0; i < n; i++) for(int j = 0; j < n; j++) d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
	int q; cin >> q;
	for(int i = 0; i < q; i++)
	{
		int u, v, l; cin >> u >> v >> l;
		--u; --v;
		// set the diff initially to just l for the difference between u and v. we can call e the tolerance factor: how much weight is tolerated
		// before we go over the boundary.
		e[u][v] = l;
		e[v][u] = l;
	}
	// we decrease the tolerance level by d[k][j] when we relax i->k to i->j.
	for(int k = n-1; k >= 0; k--) for(int i = 0; i < n; i++) for(int j = 0; j < n; j++) e[i][j] = e[j][i] = max(e[i][j], e[i][k]-d[k][j]);
	int ans = 0;
	// then we match tolerances to edges to check compatibility.
	for(auto x : V)
	{
		ans += (e[x.s.f][x.s.s] >= x.f);
	}
	// this is quite straightforward and doesn't really need a rigorous proof, just proof by ac.
	cout << ans << endl;
}
