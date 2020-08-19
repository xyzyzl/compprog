// Time:
// Algorithms:

#include <bits/stdc++.h>

#pragma GCC optimize("O3")

using namespace std;

#define MAXN 1000005

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
#define MOD (1e9*1)+7
#define MOD2 998244353
#define INF (1e9*1)+5

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

int n, m, k;
vi adj[MAXN], ans;
int pos[MAXN];
vi rec;
vi col[2];

bool dfs(int v)
{
	pos[v] = rec.size();
	col[pos[v]%2].pb(v);
	rec.pb(v);
	int x = -1;
	for(int nx : adj[v])
	{
		if(pos[nx] != -1 && pos[v] - pos[nx] > 1)
		{
			MAX(x, pos[nx]);
		}
	}
	if(x != -1)
	{
		// cyclic
		FORR(x, i, pos[v]+1)
		{
			ans.pb(rec[i]);
		}
		return 1;
	}
	for(int nx : adj[v])
	{
		if(pos[nx] == -1)
		{
			if(dfs(nx)) return 1;
		}
	}
	rec.pop_back();
	return 0;
}

void read()
{
	cin >> n >> m >> k;
	FOR(i, m)
	{
		int a, b;
		cin >> a >> b;
		adj[a].pb(b);
		adj[b].pb(a);
	}
}

void solve()
{
	// first try to find cycle
	fill(pos, pos+n+1, -1);
	dfs(1);
	if(ans.empty())
	{
		cout << 1 << endl;
		// must be acyclic -> tree
		if(col[0].size() >= col[1].size())
		{
			FOR(i, (k+1)/2) cout << col[0][i] << " ";
		} else
		{
			FOR(i, (k+1)/2) cout << col[1][i] << " ";
		}
		cout << endl;
	} else
	{
		// cerr << "DSFIJODIJFOSDIFJOSDJFOWEHTFG O" << endl;
		// has cycle
		if(ans.size() <= k)
		{
			// can make cycle
			cout << 2 << endl << ans.size() << endl;
			FOR(i, ans.size())
			{
				cout << ans[i] << ' ';
			}
			cout << endl;
		} else {
			cout << 1 << endl;
			FOR(i, (k+1)/2) // must be *exactly* ceil(k/2) #s
			{
				cout << ans[i*2] << ' ';
			}
			cout << endl;
		}
	}
}

int main()
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
