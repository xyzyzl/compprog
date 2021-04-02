#include <bits/stdc++.h>

using namespace std;
using ll=long long;
const int MAXN = 100005;

int N;
string S;
ll ans;
vector<int> adj[MAXN];

int dfs(int v, int p, int c)
{
	ll cur = 0;
	int ac = S[v]-'0';
	for(int x : adj[v])
	{
		if(x != p) cur+= dfs(x, v, !c);
	}
	if(c != ac)
	{
		cur += (!c?1:-1);
	}
	ans += abs(cur);
	return cur;
}

void solve()
{
	ans=0;
	cin >> N;
	for(int i = 0; i < N; i++) adj[i].clear();
	for(int i = 1; i < N; i++) 
	{
		int a, b; cin >> a >> b;
		--a; --b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	cin >> S;
	ll _ans = LLONG_MAX;
	for(int red = 0, tmp = dfs(0, -1, red); red < 2; red++, ans=0, tmp = dfs(0, -1, red))
		if(!tmp) _ans = min(_ans, ans);
	cout << (_ans < LLONG_MAX ? _ans : -1) << endl;
}

int main()
{
	int t; cin >> t;
	while(t--) solve();
}
