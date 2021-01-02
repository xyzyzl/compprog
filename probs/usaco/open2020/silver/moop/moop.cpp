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

int n;
pii a[MAXN];
int p[MAXN], sz[MAXN];

int find_set(int i)
{
	return (p[i] == i) ? i : (p[i] = find_set(p[i]));
}

bool union_set(int i, int j)
{
	int x = find_set(i);
	int y = find_set(j);
	if (x == y)
		return false;
	if (x > y) swap(x,y);
	p[x] = p[y] = x;
	sz[x] += sz[y];
	return true;
}

void init()
{
	for (int i = 0; i < n; i++)
		p[i] = i;
	for (int i = 0; i < n; i++)
		sz[i] = 1;
}

int pmn[MAXN], pid[MAXN], smx[MAXN], sid[MAXN];
void solve()
{
	cin >> n;
	FOR(i, n) cin >> a[i].f >> a[i].s;
	sort(a,a+n);
	init();
	FOR(i, n)
	{
		if(i)
		{
			pid[i] = (a[i].s < pmn[i-1]) ? i : pid[i-1];
			pmn[i] = min(pmn[i-1], a[i].s);
		}
		else
		{
			pmn[i] = a[i].s;
			pid[i] = i;
		}
	}
	FORD(i, n)
	{
		if(i < n-1)
		{
			sid[i] = (a[i].s > smx[i+1]) ? i : sid[i+1];
			smx[i] = max(smx[i+1], a[i].s);
		}
		else
		{
			smx[i] = a[i].s;
			sid[i] = i;
		}
	}
	int sm = 0;
	FOR(i, n-1)
	{
		sm += (pmn[i] > smx[i+1]);
	}
	cout << 1+sm << endl;
}

signed main()
{
	fileio("moop.in", "moop.out");
	DUEHOANG;
	int t = 1;
	// cin >> t; // uncomment if it's multitest
	while(t--)
	{
		solve();
	}
	
}
