#include <bits/stdc++.h>

using namespace std;

int n, m, S, F, R, vis[100005], dist[100005], d2[100005], d3[100005];
vector<int> adj[100005];
int main()
{
	cin >> n >> m;
	for(int i = 0; i < m; i++)
	{
		int a, b; cin >> a >> b;
		--a; --b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	cin >> S >> F >> R;
	--S; --F; --R;
	queue<int> q;
	q.push(R); // find distances from r
	vis[R] = 1;
	while(!q.empty())
	{
		int tp = q.front();
		q.pop();
		for(int x : adj[tp])
		{
			// have to set visited as soon as you see the node and not when you process and
			// recurse through the node
			if(vis[x]) continue;
			vis[x] = 1;
			dist[x] = dist[tp]+1;
			q.push(x);
		}
	}
	for(int i = 0; i < n; i++)
	{
		d2[i] = -1;
		vis[i] = 0;
	}
	queue<int> q2;
	q2.push(S);
	vis[S] = 1;
	d2[S] = 0;
	d3[S] = dist[S];
	while(!q2.empty())
	{
		int tp = q2.front();
		q2.pop();
		vis[tp] = 1;
		for(int x : adj[tp])
		{
			int b = d2[tp] + 1;
			int c = min(d3[tp], dist[x]);
			if((d2[x] == -1) || ((b <= d2[x] && c > d3[x])))
			{
				vis[x] = 1;
				d2[x] = b;
				d3[x] = c;
				if(x != F) q2.push(x);
			}
		}
	}
	cout << d3[F] << endl;
}