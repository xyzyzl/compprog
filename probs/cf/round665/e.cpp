// Time:
// Algorithms: 

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

bool cmp(iii x, iii y)
{
	if(x.f == y.f)
	{
		return x.s.s < y.s.s;
	}
	return x.f < y.f;
}

int n,m;
iii lines[MAXN];
os h;
void solve()
{
	cin >> n >> m;
	ll a = 0;
	FOR(i, n) 
	{
		int x,y;
		cin >> lines[i].s.f >> x >> y;
		if(x == 0) // left to right
		{
			if(y == 1000000) a++;
			lines[i].f   = y;
			lines[i].s.s = 3;
			h.insert(lines[i].s.f);
		} else // right to left
		{
			lines[i].f   = x;
			lines[i].s.s = 0;
		}
	}
	FOR(i, m)
	{
		int x,y;
		cin >> lines[n+i].f >> x >> y;
		if(x == 0) // bottom to top
		{
			if(y == 1000000) a++;
			lines[n+i].s.f = y;
			lines[n+i].s.s = 1;
		} else
		{
			lines[n+i].s.f = x;
			lines[n+i].s.s = 2;
		}
	}
	sort(lines, lines+n+m, cmp);
	ll ans = a;
	FOR(i, n+m)
	{
		if(lines[i].s.s == 3) // remove segment @ right endpoint
		{
			h.erase(h.find(lines[i].s.f));
		} else if(lines[i].s.s == 0) // add segment
		{
			h.insert(lines[i].s.f);
		} else
		{
			if(lines[i].s.s == 1) // bottom to top
			{
				ll x = 0;
				auto q = h.upper_bound(lines[i].s.f);
				if(q == h.end()) x = h.size();
				else x = h.order_of_key(*q);
				// cerr << x << endl;
				ans += x;
			} else // top to bottom
			{
				ll x = 0;
				auto q = h.lower_bound(lines[i].s.f);
				if(q == h.end())
					x = h.size();
				else x = h.order_of_key(*q);
				// cerr << h.size() << endl;
				ans += (h.size()-x);
			}
		}
	}
	// cerr << a << endl;
	cout << ans+1 << endl;
}

int main()
{
	DUEHOANG;
	int t = 1;
	// cin >> t; // uncomment if it's multitest
	while(t--)
	{
		solve();
	}
	
}

