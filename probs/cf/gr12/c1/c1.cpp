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

void solve()
{
	int n; cin >> n;
	vector<vector<char> > a(n, vector<char>(n));
	vector<vector<char> > b(n, vector<char>(n));
	vector<vector<char> > c(n, vector<char>(n));
	int k = 0;
	FOR(i, n) FOR(j, n)
	{
		cin >> a[i][j];
		if(a[i][j] == 'X' || a[i][j] == 'O') k++;
		c[i][j] = b[i][j] = a[i][j];
	}
	int ca=0,cb=0,cc=0;
	FOR(i, n)
	{
		int off = i%3;
		FOR(j, n)
		{
			if(a[i][j] == 'X' && j%3 == off)
			{
				a[i][j] = 'O';
				ca++;
			}
		}
	}
	FOR(i, n)
	{
		int off = (i+1)%3;
		FOR(j, n)
		{
			if(b[i][j] == 'X' && j%3 == off)
			{
				b[i][j] = 'O';
				cb++;
			}
		}
	}
	FOR(i, n)
	{
		int off = (i+2)%3;
		FOR(j, n)
		{
			if(c[i][j] == 'X' && j%3 == off)
			{
				c[i][j] = 'O';
				cc++;
			}
		}
	}
	if(ca <= k/3) FOR(i, n)
	{
		FOR(j, n) cout << a[i][j];
		cout << endl;
	} else if(cb <= k/3) FOR(i, n)
	{
		FOR(j, n) cout << b[i][j];
		cout << endl;
	} else if(cc <= k/3) FOR(i, n)
	{
		FOR(j, n) cout << c[i][j];
		cout << endl;
	}
}

signed main()
{
	// fileio("");
	DUEHOANG;
	int t = 1;
	cin >> t; // uncomment if it's multitest
	while(t--)
	{
		solve();
	}
	
}
