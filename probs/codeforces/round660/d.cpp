#include <bits/stdc++.h>

using namespace std;

int n, a[200005], b[200005], d[200005], m[200005];
vector<int> adj[200005];

vector<int> cur, nxt;
void dfs(int v, int p)
{
	if(m[v]) return;
	int ad = max(a[v], 0);
	if(a[v] > 0) cur.push_back(v+1);
	else nxt.push_back(v+1);
	for(int x : adj[v])
	{
		a[x] += ad;
		dfs(x, v);
	}
	m[v] = 1;
}

int main()
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
		d[b[i]-1]++;
		adj[i].push_back(--b[i]);
	}
	vector<int> s;
	for(int i = 0; i < n; i++)
	{
		if(d[i] == 0) s.push_back(i);
	}
	for(int x : s) dfs(x, -1);
	int ans = 0;
	for(int i = 0; i < n; i++)
	{
		ans += a[i];
	}
	cout << ans << endl;
	for(int x : cur) cout << x << " ";
	reverse(nxt.begin(), nxt.end());
	for(int x : nxt) cout << x << " ";
	cout << endl;
}
