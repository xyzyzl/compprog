// Time:
// Algorithms: 

#include <bits/stdc++.h>

#pragma GCC optimize("O3")

using namespace std;

#define MAXN 1005

#define FOR(i, n) for (int i = 0; i < n; i++)
#define FORR(j, i, n) for (int i = j; i < n; i++)
#define FORD(i, n) for (int i = n - 1; i >= 0; i--)
#define F1R(i, n) for (int i = 1; i <= n; i++)
#define F1RD(i, n) for (int i = n; i >= 1; i--)
#define pb push_back
#define mp make_pair
#define endl '\n'
#define DUEHOANG                  \
	ios_base::sync_with_stdio(0); \
	cin.tie(NULL);                \
	cout.tie(NULL)

#define fileio(in, out)      \
	freopen(in, "r", stdin); \
	freopen(out, "w", stdout);

#define ll long long
#define int ll
#define MOD (1e9*1)+7
#define MOD2 998244353
#define INF (1e16*1LL)+5LL

typedef set<int> si;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef pair<int, pii> iii;
typedef vector<pii> vii;
typedef vector<iii> viii;
typedef priority_queue<int> pqi;
typedef stack<int> sti;
typedef queue<int> qi;
typedef deque<int> di;
typedef map<int, int> mii;
#define f first
#define s second

#define LEFT(x) 2 * x
#define RIGHT(x) 2 * x + 1

#define bitinc(x) x&-x

const int MAX(int &a, int b)
{
	return a = max(a, b); 
}
const int MIN(int &a, int b)
{
	return a = min(a, b); 
}

int n, m, L, S, T, wt[MAXN], mat[MAXN][MAXN];
vii adj[MAXN];
void dijkstra(int src)
{
	fill(wt, wt + n, INF);

	set<pii> pq;
	pq.insert(mp(0, src));

	wt[src] = 0;

	int ct = 0;
	while (!pq.empty())
	{
		pii tp = *pq.begin();
		pq.erase(pq.begin());

		for (pii gu : adj[tp.s])
		{
			int w = gu.f;
			if(w <= 0) continue;
			int ind = gu.s;
			if (wt[tp.s] + w < wt[ind])
			{
				pq.erase(mp(wt[ind], ind)); /// you can't efficiently erase with a priority queue
				/// and you're processing way too many indices
				wt[ind] = wt[tp.s] + w;
				pq.insert(mp(wt[ind], ind));
			}
		}
	}
}

int pp[MAXN];
bool dijkstra2(int src)
{
	fill(wt, wt + n, INF);
	memset(pp, -1, sizeof pp);
	set<pii> pq;
	pq.insert(mp(0, src));

	wt[src] = 0;

	int ct = 0;
	while (!pq.empty())
	{
		pii tp = *pq.begin();
		pq.erase(pq.begin());

		for (pii gu : adj[tp.s])
		{
			int ind = gu.s;
			int w = abs(mat[tp.s][ind]);
			if (wt[tp.s] + w < wt[ind])
			{
				pq.erase(mp(wt[ind], ind)); /// you can't efficiently erase with a priority queue
				/// and you're processing way too many indices
				wt[ind] = wt[tp.s] + w;
				pp[ind] = tp.s;
				pq.insert(mp(wt[ind], ind));
			}
		}
	}
	return (wt[T] <= L);
}

void read()
{
	cin >> n >> m >> L >> S >> T;
	FOR(i, m)
	{
		int a, b, w;
		cin >> a >> b >> w;
		if(w)
		{
			adj[a].pb(mp(w,b));
			adj[b].pb(mp(w,a));
			mat[a][b] = w, mat[b][a] = w;
		} else 
		{
			adj[a].pb(mp(-1, b));
			adj[b].pb(mp(-1, a));
			mat[a][b] = -1, mat[b][a] = -1;
		}
	}
}

bool dijkstra_spam()
{
	// change some edge + rerun dijkstra
	dijkstra2(S);
	if(wt[T] == L) return true;
	int cur = T;
	bool found = 0;
	while(cur != S)
	{
		if(!found && mat[cur][pp[cur]] < 0)
		{
			ll d = abs(mat[cur][pp[cur]]);
			mat[cur][pp[cur]] = d + L - wt[T];
			mat[pp[cur]][cur] = d + L - wt[T];
			found = 1;
		}
		if(found) break;
		cur = pp[cur];
	}
	return false;
}

void solve()
{
	dijkstra(S);
	int q = wt[T];
	if(q < L)
	{
		cout << "NO" << endl;
		return;
	} else if(q == L)
	{
		cout << "YES" << endl;
		FOR(i, n)
		{
			for(pii w : adj[i])
			{
				if(i > w.s) continue;
				if(w.f < 0) w.f = INF;
				cout << i << " " << w.s << " " << w.f << endl;
			}
		}
		return;
	}
	if(!dijkstra2(S)) 
	{
		cout << "NO" << endl;
		return;
	}
	cout << "YES" << endl;
	cout.flush();
	int x = T;
	while(pp[x] != -1)
	{
		if(mat[x][pp[x]] == -1)
		{
			mat[x][pp[x]] = -2;
			mat[pp[x]][x] = -2;
		}
		x = pp[x];
	}
	FOR(i, n)
	{
		for(pii p : adj[i])
		{
			if(mat[i][p.s] == -1) mat[i][p.s] = INF, mat[p.s][i] = INF;
		}
	}
	x = T;
	while(pp[x] != -1)
	{
		if(mat[x][pp[x]] == -2)
		{
			mat[x][pp[x]] = -1;
			mat[pp[x]][x] = -1;
		}
		x = pp[x];
	}
	bool b = 0;
	while(!b)
	{
		b=dijkstra_spam();
	}
	FOR(i, n)
	{
		for(pii wer : adj[i])
		{
			if(i > wer.s) continue;
			cout << i << " " << wer.s << " " << abs(mat[i][wer.s]) << endl;
		}
	}
}

signed main()
{
	DUEHOANG;
	int t = 1;
	// cin >> t; // uncomment if it's multitest
	while(t--)
	{
		read();
		solve();
	}
	
}
