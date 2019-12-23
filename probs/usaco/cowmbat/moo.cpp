// Time:
// Algorithms: 

#include <bits/stdc++.h>

#pragma GCC optimize("O3")

using namespace std;

#define MAXN 100005
#define MAXK 30

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

int n, m, k, a[MAXN], mn_v[MAXN];
int al[MAXK][MAXK], dp[MAXN][MAXK], ps[MAXN][MAXK];
int main()
{
    int t = 1;
    // cin >> t; // uncomment if it's multitest
    while(t--)
    {
        memset(dp, 0x3f, sizeof(dp));
        memset(mn_v, 0x3f, sizeof(mn_v));
        DUEHOANG;
        fileio("cowmbat.in", "cowmbat.out");
        cin >> n >> m >> k;
        FOBIR(i, n)
        {
            char c;
            cin >> c;
            a[i] = c - 'a';
            // cout << a[i] << endl;
        }
        FOR(i, m) FOR(j, m) cin >> al[i][j];
        FOR(k, m) FOR(i, m) FOR(j, m)
        {
            if(al[i][k] + al[k][j] < al[i][j]) al[i][j] = al[i][k] + al[k][j];
        }
        FOBIR(i, n)
        {
            FOR(j, m) 
            {
                ps[i][j] = ps[i-1][j] + al[a[i]][j];
            }
        }
        mn_v[0] = 0;
        FOBIR(i, n)
        {
            FOR(j, m)
            { 
                dp[i][j] = min(dp[i][j], dp[i-1][j] + al[a[i]][j]);
                if(i>=k) dp[i][j] = min(ps[i][j] - ps[i-k][j] + mn_v[i-k], dp[i][j]);
                MIN(mn_v[i], dp[i][j]);
            }
        }
        cout << mn_v[n] << endl;
    }
}