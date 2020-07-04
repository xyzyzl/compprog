// Time:
// Algorithms: 

#include <bits/stdc++.h>

#pragma GCC optimize("O3")

using namespace std;

<<<<<<< HEAD
#define MAXN 1000005
=======
#define MAXN 505
>>>>>>> cf0dc10f9f74a2bdff9ff6fb1ab25eb578c8fd38

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

int n, dp[MAXN][MAXN];
string w;
void read()
{
	cin >> n;
	cin >> w;
	FOR(i, n+5) FOR(j, n+5) dp[i][j] = -1;
}

// with memoization!
int recurse(int i, int j)
{
	if(dp[i][j] != -1) return dp[i][j];
	if(i == j) return dp[i][j] = 1;
	if(i > j) return dp[i][j] = 0;
	int ret = recurse(i+1, j) + 1;
	FORR(i+1, k, j+1)
	{
		if(w[i] == w[k])
			MIN(ret, recurse(i+1, k-1) + recurse(k, j));
	}
	return dp[i][j] = ret;
}
void solve()
{
	cout << recurse(0, n-1) << endl;	
}

int main()
{
	DUEHOANG;
	int t = 1;
	// cin >> t; // uncomment if it's multitest
	while(t--)
	{
		read();
		solve();
	}
	
}
