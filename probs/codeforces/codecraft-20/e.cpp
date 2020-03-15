// Time:
// Algorithms: 

#include <bits/stdc++.h>

#pragma GCC optimize("O3")

using namespace std;

#define MAXN 100005
#define HI 7

#define FOR(i, n) for (int i = 0; i < n; i++)
#define FORR(j, i, n) for (int i = j; i < n; i++)
#define FORD(i, n) for (int i = n - 1; i >= 0; i--)
#define FOBIR(i, n) for (int i = 1; i <= n; i++)
#define FOBIRD(i, n) for (int i = n; i >= 1; i--)
#define pb push_back
// #define mp make_pair
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

const int MAX(ll &a, ll b)
{
    return a = max(a, b); 
}
const int MIN(ll &a, ll b)
{
    return a = min(a, b); 
}

int n, p, k, mp[MAXN];
ll a[MAXN], s[MAXN][HI+3], dp[MAXN][(1 << HI) + 5];

bool comp(int x, int y)
{
	return a[x] > a[y];
}

int main()
{
    int t = 1;
    // cin >> t; // uncomment if it's multitest
    while(t--)
    {
		cin >> n >> p >> k;
		FOBIR(i, n)
		{
			mp[i] = i;
			cin >> a[i];
		}
		sort(mp+1, mp+n+1, comp);
		// FOBIR(i, n) cout << mp[i] << " ";
		// cout << endl;
		FOBIR(i, n) FOR(j, p) cin >> s[i][j];
		// DP time
		memset(dp, -1, sizeof dp);
		dp[0][0] = 0ll;
		FOBIR(i, n)
		{ 
			FOR(bitmask, (1 << p))
			{
				int x = 0;
				FOR(j, p) if(bitmask & (1 << j)) x++;
				x = i-1-x;
				if(dp[i-1][bitmask] != -1)
				{
					if(x < k) MAX(dp[i][bitmask], dp[i-1][bitmask] + a[mp[i]]);
					else MAX(dp[i][bitmask], dp[i-1][bitmask]);
				}
				FOR(j, p) if(bitmask & (1 << j) && dp[i-1][bitmask ^ (1 << j)] != -1)
					MAX(dp[i][bitmask], dp[i-1][bitmask ^ (1 << j)] + s[mp[i]][j]);
			}
		}
		cout << dp[n][(1 << p)-1] << endl;
    }
    
}

