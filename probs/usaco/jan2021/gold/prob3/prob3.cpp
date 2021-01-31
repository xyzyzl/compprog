#include <bits/stdc++.h>

using ll = long long;
using namespace std;
const int MAXN = 100005;
using pii = pair<int, int>;
using vi = vector<int>;
#define f first
#define s second
#define pb push_back
#define ins insert

int N, K, vis[MAXN];
ll M, X, R;
pii ab[MAXN];
vi V[MAXN], cy;
int swp[MAXN], swp2[MAXN];

void dfs(int v)
{
	vis[v] = 1;
	cy.pb(v);
	if(!vis[v]) dfs(swp[v]);
}

int main()
{
	cin >> N >> K >> M;
	for(int i = 0; i < N; i++)
	{
		V[i].pb(i);
		swp[i] = i;
	}
	for(int i = 0; i < K; i++)
	{
		cin >> ab[i].f >> ab[i].s;
		ab[i].f--; ab[i].s--;
	}
	for(int i = 0; i < K; i++)
	{
		V[swp[ab[i].f]].pb(ab[i].s);
		V[swp[ab[i].s]].pb(ab[i].f);
		swap(swp[ab[i].f], swp[ab[i].s]);
	}
	// swp[i] contains all the needed values
	X = M/K, R = M%K;
	for(int i = 0; i < N; i++) if(!vis[i])
	{
		dfs(i);
	}
}
