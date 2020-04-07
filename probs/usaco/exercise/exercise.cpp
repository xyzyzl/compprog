// Time:
// Algorithms: 

#include <bits/stdc++.h>

#pragma GCC optimize("O3")

using namespace std;

#define MAXN 10005

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

int n, m;
vi primes;
bool comp[MAXN];
const int N_P = 1230;
ll dp[N_P][MAXN];

ll add(int a, int b)
{
	return (a+b)%m;
}
ll sub(int a, int b)
{
	return (a-b+m)%m;
}
ll mul(int a, int b)
{
	return ((ll)(a) * (ll)(b))%m;
}

void solve()
{
	cin >> n >> m;
	FORR(2, i, n+1)
	{
		if(!comp[i])
		{
			primes.pb(i);
			for(int j = i; j <= n; j+=i) comp[j] = 1;
		}
	}
	int p = primes.size();
	if(primes.empty())
	{
		cout << 1 << endl;
		return;
	}
	FOR(i, n+1) dp[0][i] = 1;
	F1R(i, p)
	{
		FOR(j, n+1)
		{
			dp[i][j] = dp[i-1][j]; // everything from previous index

			// add things from new index, all powers
			int x = primes[i-1];
			while(x <= j)
			{
				dp[i][j] = add(dp[i][j], mul(x, dp[i-1][j-x]));
				x = mul(x, primes[i-1]);
			}
		}
	}
	cout << dp[p][n] << endl;
}

int main()
{
	fileio("exercise.in", "exercise.out");
	int t = 1;
	// cin >> t; // uncomment if it's multitest
	while(t--)
	{
		solve();
	}
	
}
