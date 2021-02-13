#include <bits/stdc++.h>

const int MAXN = 100005;
const int MOD = 1e9+7;
using ll=long long;
using namespace std;
using pii=pair<int, int>;
using vi = vector<int>;
#define f first
#define s second
#define pb push_back

// need to topo sort to find the order and then use dp along edges
int N, M, dp[MAXN], vis[MAXN], indeg[MAXN];
vi adj[MAXN], res;

bool topo()
{
	multiset<int> st;
	for(int i = 0; i < N; i++) if(!indeg[i]) st.insert(i);
	for(int i = 0; i < N; i++)
	{
		int u = *st.begin(); if(st.empty()) return 0; st.erase(st.begin());
		res.pb(u);
		for(int v : adj[u])
		{
			--indeg[v];
			if(!indeg[v]) st.insert(v);
		}
	}
	return 1;
}

int main()
{
	cin >> N >> M;
	for(int i = 0; i < M; i++)
	{
		int a, b; cin >> a >> b; --a; --b;
		if(b==0) continue; // no cycles and anything before is irrelevant
		adj[a].pb(b);
		indeg[b]++;
	}
	topo(); // we are assuming 1 is returned
	dp[0] = 1;
	for(int x : res)
	{
		vis[x] = 1;
		for(int y : adj[x])
		{
			if(!vis[y]) dp[y] = (dp[y] + dp[x])%MOD;
		}
	}
	cout << dp[N-1] << endl;
}