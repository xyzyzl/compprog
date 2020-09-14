#include <bits/stdc++.h>

using namespace std;

int n, P[100005];
vector<int> adj[100005];
int c1=-1, c2=-1,mn=1e9+7;
int dfs(int v, int p)
{
	int sz = 1, mx = 0;
	P[v] = p;
	for(int x : adj[v])
	{
		if(x==p) continue;
		int y = dfs(x,v);
		mx = max(mx, y);
		sz += y;
	}
	mx = max(mx, n-sz);
	if(mx < mn)
	{
		mn = mx;
		c1 = v;
		c2 = -1;
	} else if(mx == mn)
	{
		c2 = v;
	}
	return sz;
}
int lf = -1;
void fl(int v, int p)
{
	if(adj[v].size() == 1)
	{
		lf = v;
		return;
	}
	for(int x : adj[v])
	{
		if(x==p) continue;
		fl(x,v);
	}
}
int main()
{
	int t;
	cin >> t;
	while(t--)
	{
		cin >> n;
		for(int i = 0; i < n; i++)
		{
			adj[i].clear();
			P[i] = -1;
		}
		for(int i = 1; i < n; i++) 
		{
			int a,b;
			cin >> a >> b;
			--a; --b;
			adj[a].push_back(b);
			adj[b].push_back(a);
		}
		c1 = -1;
		c2 = -1;
		mn = 1e9+7;
		dfs(0, -1);
		if(c2 == -1) 
		{
			cout << 1 << " " << 1+adj[0][0] << endl;
			cout << 1 << " " << 1+adj[0][0] << endl;
			continue;
		}
		if(P[c1] != c2) swap(c1,c2);
		// find some leaf of subtree of c1
		fl(c1,c2);
		cout << 1+lf << " " << 1+P[lf] << endl;
		cout << 1+lf << " " << 1+c2 << endl;
	}
}
