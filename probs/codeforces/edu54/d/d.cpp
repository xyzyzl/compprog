#include <bits/stdc++.h>
 
using namespace std;
 
#define int long long
 
#define MAXN 300005
#define INF (int)(1e9+7);
#define FOR(i, n) for(int i = 0; i < n; i++)
#define FORD(i, n) for(int i = n-1; i >= 0; i--)
#define FOBIR(i, n) for(int i = 1; i <= n; i++)
#define pb push_back
#define mp make_pair
#define endl '\n'
#define DUEHOANG ios_base::sync_with_stdio(0); cin.tie(); cout.tie()
 
typedef set<int> si;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef priority_queue<int> pqi;
typedef stack<int> sti;
typedef queue<int> qi;
typedef deque<int> di;
typedef map<int, int> mii;
#define f first
#define s second
typedef vector<pair<int, int> > vii;
 
map<pii, int> edg;
 
bool seen[MAXN];
 
vector<pair<int, pii> > adj[MAXN];
vi e;
int wt[MAXN], par[MAXN];
int n, m, k;
void not_prim(int src)
{
	fill(wt, wt + n, 100000000000000007);
    fill(par, par + n, -1);
 
	set<pii> pq;
	pq.insert(mp(0, src));
 
	wt[src] = 0;
 
    int ct = 0;
	while (!pq.empty())
	{
		pii tp = *pq.begin();
		pq.erase(pq.begin());
 
        if(par[tp.s]!=-1)
		{
			if(!seen[par[tp.s]])
			{
				ct++;
				e.pb(par[tp.s]+1);
			}
			seen[par[tp.s]] = 1;
		}
        if(ct == k) return; // stop!
 
		for (pair<int, pii> gu : adj[tp.s])
		{
			int w = gu.s.f;
			int ind = gu.s.s;
			if (wt[tp.s] + w < wt[ind])
			{
				pq.erase(mp(wt[ind], ind));
				wt[ind] = wt[tp.s] + w;
				pq.insert(mp(wt[ind], ind));
				par[ind] = gu.f;
			}
		}
	}
}