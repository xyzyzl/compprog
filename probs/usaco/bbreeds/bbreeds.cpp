// Time:
// Algorithms: 

#include <bits/stdc++.h>

#pragma GCC optimize("O3")

using namespace std;

#define MAXN 1005

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

int n, dp[MAXN][MAXN], n_open[MAXN];
string str;
void solve()
{
	cin >> str;
	n=str.length();
	FOR(i, n) FOR(j, n) dp[i][j] = 0;
	FOR(i, n) n_open[i+1] = n_open[i] + (str[i] == '(' ? 1 : -1);
	dp[n][0] = 1;
	FORD(i, n)
	{
		FOR(a, n)
		{
			int b = n_open[i] - a;
			if(str[i] == '(')
			{
				dp[i][a] = (dp[i+1][a+1] + dp[i+1][a]) % 2012;
			} else 
			{
				dp[i][a] = 0;
				if(a) dp[i][a] = (dp[i][a] + dp[i+1][a-1]) % 2012;
				if(b) dp[i][a] = (dp[i][a] + dp[i+1][a]) % 2012;
			}
		}
	}
	cout << dp[0][0] % 2012 << endl;
}

int main()
{
	DUEHOANG;
	fileio("bbreeds.in", "bbreeds.out");
	int t = 1;
	// cin >> t; // uncomment if it's multitest
	while(t--)
	{
		solve();
	}
	
}
