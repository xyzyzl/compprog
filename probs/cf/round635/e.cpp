// Time:
// Algorithms: 

#include <bits/stdc++.h>

#pragma GCC optimize("O3")

using namespace std;

#define MAXN 1000005

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
// #define MOD (1e9*1)+7
#define MOD 998244353
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

int n, m;
string s, t;
int dp[3005][3005];
void read()
{
	cin >> s >> t;
	n = s.length();
	m = t.length();
}

void solve()
{
	dp[n][0] = 1;
	F1RD(i, n-1)
	{
		FOR(j, m+1)
		{
			if(j == 0)
			{
				if(i >= m)
				{
					dp[i][j] = n-i+1;
				} else if(s[i] == t[i])
				{
					dp[i][j] = dp[i+1][j];
				}
			} else if(j == m)
			{
				dp[i][j] = 2 * dp[i+1][j] % MOD;
				if(s[i] == t[j-1])
				{
					dp[i][j] = (dp[i][j] + dp[i+1][j-1]) % MOD;
				}
			} else 
			{
				if(i + j >= m || s[i] == t[i+j])
				{
					dp[i][j] = dp[i+1][j];
				}
				if(s[i] == t[j-1])
				{
					dp[i][j] = (dp[i][j] + dp[i+1][j-1]) % MOD;
				}
			}
		}
	}
	int ans = dp[1][m];
	FOR(i, m)
	{
		if(t[i] == s[0]) ans = (ans + dp[1][i]) % MOD;
	}
	ans = ans * 2 % MOD;
	cout << ans << endl;
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
