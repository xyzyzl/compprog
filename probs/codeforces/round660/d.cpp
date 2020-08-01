/*
Notes: 
Originally I got WA because I had processed the toposort in the wrong order. I forgot to consider
the case where edges went from negative a[u] -> negative a[v].

Then, I realized that my DFS was wrong. Instead of updating values after all leading nodes had been
processed, I updated the values upon the first traversal of the node. I should have let all parent 
nodes update the current node first and then update the child node.

Processing the toposort is correct once the graph is laid out correctly.
*/
#include <bits/stdc++.h>
 
using namespace std;
 
#define int long long
 
int n, a[200005], b[200005], d[200005], m[200005], ans;
vector<int> adj[200005];
 
void dfs(int v, int p)
{
	m[v] = 1;
	for(int x : adj[v])
	{
		if(m[x]) continue;
		dfs(x, v);
	}
	ans += a[v];
	if(b[v] != -1 && a[v] > 0)
	{
		a[b[v]] += a[v];
	}
}
 
int indeg[200005];
vector<int> res;
 
bool topo()
{
	// no need to reset the adjacency list and things
	multiset<int> st;
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
		res.push_back(u+1);
 
		for(int v : adj[u])
		{
			indeg[v]--;
			if(indeg[v] == 0) st.insert(v);
		}
		// cout << u << endl;
	}
	return 1;
}
 
signed main()
{
	cin >> n;
	for(int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	for(int i = 0; i < n; i++)
	{
		cin >> b[i];
		if(b[i] == -1) continue;
		d[--b[i]]++;
		adj[b[i]].push_back(i);
	}
	vector<int> s;
	for(int i = 0; i < n; i++)
	{
		if(!m[i]) dfs(i, -1);
	}
	int ans = 0;
	for(int i = 0; i < n; i++)
	{
		ans += a[i];
	}
	cout << ans << endl;
	for(int i = 0; i < n; i++)
	{
		adj[i].clear();
	}
	for(int i = 0; i < n; i++)
	{
		if(b[i] == -1) continue;
		if(a[i] <= 0)
		{
			indeg[i]++;
			adj[b[i]].push_back(i);
		}
		else
		{
			indeg[b[i]]++;
			adj[i].push_back(b[i]);
		}
	}
	topo();
	for(int x : res) cout << x << " ";
	cout << endl;
}