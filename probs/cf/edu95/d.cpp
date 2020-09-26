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
#define MOD (1e9 * 1) + 7
#define MOD2 998244353
#define INF (1e9 * 1) + 5

typedef set<int> si;
typedef multiset<int> msi;
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

#define bitinc(x) x & -x

const int MAX(int &a, int b)
{
	return a = max(a, b);
}
const int MIN(int &a, int b)
{
	return a = min(a, b);
}

int n, q;
si pt;
msi l;

void add(int p)
{

	pt.insert(p);
	auto it = pt.find(p);
	int pv = -1;
	if (it != pt.begin())
	{
		auto pr = prev(it);
		l.insert(p - *pr);
		pv = *pr;
	}
	++it;
	int nx = -1;
	if (it != pt.end())
	{
		auto pr = it;
		l.insert(*pr - p);
		nx = *pr;
	}
	// cerr << pv << " " << nx << endl;
	if (pv != -1 && nx != -1)
	{
		l.erase(l.find(nx - pv));
	}
}

void rem(int p)
{
	auto it = pt.find(p);
	int pv = -1;
	if (it != pt.begin())
	{
		auto pr = prev(it);
		l.erase(l.find(p - *pr));
		pv = *pr;
	}
	++it;
	int nx = -1;
	if (it != pt.end())
	{
		auto pr = it;
		l.erase(l.find(*pr - p));
		nx = *pr;
	}
	pt.erase(pt.find(p));
	if (pv != -1 && nx != -1)
		l.insert((nx - pv));
}

void solve()
{
	cin >> n >> q;
	FOR(i, n)
	{
		int p;
		cin >> p;
		add(p);
	}
	cout << (l.empty() ? 0 : (*pt.rbegin() - *pt.begin() - *l.rbegin())) << endl;
	cout.flush();
	FOR(i, q)
	{
		int t;
		cin >> t;
		if (t)
		{
			int p;
			cin >> p;
			add(p);
		}
		else
		{
			int p;
			cin >> p;
			rem(p);
		}
		cout << (l.empty() ? 0 : (*pt.rbegin() - *pt.begin() - *l.rbegin())) << endl;
		cout.flush();
	}
}

signed main()
{
	DUEHOANG;
	int t = 1;
	// cin >> t; // uncomment if it's multitest
	while (t--)
	{
		solve();
	}
}
