#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> // pbds
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/detail/standard_policies.hpp>

#pragma GCC optimize("O3")

using namespace __gnu_pbds;
using namespace std;

#define MAXN 105

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

signed main()
{
	DUEHOANG;
	int t = 1;
	cin >> t; // uncomment if it's multitest
	while (t--)
	{
		int n, m;
		cin >> n >> m;
		char c[MAXN][MAXN];
		int c1 = 0;
		FOR(i, n)
		FOR(j, m)
		{
			cin >> c[i][j];
			if (c[i][j] == '1')
				c1++;
		}
		cout << 3 * c1 << endl;
		FOR(i, n)
		FOR(j, m)
		{
			if (c[i][j] == '1')
			{
				// flip only (i,j) to 0 in 3 moves
				int ni = (i < n - 1 ? (i + 1) : (i - 1));
				int nj = (j < m - 1 ? (j + 1) : (j - 1));
				cout << 1+i << " " << 1+j << ' ';
				cout << 1+ni << " " << 1+j << ' ';
				cout << 1+i << " " << 1+nj << endl;

				cout << 1+i << " " << 1+j << ' ';
				cout << 1+ni << " " << 1+j << ' ';
				cout << 1+ni << " " << 1+nj << endl;

				cout << 1+i << " " << 1+j << ' ';
				cout << 1+i << " " << 1+nj << ' ';
				cout << 1+ni << " " << 1+nj << endl;
			}
		}
	}
}
