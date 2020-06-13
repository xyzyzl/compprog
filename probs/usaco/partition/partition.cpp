// Time:
// Algorithms:

#include <bits/stdc++.h>

#pragma GCC optimize("O3")

using namespace std;

#define MAXN 17

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

int n, k, ans, sm[MAXN];
int arr[MAXN][MAXN], cost[MAXN][MAXN], dp[MAXN][MAXN];
void read()
{
	cin >> n >> k;
	FOR(i, n) FOR(j, n)
	{
		cin >> arr[i][j];
	}
	ans = INT_MAX;
}

void solve()
{
	// choose some bitmask
	FOR(mask, (1 << (n-1)))
	{
		int rem = __builtin_popcount(mask); // the number of ones
		// cerr << rem << endl;
		if(rem <= k)
		{
			FOR(i, n)
			{
				memset(sm, 0, sizeof sm);
				// precompute cost
				FORR(i+1, j, n+1)
				{
					cost[i][j] = 0;
					int rs = 0;
					FOR(k, n)
					{
						sm[k] += arr[j-1][k];
						rs += sm[k];
						MAX(cost[i][j], rs);
						if((1 << k) & mask) rs = 0;
					}
				}
			}
			FOR(i, n+1) FOR(j, n+1)
			{
				dp[i][j] = INF;
			}
			dp[0][0] = 0;
			for(int kk = 1; kk <= n && kk <= (k-rem+1); ++kk)
			{
				FOR(i, n)
				{
					FORR(i+1, j, n+1)
					{
						MIN(dp[kk][j], max(dp[kk-1][i], cost[i][j]));
					}
				}
				MIN(ans, dp[kk][n]);
			}
		}
	}
	cout << ans << endl;
}

int main()
{
	fileio("partition.in", "partition.out");
	DUEHOANG;
	int t = 1;
	// cin >> t; // uncomment if it's multitest
	while(t--)
	{
		read();
		solve();
	}

}
