#include <bits/stdc++.h>

using namespace std;

int n, m;
vector<int> adj[200005];
int p[200005], sz[200005], c[200005], k[200005];
bool vis[200005];
queue<int> q;

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
	if(x>y) swap(x,y);
	// collapse adj list
	p[x] = p[y] = x;
	for(int i : adj[y]) adj[x].push_back(i);
	if(adj[x].size() >= 2) q.push(x);
	adj[y].clear();
	sz[x] += sz[y];
	return true;
}

void init()
{
	for(int i = 0; i < n; i++) p[i] = i;
	for(int i = 0; i < n; i++) sz[i] = 1;
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);
	freopen("fcolor.in", "r", stdin);
	freopen("fcolor.out", "w", stdout);
	cin >> n >> m;
	for(int i = 0; i < m; i++)
	{
		int a,b;
		cin >> a >> b;
		--a;--b;
		adj[a].push_back(b);
	}
	init();
	for(int i = 0; i < n; i++) if(adj[i].size() >= 2) q.push(i);
	while(!q.empty())
	{
		int x = q.front();
		if(adj[x].size() < 2) q.pop();
		else
		{
			int a = adj[x].back();
			adj[x].pop_back();
			if(!adj[x].size()) break;
			int b = adj[x].back();
			union_set(a,b);
		}
	}
	int ct = 0;
	for(int i = 0; i < n; i++)
	{
		k[i] = find_set(i);
	}
	for(int i = 0; i < n; i++)
	{
		if(!vis[k[i]])
		{
			c[k[i]] = ++ct;
			vis[k[i]] = 1;
		}
	}
	for(int i = 0; i < n; i++)
	{
		cout << c[k[i]] << endl;
	}
}
