#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> // pbds
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/detail/standard_policies.hpp>

#pragma GCC optimize("O3")

using namespace __gnu_pbds;
using namespace std;

#define MAXN 25
#define MAXS 205

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

int n, K, S, A[MAXN], C[MAXN];
ll dp[MAXN][MAXS]; // dp(color, index, # blocks, length)
double fact[MAXN];
vi idx[MAXN];
void solve()
{
	cin >> n >> K;
	double ans = 0;
	F1R(i, n)
	{
		idx[i].clear();
	}
	F1R(i, n)
	{
		cin >> A[i] >> C[i]; // length, color
		S += A[i];
		idx[C[i]].pb(i);
		ans += (double)n*fact[n-1]*max(0, A[i]-K);
	}
	F1R(i, n)
	{
		F1R(j, n)
		{
			if(i == j || C[i] != C[j]) continue;
			// at most 10 such pairs
			vi X(K);
			FOR(L, K)
			{
				X[L] = 0;
				F1R(k, A[i])
				{
					if(k + K > A[i]+L && k + K <= A[i] + A[j] + L) X[L]++;
				}
			}
			memset(dp, 0, sizeof dp);
			dp[0][0] = 1;
			F1R(id, n)
			{
				if(id != i && id != j)
				{
					FORD(k, n-2)
					{
						FORD(L, K)
						{
							if(L+A[id] < K)
							{
								dp[k+1][L+A[id]] += dp[k][L];
							}
						}
					}
				}
			}
			FOR(k, n-1)
			{
				FOR(L, K)
				{
					ans += dp[k][L] * fact[k] * fact[n-2-k] * (double)(n-1-k) * (double)(X[L]);
				}
			}
		}
	}
	cout << setprecision(8) << fixed << (ans / fact[n]) << endl;
}

signed main()
{
	// fileio("");
	DUEHOANG;
	int t = 1;
	fact[0] = 1;
	F1R(i, 21)
	{
		fact[i] = (fact[i-1] * i);
	}
	cin >> t; // uncomment if it's multitest
	while(t--)
	{
		solve();
	}
	
}
