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

int n, k, p, a[55][35];
int dp[55][1505];
void solve(int tc)
{
	memset(dp, 0, sizeof dp);
	memset(a, 0, sizeof a);
	cin >> n >> k >> p;
	F1R(i, n)
	{
		F1R(j, k)
		{
			int w;
			cin >> w;
			a[i][j] = a[i][j-1] + w;
		}
	}
	/*
	F1R(i, n)
	{
		F1R(j, k) cout << a[i][j] << " ";
		cout << endl;
	}
	*/
	F1R(i, n)
	{
		FOR(j, p+1)
		{
			FOR(q, 1+min(j, k))
			{
				dp[i][j] = max(dp[i][j], dp[i-1][j-q] + a[i][q]);
			}
		}
	}
	cout << "Case #" << tc << ": " << dp[n][p] << endl; // all n stacks and p plates
}

int main()
{
	int t = 1;
	cin >> t; // uncomment if it's multitest
	F1R(tc, t)
	{
		solve(tc);
	}
	
}
