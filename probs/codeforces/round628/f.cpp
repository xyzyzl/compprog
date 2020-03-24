// Time:
// Algorithms: 

#include <bits/stdc++.h>

#pragma GCC optimize("O3")

using namespace std;

#define MAXN 100005

#define FOR(i, n) for (int i = 0; i < n; i++)
#define FORR(j, i, n) for (int i = j; i < n; i++)
#define FORD(i, n) for (int i = n - 1; i >= 0; i--)
#define FOBIR(i, n) for (int i = 1; i <= n; i++)
#define FOBIRD(i, n) for (int i = n; i >= 1; i--)
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

int n, m, deg[MAXN], dg[MAXN], des=1;
bool not_exists[MAXN]; // originally was exists but that would need
// one more line of code so that was bad for me
vi adj[MAXN];
set<pii> nds;

void delete_node(int node)
{
	// remove the node iff it's a neighbor of removed and isn't already
	if(not_exists[node]) return;
	nds.erase(mp(deg[node], node));
	not_exists[node]=1;
	for(int x : adj[node])
	{
		// cerr << x << " aaaa " << not_exists[x] << endl;
		if(not_exists[x]) continue;
		nds.erase(mp(deg[x], x));
		nds.insert(mp(--deg[x], x));
	}
	// cerr << nds.size() << endl;
}

void solve()
{
	cin >> n >> m;
	des = ceil(sqrt(n));
	// cerr << des << endl;
	FOR(i, m)
	{
		int a, b;
		cin >> a >> b;
		--a; --b;
		deg[a]++;
		deg[b]++;
		adj[a].pb(b);
		adj[b].pb(a);
	}
	FOR(i, n) nds.insert(mp(deg[i], i));
	vi ans;
	while(!nds.empty())
	{
		// cerr << deg[1] << endl;
		// cerr << nds.size() << endl;
		pii p = *nds.begin();
		nds.erase(nds.begin());
		// cerr << nds.size() << endl;
		// cerr << p.f << " " << p.s+1 << endl;
		if(p.f+1 >= des)
		{
			cout << 2 << endl;
			vi d;
			d.pb(p.s);
			dg[p.s] = 1;
			while(1)
			{
				pii nxt = mp(INF, 0);
				for(int x : adj[d.back()])
				{
					if(not_exists[x]) continue;
					nxt = min(nxt, mp(dg[x], x));
				}
				if(nxt.f)
				{
					// must be visited!!
					cout << (d.size() - nxt.f + 1) << endl;
					FORR(nxt.f-1, i, d.size())
					{
						cout << 1+d[i] << " ";
					}
					cout << endl;
					return;
				}
				d.pb(nxt.s);
				dg[nxt.s] = d.size();
			}
		}
		ans.pb(p.s+1);
		delete_node(p.s);
		for(int x : adj[p.s]) delete_node(x);
	}
	cout << 1 << endl;
	FOR(i, des) cout << ans[i] << " ";
	cout << endl;
}

int main()
{
	// fileio("fin.txt", "fout.txt");
	int t = 1;
	// cin >> t; // uncomment if it's multitest
	while(t--)
	{
		solve();
	}
	
}
