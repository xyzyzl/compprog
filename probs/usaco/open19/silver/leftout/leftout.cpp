#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> // pbds
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/detail/standard_policies.hpp>

#pragma GCC optimize("O3")

using namespace __gnu_pbds;
using namespace std;

#define MAXN 1005

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
#define fileio(file)                 \
	freopen(file ".in", "r", stdin); \
	freopen(file ".out", "w", stdout)
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
bool ok[MAXN][MAXN];
void solve()
{
	cin >> n;
	FOR(i, n)
	FOR(j, n)
	{
		char c;
		cin >> c;
		if (c == 'R')
			ok[i][j] = 0;
		else
			ok[i][j] = 1;
	}
	// flip everything to ok[0][0]
	F1R(i, n - 1)
	{
		if (ok[i][0] != ok[0][0])
		{
			FOR(j, n)
			ok[i][j] = !ok[i][j];
		}
		if (ok[0][i] != ok[0][0])
		{
			FOR(j, n)
			ok[j][i] = !ok[j][i];
		}
	}
	int k = 0;
	F1R(i, n - 1)
	{
		F1R(j, n - 1)
		k += (ok[i][j] != ok[0][0]);
	}
	if (k == (n - 1) * (n - 1))
	{
		cout << "1 1" << endl;
		return;
	}
	int l = 0;
	F1R(i, n - 1)
	{
		F1R(j, n - 1)
		l += (ok[i][j] != ok[0][0]);
	}
	if (l == n - 1)
	{
		F1R(i, n - 1)
		{
			k = 0;
			FOR(j, n)
			k += (ok[i][j] != ok[0][0]);
			if (k == n - 1)
			{
				cout << i + 1 << " " << 1 << endl;
				return;
			}
			k = 0;
			FOR(j, n)
			k += (ok[j][i] != ok[0][0]);
			if (k == n - 1)
			{
				cout << 1 << " " << i + 1 << endl;
				return;
			}
		}
		cout << -1 << endl;
		return;
	} else
	{
		if(l == 1)
		{
			F1R(i, n-1) F1R(j, n-1) if(ok[i][j] != ok[0][0]) cout << i+1 << " " << j+1 << endl;
			return;
		} else
		{
			cout << -1 << endl;
		}
		
	}
}

signed main()
{
	// fileio("");
	DUEHOANG;
	int t = 1;
	// cin >> t; // uncomment if it's multitest
	while (t--)
	{
		solve();
	}
}
