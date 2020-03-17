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

int n, K, a[MAXN];
int dp[MAXN][25][4];

int main()
{
	DUEHOANG;
	fileio("hps.in", "hps.out");
    int t = 1;
    // cin >> t; // uncomment if it's multitest
    while(t--)
    {
    	cin >> n >> K;
    	FOBIR(i, n)
    	{
    		char c;
    		cin >> c;
    		switch(c)
    		{
    			case 'H': a[i] = 0; break;
    			case 'P': a[i] = 1; break;
    			default: a[i] = 2; break;
    		}
    	}
    	FOR(i, MAXN) FOR(j, 25) FOR(k, 4) dp[i][j][k] = -INF;
    	dp[0][0][0] = dp[0][0][1] = dp[0][0][2] = 0;
    	FOBIR(i, n)
    	{
    		FOR(j, K+1)
    		{
    			FOR(k, 3)
    			{
    				FOR(other, 3)
    				{
    					if(other==k) continue;
    					if(j > 0) MAX(dp[i][j][k], max(dp[i-1][j-1][other], dp[i-1][j][k]) + (k == a[i]));
    					else MAX(dp[i][j][k], dp[i-1][j][k] + (k == a[i]));
    				}
    			}
    		}
    	}
    	int mx = 0;
    	FOR(i, 3) MAX(mx, dp[n][K][i]);
    	cout << mx << endl;
    }
    
}
