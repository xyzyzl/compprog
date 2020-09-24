#include <bits/stdc++.h>

using namespace std;

int n, x, dep[1005];
vector<int> adj[1005];


int main()
{
	int t;
	cin >> t;
	while(t--)
	{
		cin >> n >> x;
		for(int i = 1; i <= n; i++) 
			adj[i].clear();
		for(int i = 1; i < n; i++)
		{
			int u,v;
			cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		if(adj[x].size() <= 1) cout << "Ayush" << endl;
		else cout << (n%2 ? "Ashish" : "Ayush") << endl;
	}

}
