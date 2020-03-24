/*input
9
1
2
3
9
5
6
8
7
4
*/

// Time:
// Algorithms: 

#include <bits/stdc++.h>

#pragma GCC optimize("O3")

using namespace std;

#define MAXN 55

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

int n, a[MAXN];
int dp[MAXN][MAXN][MAXN][MAXN]; // i, length, smallest
// left index, smallest right index
int rec(int i, int j, int p, int q)
{
	if(dp[i][j][p][q] >= 0) return dp[i][j][p][q];
	if(p > q) return -INF;
	if(i > j) return 0;
	if(i == j)
	{
		return dp[i][j][p][q] = (p <= a[i] && a[i] <= q);
	}

	int ans = 0;
	//--literally nothing--//
	MAX(ans, rec(i+1, j-1, p, q));
	//--swap--//
	if(a[j] >= p) MAX(ans, rec(i+1, j-1, a[j], q)+1);
	if(a[i] <= q) MAX(ans, rec(i+1, j-1, p, a[i])+1);
	if(p <= a[j] && a[j] <= a[i] && a[i] <= q)
		MAX(ans, rec(i+1, j-1, a[j], a[i])+2);
	//--no swap--//
	MAX(ans, rec(i+1, j, p, q));
	if(a[i] >= p) MAX(ans, rec(i+1, j, a[i], q)+1);
	MAX(ans, rec(i, j-1, p, q));
	if(a[j] <= q) MAX(ans, rec(i, j-1, p, a[j])+1);
	return dp[i][j][p][q] = ans;
}

void solve()
{
	cin >> n;
	FOR(i, n)
	{
		cin >> a[i];
	}
	memset(dp, 0xc0, sizeof dp);
	// cout << dp[0][0][0][0] << endl;
	cout << rec(0, n-1, 0, 50) << endl;
}

int main()
{
	fileio("subrev.in", "subrev.out");
	int t = 1;
	// cin >> t; // uncomment if it's multitest
	while(t--)
	{
		solve();
	}
	
}
