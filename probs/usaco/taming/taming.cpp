#include <bits/stdc++.h>

#pragma GCC optimize("O3")

using namespace std;

#define MAXN 105

#define FOR(i, n) for (int i = 0; i < n; i++)
#define FORR(j, i, n) for (int i = j; i < n; i++)
#define FORD(i, n) for (int i = n - 1; i >= 0; i--)
#define FOBIR(i, n) for (int i = 1; i <= n; i++)
#define pb push_back
#define mp make_pair
#define endl '\n'
#define DUEHOANG                  \
	ios_base::sync_with_stdio(0); \
	cin.tie(NULL);                \
	cout.tie(NULL)

#define JaydenXia(in, out) \
	freopen(in, "r", stdin); \
	freopen(out, "w", stdout);

#define long long long

typedef set<int> si;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef vector<pii> vii;
typedef priority_queue<int> pqi;
typedef stack<int> sti;
typedef queue<int> qi;
typedef deque<int> di;
typedef map<int, int> mii;
#define x first
#define y second

int n, a[MAXN];
int dp[MAXN][MAXN][MAXN];
int main()
{
    JaydenXia("taming.in", "taming.out");
    DUEHOANG;
    cin >> n;
    FOR(i, n) FOR(j, i+1) FOR(k, n+1) dp[i][j][k] = 10005;
    FOR(i, n)
    {
        cin >> a[i];
    }
    dp[0][0][1] = (a[0] != 0);
    // cout << dp[0][0][1] << endl;
    FOBIR(i, n-1)
    {
        FOR(j, i+1)
        {
            FOBIR(k, i+1)
            {
                if(i==j)
                {
                    FOR(m, i)
                    {
                        dp[i][j][k] = min(dp[i][j][k], dp[i-1][m][k-1]);
                    }
                } else dp[i][j][k] = dp[i-1][j][k];

                dp[i][j][k]+=(a[i] != (i-j));
            }
        }
    }
    FOBIR(i, n)
    {
        int mn = 10005;
        FOR(j, n)
        {
            mn = min(mn, dp[n-1][j][i]);
        }
        cout << mn << endl;
    }
}