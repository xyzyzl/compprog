#include <bits/stdc++.h> // :rage: :deciduous_tree:

#pragma GCC optimize("O3")

using namespace std;

#define MAXN 255

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

#define LEFT(x) 2 * x
#define RIGHT(x) 2 * x + 1

#define bitinc(x) x&-x

int n, a[MAXN], dp[MAXN][MAXN];
int main()
{
    DUEHOANG;
    fileio("248.in", "248.out");
    int t = 1;
    // cin >> t;
    while(t--)
    {
        cin >> n;
        FOR(i, n) cin >> a[i];
        FOBIR(len, n)
        {
            FOR(i, n)
            {
                int j = i+len-1;
                if(len == 1) dp[i][j] = a[i];
                FOR(mid, len-1)
                {
                    if(dp[i][i+mid] && (dp[i][i+mid] == dp[i+mid+1][j])) dp[i][j] = dp[i][i+mid]+1;
                }
            }
        }
        int x = 0;
        FOR(i, n) FOR(j, n) x = max(x, dp[i][j]);
        cout << x << endl;
    }
}