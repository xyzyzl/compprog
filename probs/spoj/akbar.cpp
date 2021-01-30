#include <bits/stdc++.h>

using namespace std;

int n, m, k, C[1000005];
vector<int> adj[1000005];
bool cannot = 0;

void dfs(int v, int p, int col, int dep)
{
	if(C[v] > 0 && C[v] != col) 
	{
		cannot = 1;
		return;
	}
	C[v] = col;
	if(dep == 0) return;
	for(int x : adj[v])
	{
		if(x == p) continue;
		dfs(x, v, col, dep-1);
	}
}

int main()
{
	int t; cin >> t;
	while(t--)
	{
		cin >> n >> m >> k;
		for(int i = 0; i < n; i++)
		{
			adj[i].clear();
			C[i] = 0;
			cannot = 0;
		}
		for(int i = 0; i < m; i++) 
		{
			int a, b; cin >> a >> b; --a; --b;
			adj[a].push_back(b);
			adj[b].push_back(a);
		}
		vector<pair<int, int> > V;
		for(int i = 0; i < k; i++)
		{
			int c, s; cin >> c >> s;
			--c;
			V.push_back({c, s});
		}
		int a = 0;
		for(auto x : V)
		{
			dfs(x.first, -1, ++a, x.second);
			if(cannot)
			{
				cout << "No" << endl;
				goto here;
			}
		}
		for(int i = 0; i < n; i++)
		{
			if(!C[i])
			{
				cout << "No" << endl;
				goto here;
			}
		}
		cout << "Yes" << endl;
		here:
		continue;
	}
}