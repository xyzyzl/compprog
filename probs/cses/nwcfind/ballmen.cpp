#include <bits/stdc++.h>

using namespace std;

#define int long long

#define MAXN 100005
#define INF (int)(1e15 + 7)
#define FOR(i, n) for (int i = 0; i < n; i++)
#define FORD(i, n) for (int i = n - 1; i >= 0; i--)
#define FOBIR(i, n) for (int i = 1; i <= n; i++)
#define pb push_back
#define mp make_pair
#define endl '\n'
#define DUEHOANG                  \
	ios_base::sync_with_stdio(0); \
	cin.tie();                    \
	cout.tie()

typedef set<int> si;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef pair<int, pii> iii; // remember that iii.f is an integer and that iii.s is a pair
typedef priority_queue<int> pqi;
typedef stack<int> sti;
typedef queue<int> qi;
typedef deque<int> di;
typedef map<int, int> mii;
#define f first
#define s second
typedef vector<pair<int, int>> vii;

int n, m, dist[MAXN], pc[MAXN], st;
vector<iii> edges;
bool acy = false;
string bf(int src)
{
	FOR(i, n)
	dist[i] = INF;
	dist[src] = 0;
	FOR(i, n - 1)
	FOR(j, m)
	{
		int u = edges[j].s.f;
		int v = edges[j].s.s;
		int w = edges[j].f;
		if (dist[u] != INF && dist[u] + w < dist[v])
		{
			dist[v] = dist[u] + w;
			pc[v] = u;
		}
	}
	FOR(i, m)
	{
		int u = edges[i].s.f;
		int v = edges[i].s.s;
		int w = edges[i].f;
		// cout << u << endl;
		if (dist[u] != INF && dist[u] + w < dist[v])
		{
			// cout << pc[v] << endl;
			st = v;
			return "YES";
		}
	}
	acy = true;
	return "NO";
}

bool vis[MAXN];

signed main()
{
	DUEHOANG;
	fill(pc, pc + n, -1);
	cin >> n >> m;
	int sou = 0;
	FOR(i, m)
	{
		int a, b, w;
		sou = a;
		cin >> a >> b >> w;
		a--;
		b--;
		edges.pb(mp(w, mp(a, b)));
	}
	cout << bf(sou) << endl;
	if (!acy)
	{
		// cout << "AAAAAAAAAAAAAAAAAAAAAAAAAA" << endl;
		int joe = st;
		vi imax_orz;
		while (!vis[joe])
		{
			imax_orz.pb(joe + 1);
			vis[joe] = 1;
			joe = pc[joe];
		}
		fill(vis, vis + MAXN, 0);
		imax_orz.pb(joe + 1);
		reverse(imax_orz.begin(), imax_orz.end());
		for (int snek : imax_orz)
		{
			if (vis[snek])
			{
				cout << snek << " ";
				break;
			}
			cout << snek << " ";
			vis[snek] = 1;
		}
	}
}
