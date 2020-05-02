#include <bits/stdc++.h>

using namespace std;

int dist[100005];
vector<int> adj[100005];
void dfs(int v, int p, int dep)
{
	dist[v] = dep;
	for(int i : adj[v])
	{
		if(i == p) continue;
		dfs(i, v, dep^1);
	}
}

int main()
{
	int n;
	cin >> n;
	vector<int> leaf;
	for(int i = 1; i < n; i++)
	{
		int a, b;
		cin >> a >> b;
		--a; --b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	int rt = -1;
	for(int i = 0; i < n; i++)
	{
		if(adj[i].size() == 1)
		{
			if(rt == -1) rt = i;
			leaf.push_back(i);
		}
	}
	dfs(rt, -1, 0); // find distance to all leaves
	int par = 0;
	bool bad = 0;
	for(int x : leaf)
	{
		if(x == rt) continue;
		if(dist[x] != par) bad = 1;
	}
	if(bad) cout << 3 << " ";
	else cout << 1 << " ";
	int ct = 0;
	for(int i = 0; i < n; i++)
	{
		for(int x : adj[i])
		{
			if(adj[x].size() == 1)
			{
				ct++;
				break;
			}
		}
	}
	cout << (n-1) - leaf.size() + ct << endl;
}
