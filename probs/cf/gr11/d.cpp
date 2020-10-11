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

int n;
vi v, inds;
void solve()
{
	cin >> n;
	v.resize(n);
	inds.resize(n + 1);
	FOR(i, n)
	{
		cin >> v[i];
		inds[v[i]] = i;
	}
	if (n == 1)
	{
		cout << 0 << endl;
		return;
	}
	int c = 0;
	FOR(i, n)
	{
		if (v[i] != i + 1)
			break;
		c++;
	}
	if(c==n) return;
	int ord = 0;
	vi q;
	FORR(1, k, n)
	{
		if (inds[k] < inds[k + 1])
		{
			q.clear();
			FOR(i, inds[k])
			q.pb(1);
			q.pb(inds[k + 1] - inds[k]);
			q.pb(1);
			FORR(inds[k + 1] + 1, i, n)
			{
				q.pb(1);
			}
			cout << q.size() << " ";
			for (int x : q)
				cout << x << " ";
			cout << endl;
			reverse(v.begin() + inds[k], v.begin() + inds[1 + k]);
			reverse(v.begin(), v.end());
			for (int x : v)
				cerr << x << " ";
			cerr << endl;
		}
		else
		{
			q.clear();
			FOR(i, inds[k + 1])
			q.pb(1);
			q.pb(inds[1] - inds[k + 1]);
			q.pb(1);
			FORR(inds[1] + 1, i, n)
			{
				q.pb(1);
			}
			cout << q.size() << " ";
			for (int x : q)
				cout << x << " ";
			cout << endl;
			reverse(v.begin() + inds[k + 1], v.begin() + inds[1]);
			reverse(v.begin(), v.end());
			for (int x : v)
				cerr << x << " ";
			cerr << endl;
		}
		FOR(i, n)
		inds[v[i]] = i;
		int c = 0;
		FOR(i, n)
		{
			if (v[i] != i + 1)
				break;
			c++;
		}
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
