#include <bits/stdc++.h>
 
#define MAXN 200005
#define int long long
using namespace std;
 
#define bitinc(x) (x&-x)
#define ll long long
#define INF (int)(1e9+7);
 
int n, arr[MAXN], in[MAXN], ot[MAXN], bit[2*MAXN];
vector<int> adj[MAXN];
 
int timer = 1;
void dfs(int v=0,int p=-1)
{
	in[v] = timer++;
	for(int x : adj[v])
	{
		if(x == p) continue;
		dfs(x,v);
	}
	ot[v] = timer;
}
 
int sum(int ind)
{
	int sm = 0;
	while(ind > 0)
	{
		sm += bit[ind];
		ind -= bitinc(ind);
	}
	return sm;
}
void upd(int ind, int val)
{
	while(ind <= n)
	{
		bit[ind] += val;
		ind += bitinc(ind);
	}
}
 
signed main()
{
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
	for(int i = 0; i < n; i++)
	{
		upd(in[i],  arr[i]);
		upd(ot[i], -arr[i]);
	}
	for(int que = 0; que < q; que++) // que que que
	{
		int t;
		cin >> t;
		if(t==1)
		{
			int s,x;
			cin >> s >> x;
			--s;
			upd(in[s], -arr[s]);
			upd(ot[s],  arr[s]);
			arr[s] = x;
			upd(in[s],  arr[s]);
			upd(ot[s], -arr[s]);
		} else
		{
			int s;
			cin >> s;
			--s;
			cout << sum(in[s]) << endl;
		}
	}
}