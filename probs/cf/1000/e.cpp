#include <bits/stdc++.h>

using namespace std;

int n, m, ind[300005], low[300005], d0[300005], t;
vector<pair<int, int> > adj[300005];
vector<int> adj2[300005];
vector<pair<int, int> > te, br;

int p[2005 * 2005], sz[2005 * 2005];

int find_set(int i)
{
	return (p[i] == i) ? i : (p[i] = find_set(p[i]));
}

bool union_set(int i, int j)
{
	int x = find_set(i);
	int y = find_set(j);
	if (x == y)
		return false;
	p[x] = p[y] = x;
	sz[x] += sz[y];
	return true;
}

void init()
{
	for (int i = 0; i < n; i++)
		p[i] = i;
	for (int i = 0; i < n; i++)
		sz[i] = 1;
}

void dfs(int v, int ei)
{
	ind[v] = low[v] = ++t;
	for(auto x : adj[v])
	{
		// cerr << v << " " << x.first << " " << x.second << " " << ei << endl;
		if(x.second == ei) continue;
		if(ind[x.first] == -1) // tree edge
		{
			te.push_back({v, x.first});
			dfs(x.first, x.second);
			low[v] = min(low[v], low[x.first]);
		} else // back edge
		{
			low[v] = min(low[v], ind[x.first]);
		}
	}
}

void d()
{
	queue<int> q;
	q.push(0);
	d0[0] = 1;
	while(!q.empty())
	{
		int t = q.front();
		q.pop();
		for(int i : adj2[t])
			if(!d0[i])
			{
				q.push(i);
				d0[i] = d0[t] + 1;
			}
	}
	int b = 0;
	for(int i = 0; i < n; i++)
	{
		if(d0[b] < d0[i]) b=i;
	}
	fill(d0, d0+n, 0);
	d0[b] = 1;
	while(!q.empty()) q.pop();
	q.push(b);
	while(!q.empty())
	{
		int t = q.front();
		q.pop();
		for(int i : adj2[t])
			if(!d0[i])
			{
				q.push(i);
				d0[i] = d0[t] + 1;
			}
	}
	int mx = 0;
	for(int i = 0; i < n; i++)
	{
		mx = max(mx, d0[i]-1);
	}
	cout << mx << endl;
}

int main()
{
	cin >> n >> m;
	int neg = 0;
	memset(ind, -1, sizeof ind);
	init();
	for(int i = 0; i < m; i++)
	{
		int u, v; cin >> u >> v; --u; --v;
		adj[u].push_back({v, ++neg});
		adj[v].push_back({u, neg});
	}
	dfs(0, -1);
	/*
	for(int i = 0; i < n; i++)
	{
		cout << low[i] << " ";
	}
	cout << endl;
	for(int i = 0; i < n; i++)
	{
		cout << ind[i] << " ";
	}
	cout << endl;
	*/
	for(auto e : te)
	{
		if(low[e.second] == ind[e.second]) br.push_back(e);
		else union_set(e.first, e.second);
	}
	for(auto e : br)
	{
		int u = find_set(e.first);
		int v = find_set(e.second);
		adj2[u].push_back(v);
		adj2[v].push_back(u);
	}
	// find the fucking diameter of this fucking tree
	d();
}