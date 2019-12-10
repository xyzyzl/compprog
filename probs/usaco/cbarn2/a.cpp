#include <bits/stdc++.h> // :rage: :deciduous_tree:

#pragma GCC optimize("O3")

using namespace std;

#define MAXN 105
#define MAXK 10

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

#define fileio(in, out)      \
    freopen(in, "r", stdin); \
    freopen(out, "w", stdout);

#define ll long long

typedef set<int> si;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef pair<int, pii> iii;
typedef vector<pii> vii;
typedef priority_queue<int> pqi;
typedef stack<int> sti;
typedef queue<int> qi;
typedef deque<int> di;
typedef map<int, int> mii;
#define f first
#define s second

#define INF 1e15 + 7

#define LEFT(x) 2 * x
#define RIGHT(x) 2 * x + 1

#define bitinc(x) x&-x

int n, k;
ll arr[MAXN], dp[MAXN][MAXK];
int main()
{
    fileio("cbarn2.in", "cbarn2.out");
    int t = 1;
    // cin >> t;
    while(t--)
    {
        ll res = LLONG_MAX;
        cin >> n >> k;
        FOR(i, n) cin >> arr[i];
        FOR(rot, n)
        {
            FOR(i, n+1) FOR(j, k+1) dp[i][j] = INF;
            dp[n][0] = 0;
            FOBIR(open, k)
            {
                FOR(i, n)
                {
                    ll x = 0;
                    FORR(i, j, n)
                    {
                        x += (arr[j]) * (j-i);
                        dp[i][open] = min(dp[i][open], x + dp[j+1][open-1]); // open at the jth
                    }
                }
            }
            res = min(res, dp[0][k]);
            rotate(arr, arr+1, arr+n);
        }
        cout << res << endl;
    }
}