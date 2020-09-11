#include <bits/stdc++.h>

#define MAXN 100005
using namespace std;
typedef pair<int, int> pii;
#define f first
#define s second

int n, sz[MAXN], in[MAXN], bit[2*MAXN], val[MAXN];
pii p[MAXN];
vector<int> adj[MAXN];

int ct=1;
void dfs(int v, int p)
{
	in[v]=ct++;
	sz[v] = 1;
	for(int x : adj[v])
	{
		if(x == p) continue;
		dfs(x,v);
		sz[v] += sz[x];
	}
}

void upd(int x, int v)
{
	while(x <= ct)
	{
		bit[x] += v;
		x += (x&-x);
	}
}

int  sum(int x)
{
	int k = 0;
	while(x > 0)
	{
		k += bit[x];
		x -= (x&-x);
	}
	return k;
}

int main()
{
	freopen("promote.in", "r", stdin);
	freopen("promote.out", "w", stdout);
	cin >> n;
	for(int i = 0; i < n; i++)
	{
		cin >> p[i].f;
		p[i].s = i;
	}
	for(int i = 1; i < n; i++)
	{
		int v;
		cin >> v;
		--v;
		adj[i].push_back(v);
		adj[v].push_back(i);
	}
	dfs(0, -1);
	sort(p, p+n);
	for(int i = n-1; i >= 0; i--)
	{
		int ans = sum(in[p[i].s] + sz[p[i].s]-1) - sum(in[p[i].s] - 1);
		val[p[i].s] = ans;
		upd(in[p[i].s]             ,  1);
	}
	for(int i = 0; i < n; i++) cout << val[i] << endl;
}