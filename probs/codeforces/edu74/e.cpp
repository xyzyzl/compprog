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

int n, m, ct[21][21], dp[1 << 21], lowest[1 << 21], dist[1 << 21][21];
string s;
void read()
{
	cin >> n >> m >> s;
}

void solve()
{
	FOR(i, s.size()-1)
	{
		ct[s[i]-'a'][s[i+1]-'a']++;
		ct[s[i+1]-'a'][s[i]-'a']++;
	}
	FOR(i, (1 << 21))
	{
		dp[i] = INF;
	}
	dp[0] = 0;
	F1R(i, (1 << m) - 1)
	{
		FOR(j, 20)
		{
			if((i >> j) & 1)
			{
				lowest[i] = j;
				break;
			}
		}
	}
	F1R(i, (1 << m) - 1)
	{
		FOR(j, m)
		{
			int x = lowest[i];
			dist[i][j] = dist[i ^ (1 << x)][j] + ct[j][x];
		}
	}

	FOR(i, (1 << m))
	{
		FOR(j, m)
		{
			if((i >> j) & 1) continue;
			// transition
			int pos = __builtin_popcount(i);
			MIN(dp[i | (1 << j)], dp[i] + pos*(dist[i][j] - dist[((1 << m)-1) ^ (i | (1 << j))][j]));
		}
	}
	cout << dp[(1 << m)-1] << endl;
			
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
