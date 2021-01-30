#include <bits/stdc++.h>

#define MAXN 100005
#define bitinc(x) (x&-x);

using namespace std;

int n,arr[MAXN],bit[4*MAXN],in[MAXN],ot[MAXN],par[MAXN][22];
vector<int> adj[MAXN];

int timer = 1;
// does initial DFS to find the time in/out for each subtree-range.
void dfs(int v=0,int p=-1)
{
	in[v] = timer++;
	par[v][0] = p;
	for(int i = 1; i < 22; i++)
		par[v][i] = par[par[v][i-1]][i-1];
	for(int x : adj[v])
	{
		if(x == p) continue;
		dfs(x,v);
	}
	ot[v] = timer++;
}

// prefix xor. reversable = done onto itself
int XOR(int ind)
{
	int xo = 0;
	while(ind > 0)
	{
		xo ^= bit[ind];
		ind -= bitinc(ind);
	}
	return xo;
}
void upd(int ind, int val)
{
	while(ind <= timer)
	{
		bit[ind] ^= val;
		ind += bitinc(ind);
	}
}

bool anc(int u, int v)
{
	return (in[u] <= in[v] && ot[u] >= ot[v]);
}

// method finding all lca's
int lca(int u, int v)
{
	if(anc(u,v))
		return u;
	for(int i = 21; i >= 0; i--)
	{
		if(par[u][i] >= 0 && !anc(par[u][i], v))
			u = par[u][i];
	}
	return par[u][0];
}

int main()
{
	freopen("cowland.in", "r", stdin);
	freopen("cowland.out", "w", stdout);
	int q;
	cin >> n >> q;
	for(int i = 0; i < n; i++) cin >> arr[i];
	for(int i = 1; i < n; i++) 
	{
		int u,v;
		cin >> u >> v;
		--u; --v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	dfs();
	// add each vertex query right now.
	for(int i = 0; i < n; i++)
	{
		upd(in[i], arr[i]);
		upd(ot[i], arr[i]);
	}
	// rep. for each query
	for(int que = 0; que < q; que++)
	{
		int t;
		cin >> t;
		if(t==1)
		{
			int s, x;
			cin >> s >> x;	
			--s;
			// erase the initial arr[s] value.
			upd(in[s], arr[s]);
			upd(ot[s], arr[s]);
			arr[s] = x;
			// update the arr[s] value to x.
			upd(in[s], arr[s]);
			upd(ot[s], arr[s]);
		} else 
		{
			int u,v;
			cin >> u >> v;
			--u; --v;
			int w = lca(u,v);
			cout << ((XOR(in[u]) ^ XOR(in[v])) ^ arr[w]) << endl;
		}
	}
}