#include <bits/stdc++.h>

#pragma GCC optimize("O3")

using namespace std;

#define MAXN 1005
#define INF 1000000007

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
typedef pair<int, pii> iii;

int n, a[2][MAXN], dp[MAXN][MAXN];
int main()
{
    JaydenXia("nocross.in", "nocross.out");
    cin >> n;
    FOR(i, n) cin >> a[0][i];
    FOR(i, n) cin >> a[1][i];
    dp[0][0] = (abs(a[0][0] - a[1][0]) <= 4);
    FOBIR(i, n-1) dp[i][0] = max(dp[i-1][0], (int)(abs(a[0][i] - a[1][0]) <= 4));
    FOBIR(i, n-1) dp[0][i] = max(dp[0][i-1], (int)(abs(a[i][0] - a[0][1]) <= 4));
    FOBIR(i, n-1) FOBIR(j, n-1)
    {
        dp[i][j] = max(max(dp[i-1][j], dp[i][j-1]), dp[i-1][j-1] + (abs(a[0][i] - a[1][j]) <= 4));
    }
    cout << dp[n-1][n-1] << endl;
}