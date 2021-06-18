#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<ll, ll>;
#define f first
#define s second
const int MAXN = 200005;

int n;
struct pt
{
	int n1, d1, n2, d2;
} v[MAXN];

pii simp(ll num, ll den)
{
	ll k = __gcd(num, den);
	return {num/k, den/k};
}

vector<pii> adj[MAXN];
map<pii, int> frac;
vector<int> vis;
vector<pii> ans;

int dfs(int v)
{
	vis[v] = 1;
	int cur = -1;
	for(auto it : adj[v])
	{
		if(vis[it.f]==1) continue;
		dfs(it.f);
		int nx = it.s;
		int tmp = dfs(it.f);
		if(!vis[it.f]) if(tmp != -1)
		{
			ans.push_back({nx, tmp});
			nx = -1;
		} 
		if(~nx)
		{
			if(cur != -1)
			{
				ans.push_back({cur, nx});
				cur = -1;
			} else 
			{
				cur = nx;
			}
		}
	}
	vis[v] = 2; // out of stack
	return cur;
}

int main()
{
	cin >> n;
	for(int i = 0; i < n; i++)
	{
		cin >> v[i].n1 >> v[i].d1 >> v[i].n2 >> v[i].d2;
		pii you;
		you = simp(v[i].n1, v[i].d1);
		v[i].n1 = you.first;
		v[i].d1 = you.second;
		if(!frac[you])
		{
			int k = frac.size();
			frac[you]=k;
		}
		pii you1;
		you = simp(v[i].n2, v[i].d2);
		v[i].n2 = you.first;
		v[i].d2 = you.second;
		if(!frac[you])
		{
			int k = frac.size();
			frac[you]=k;
		}
		adj[frac[you1]].push_back({frac[you], i});
		adj[frac[you]].push_back({frac[you1], i});
	}
	vis.resize(frac.size());
	for(int i = 0; i < frac.size(); i++)
	{
		if(!vis[i]) dfs(i);
	}
	cout << ans.size() << endl;
	for(auto x : ans)
	{
		cout << x.f+1 << " " << x.s+1 << endl;
	}
}