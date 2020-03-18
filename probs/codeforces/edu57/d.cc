// Time:
// Algorithms: 

#include <bits/stdc++.h>

#pragma GCC optimize("O3")

using namespace std;

#define MAXN 100005

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

const ll MAX(ll &a, ll b)
{
    return a = max(a, b); 
}
const ll MIN(ll &a, ll b)
{
    return a = min(a, b); 
}

int n;
ll a[MAXN], dp[MAXN][5];
string s;
int main()
{
    int tq = 1;
    // cin >> t; // uncomment if it's multitest
    while(tq--)
    {
		cin >> n >> s;
		FOR(i, n) cin >> a[i];
		FOR(i, n+5) FOR(j, 5) dp[i][j] = (ll)1e18;
		// cout << dp[n][0] << endl;
		dp[0][0] = 0;
		string t = "hard";
		FOR(i, n)
		{
			FOR(j, 4)
			{
				// if(i == n-1 && j == 0) cout << s[i] << " " << t[j] << endl;
				// if(i+1 == n && j == 0) cout << dp[i][j] << endl;
				if(s[i] == t[j])
				{
					MIN(dp[i+1][j+1], dp[i][j]);
					MIN(dp[i+1][j], dp[i][j] + a[i]);
					// if(i == n-1 && j == 0) cout << dp[i+1][j] << " " << dp[i][j] + a[i] << endl;
				}
				else MIN(dp[i+1][j], dp[i][j]);
			}
		}
		ll x = LLONG_MAX;
		// FOBIR(i, n) cout << dp[i][0] << " ";
		//. cout << endl;
		// FOR(i, 4) cout << dp[n][i] << " ";
		// cout << endl;
		FOR(i, 4) MIN(x, dp[n][i]);
		cout << x << endl;
    }
    
}

