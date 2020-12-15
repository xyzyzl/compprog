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

typedef pair<pii, pii> quad;
int n;
quad l[MAXN];

bool on(pair<int, int> p, pair<int, int> q, pair<int, int> r)
{
	if (q.f <= max(p.f, r.f) && q.f >= min(p.f, r.f) &&
		q.s <= max(p.s, r.s) && q.s >= min(p.s, r.s))
		return true;

	return false;
}

int ort(pair<int, int> p, pair<int, int> q, pair<int, int> r)
{
	int val = (q.s - p.s) * (r.f - q.f) - (q.f - p.f) * (r.s - q.s);
	if (val == 0)
		return 0;
	return (val > 0) ? 1 : 2;
}

bool inter(pair<pair<int, int>, pair<int, int> > l1, pair<pair<int, int>, pair<int, int> > l2)
{
	int o1 = ort(l1.f, l1.s, l2.f);
	int o2 = ort(l1.f, l1.s, l2.s);
	int o3 = ort(l2.f, l2.s, l1.f);
	int o4 = ort(l2.f, l2.s, l1.s);
	if (o1 != o2 && o3 != o4)
		return 1;
	if(!o1 && on(l1.f, l2.f, l1.s)) return 1;
	if(!o2 && on(l1.f, l2.s, l1.s)) return 1;
	if(!o3 && on(l2.f, l1.f, l2.s)) return 1;
	if(!o4 && on(l2.f, l1.s, l2.s)) return 1;
	return 0;
}

void solve()
{
	cin >> n;
	FOR(i, n) cin >> l[i].f.f >> l[i].f.s >> l[i].s.f >> l[i].s.s;
	vector<quad> p;
	FOR(i, n)
	{
		p.pb(mp(mp(l[i].f.f, l[i].f.s), mp(i, 0)));
		p.pb(mp(mp(l[i].s.f, l[i].s.s), mp(i, 1)));
	}
	sort(p.begin(), p.end());
	multiset<pair<quad, int> > ms;
	int x = 0, y = 0;
	FOR(i, 2*n)
	{
		quad L = l[p[i].s.f];
		pair<quad,int> pt = mp(L, p[i].s.f);
		if(!p[i].s.s) // add
		{
			ms.insert(pt);
			auto it = ms.find(pt);
			if(it != ms.begin() && inter(L, prev(it)->f))
			{
				x = min(p[i].s.f, prev(it)->s);
				y = max(p[i].s.f, prev(it)->s);
				break;
			}
			it = ms.upper_bound(pt);
			if(it != ms.end() && inter(L, it->f))
			{
				x = min(p[i].s.f, (it)->s);
				y = max(p[i].s.f, (it)->s);
				break;
			}
		} else // erase
		{
			auto i1 = ms.upper_bound(pt);
			if(ms.find(pt) == ms.begin())
			{
				ms.erase(pt); continue;
			}
			auto i2 = prev(ms.find(pt));
			if(i1 != ms.end() && i1 != i2 && inter(i1->f,i2->f))
			{
				x = min(i1->s, i2->s);
				y = max(i1->s, i2->s);
				break;
			}
		}
	}
	int ix = 0, iy = 0;
	FOR(i, n)
	{
		if(i != x) ix += inter(l[i],l[x]);
		if(i != y) iy += inter(l[i],l[y]);
	}
	if(ix < iy) cout << y+1 << endl;
	else cout << x+1 << endl;
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
