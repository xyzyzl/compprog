#include <bits/stdc++.h>

#define MAXN 100005
#define vi vector<int> 
#define msi multiset<int>
#define pb push_back
using namespace std;

int n, m;
vi adj[MAXN], eg[MAXN];

int indeg[MAXN];
vi res;

bool topo(int X)
{
	res.clear();
	for(int i = 0; i < n; i++)
	{
		adj[i].clear();
		indeg[i] = 0;
	}
	for(int i = 0; i < X; i++)
	{
		int k = eg[i].size();
		for(int j = 0; j < k-1; j++)
		{
			adj[eg[i][j]].pb(eg[i][j+1]);
			indeg[eg[i][j+1]]++;
		}
	}
	msi st;
	for(int i = 0; i < n; i++)
	{
		if(!indeg[i])
		{
			st.insert(i);
			// cout << i << endl;
		}
	}
	for(int i = 0; i < n; i++)
	{
		int u = *st.begin();
		if(st.empty()) return 0;
		st.erase(st.begin());
		res.pb(u+1);
		for(int v : adj[u])
		{
			indeg[v]--;
			if(indeg[v] == 0) st.insert(v);
		}
		// cout << u << endl;
	}
	return 1;
}
int main()
{
	freopen("milkorder.in", "r", stdin);
	freopen("milkorder.out", "w", stdout);
	cin >> n >> m;
	for(int i = 0; i < m; i++)
	{
		int k; cin >> k;
		for(int j = 0; j < k; j++) 
		{
			int a; cin >> a; --a;
			eg[i].pb(a);
		}
	}
	int lo = 0, hi = m;
	while(lo < hi-1)
	{
		int mid = (lo+hi)/2;
		if(topo(mid)) lo = mid;
		else hi = mid;
	}
	topo(lo);
	for(int k : res) cout << k << (k == res.back() ? '\n' : ' ');
}