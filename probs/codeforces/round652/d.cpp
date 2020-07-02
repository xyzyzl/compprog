// Time: 31:25
// Algorithms: DP - essentially comes from the fact that level n dead bush is composed of one level n-1 bush and one level n-2 bush.
// let dp[i] = max. # yellow bushes for i. then dp[i] = 2*dp[i-1] + dp[i-2]. also important is that 3|n => paint the top "claw" yellow => add 4 to dp[i].
// if i % 3 != 0 then we cannot pain the top "claw" yellow as some top thing must already be taken.

#include <bits/stdc++.h>

#pragma GCC optimize("O3")

using namespace std;

#define MAXN 2000005

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
#define MOD int((1e9*1)+7)
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

int n;
int dp[MAXN];
void read()
{
	cin >> n;
}

void solve()
{
	cout << dp[n] << endl;
}

void precomp()
{
	F1R(i, 2000000)
	{
		if(i-2 >= 0) dp[i] = (dp[i] + (dp[i-2] + dp[i-2]) % MOD) % MOD;
		if(i-1 >= 0) dp[i] = (dp[i] + dp[i-1]) % MOD;
		if(i % 3 == 0) dp[i] = (dp[i] + 4) % MOD;
	}
}

int main()
{
	DUEHOANG;
	precomp();
	int t = 1;
	cin >> t; // uncomment if it's multitest
	while(t--)
	{
		read();
		solve();
	}
	
}
