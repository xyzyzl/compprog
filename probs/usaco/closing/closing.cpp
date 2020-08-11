#include <bits/stdc++.h>

using namespace std;

int n, m, a[200005];
int p[2005 * 2005], sz[2005 * 2005];
vector<int> adj[200005];
bool vis[200005], ok[200005];

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

int init()
{
    for(int i = 0; i < n; i++) p[i] = i;
    for(int i = 0; i < n; i++) sz[i] = 1;
}

int main()
{
	freopen("closing.in", "r", stdin);
	freopen("closing.out", "w", stdout);
	cin >> n >> m;
	for(int i = 0; i < m; i++)
	{
		int a, b;
		cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	init();
	for(int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	reverse(a, a+n);
	int cc = 0;
	for(int i = 0; i < n; i++)
	{
		vis[a[i]] = 1;
		++cc;
		for(int x : adj[a[i]]) if(vis[x])
		{
			if(!union_set(a[i], x))
			{
				continue;
			}
			--cc;
		}
		if(cc <= 1)
		{
			ok[i] = 1;
		}
	}
	reverse(ok, ok+n);
	for(int i = 0; i < n; i++)
	{
		if(ok[i]) cout << "YES" << endl;
		else cout << "NO" << endl;
	}
}