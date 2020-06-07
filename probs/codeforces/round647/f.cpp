// Time:
// Algorithms: 

#include <bits/stdc++.h>

#pragma GCC optimize("O3")

using namespace std;

#define MAXN 500005

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

int n, parts[MAXN][2];
void read()
{
	cin >> n;
	FOR(i, n)
	{
		cin >> parts[i][0] >> parts[i][1];
	}
}

vii adj[1 << 20];
vi vis((1 << 20));

void upd(int src)
{
	vis[src] = 1;
	for(pii x : adj[src])
	{
		if(!vis[x.f]) upd(x.f);
	}
}

bool find_eulerian(int mask)
{
	FOR(i, mask+1) 
	{
		vis[i] = 0;
		adj[i].clear();
	}
	FOR(i, n)
	{
		int u = parts[i][0] & mask;
		int v = parts[i][1] & mask;
		adj[u].pb(mp(v, 2*i));
		adj[v].pb(mp(u, 2*i+1));
	}
	// each individual mask has a different resulting graph
	// we need to see which ends match up to which
	int x = 0;
	// cout << adj[mask].size() << endl;
	FOR(i, mask+1)
	{
		if(adj[i].size() % 2) // can't have odd things in eulerian cycle
		{
			return 0;
		}
		if(!vis[i] && adj[i].size())
		{
			++x;
			upd(i); // update the component
		}
	}
	// cout << x << endl;
	return x == 1;
}

vi ret;
void search(int v, int p)
{
	while(adj[v].size())
	{
		pii x = adj[v].back();
		adj[v].pop_back();

		if(vis[x.s / 2]) continue;
		vis[x.s / 2] = 1;
		search(x.f, x.s);
	}

	if(p != -1) // add each pair -- must be linked !!!!
	{
		ret.pb((p^1)+1);
		ret.pb(p+1);
	}
}

void trace(int mask)
{
	FOR(i, n)
	{
		vis[i] = 0;
	}
	FOR(i, mask+1)
	{
		if(adj[i].size())
		{
			// exists
			search(i, -1);
			break;
		}
	}
	for(int x : ret)
	{
		cout << x << ' ';
	}
	cout << endl;
}

void solve()
{
	FORD(i, 21)
	{
		// for beauty level i, find the eulerian circuit (if it exists)
		if(find_eulerian((1 << i)-1))
		{
			cout << i << endl; // yay!! it exists!!
			// retrace the eulerian that we know exists -- hard part
			trace((1 << i)-1);
			break;
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
