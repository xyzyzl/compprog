#include <bits/stdc++.h>

using ll = long long;
using namespace std;
const int MAXN = 100005;
using pii = pair<int, int>;
using vi = vector<int>;
using vii = vector<pii>;
#define f first
#define s second
#define pb push_back
#define ins insert

int N, K, vis[MAXN], ans[MAXN], np, ct[MAXN];
ll M, X, R;
pii ab[MAXN*2];
vii V[MAXN];
vi cy;
int swp[MAXN], swp2[MAXN];

// want to get exactly k swaps
void add(int v, int k)
{
	for(pii x : V[v])
	{
		if(x.s > k) return;
		if(!ct[x.f]) np++;
		ct[x.f]++;
	}
}

void erase(int v, int k)
{
	for(pii x : V[v])
	{
		if(x.s > k) return;
		if(ct[x.f]==1) np--;
		ct[x.f]--;
	}
}

void dfs(int v)
{
	vis[v] = 1;
	cy.pb(v);
	if(!vis[swp2[v]]) dfs(swp2[v]);
}

signed main()
{
	cin >> N >> K >> M;
	for(int i = 0; i < N; i++)
	{
		V[i].pb({i,0});
		swp[i] = i;
	}
	for(int i = 0; i < K; i++)
	{
		cin >> ab[i].f >> ab[i].s;
		ab[i].f--; ab[i].s--;
	}
	for(int i = 0; i < K; i++)
	{
		V[swp[ab[i].f]].pb({ab[i].s,i+1});
		V[swp[ab[i].s]].pb({ab[i].f,i+1});
		swap(swp[ab[i].f], swp[ab[i].s]);
	}
	for(int i = 0; i < N; i++) swp2[swp[i]]=i;
	// swp[i] contains all the needed values
	X = M/K, R = M%K;
	for(int i = 0; i < N; i++) if(!vis[i])
	{
		dfs(i);
		ll X_t = X, R_t = R; if(X_t >= cy.size())
		{
			X_t = cy.size(); R_t = 0;
		}
		int x = X_t-1;
		for(int j = 0; j < X_t; j++) add(cy[j], K);
		for(int j = 0; j < cy.size(); j++)
		{
			int nx = (x+1)%cy.size();
			add(cy[nx], R_t);
			ans[cy[j]] = np;
			erase(cy[nx], R_t);
			erase(cy[j], K);
			add(cy[nx], K);
			x=nx;
		}
		for(int j = 0; j < X_t; j++) erase(cy[j], K);
		cy.clear();
	}
	for(int i = 0; i < N; i++)
	{
		cout << ans[i] << endl;
	}
}
