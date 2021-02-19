#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> // pbds
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/detail/standard_policies.hpp>

#pragma GCC optimize("O3")

using namespace __gnu_pbds;
using namespace std;

#define MAXN 200005

#define FOR(i, n) for (int i = 0; i < n; i++)
#define FORR(j, i, n) for (int i = j; i < n; i++)
#define FORD(i, n) for (int i = n - 1; i >= 0; i--)
#define F1R(i, n) for (int i = 1; i <= n; i++)
#define F1RD(i, n) for (int i = n; i >= 1; i--)
#define pb push_back
#define mp make_pair
#define ins insert
#define endl '\n'
#define DUEHOANG                  \
	ios_base::sync_with_stdio(0); \
	cin.tie(NULL);                \
	cout.tie(NULL)
#define fileio(file) freopen(file ".in", "r", stdin); freopen(file ".out", "w", stdout)
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
// ordered_set
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> os;
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
pair<string, int> p[MAXN];
vi adj[MAXN];
int indeg[MAXN];
vi res;

bool topo()
{
	// no need to reset the adjacency list and things
	si st;
	FOR(i, n)
	{
		if(!indeg[i])
		{
			st.insert(i);
			// cout << i << endl;
		}
	}
	FOR(i, n)
	{
		int u = *st.begin();
		if(st.empty()) return 0;
		st.erase(st.begin());
		res.pb(u+1);

		for(int v : adj[u])
		{
			indeg[v]--;
			if(indeg[v] == 0) st.insert(v);
		}
		// cout << u << endl;
	}
	return 1;
}

void solve()
{
	cin >> n >> m >> k;
	FOR(i, n)
	{
		cin >> p[i].f;	
		p[i].s = i;
	}
	sort(p, p+n);
	FOR(i, m)
	{
		string ful;
		int mt; cin >> ful >> mt;
		--mt;
		bool has = 0;
		FOR(msk, (1 << k))
		{
			string s0="";
			FOR(j, k)
			{
				if(msk & (1 << j)) s0 += ful[j];
				else s0 += '_';
			}
			auto it = lower_bound(p, p+n, mp(s0, -1));
			if(it != p+n && it->f == s0) 
			{
				if(it->s != mt)
				{
					adj[mt].pb(it->s);
					indeg[it->s]++;
				}
				else has=1;
			} 
		}
		if(!has)
		{
			cout << "NO" << endl;
			return;
		}
	}
	if(topo())
	{
		cout << "YES" << endl;
		for(int x : res)
		{
			cout << x << ' ';
		}
	} else cout << "NO" << endl;
}

signed main()
{
	// fileio("");
	DUEHOANG;
	int t = 1;
	// cin >> t; // uncomment if it's multitest
	while(t--)
	{
		solve();
	}
	
}
