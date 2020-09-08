#include <bits/stdc++.h>

#define MAXN 200005
using namespace std;

#define bitinc(x) (x&-x)

int n, arr[MAXN], tin[MAXN], bit[2*MAXN];
vector<int> adj[MAXN];

void dfs(int v=0,int p=-1)
{
	for(int x : adj[v])
	{
		if(x == p) continue;
		dfs(x,v);
	}
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
int main()
{
	cin >> n;
	for(int i = 0; i < n; i++) cin >> arr[i];
	for(int i = 1; i < n; i++)
	{
		int u,v;
		cin >> u >> v;
		--u; --v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
}