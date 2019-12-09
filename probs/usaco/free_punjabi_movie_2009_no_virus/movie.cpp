#include <bits/stdc++.h> // :rage: :deciduous_tree:

#pragma GCC optimize("O3")

using namespace std;

#define MAXN 25
#define MAXC 1005

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

#define bitinc(x) x & -x

int n, L, c[MAXN], d[MAXN], arr[MAXN][MAXC], dp[(1 << 20)];

int latest_possible(int x, int i)
{
    // bin search for greatest x s.t. ar[x] <= val
    int lo = -1, hi = c[i] - 1;
    while (lo < hi)
    {
        int mid = (lo + hi + 1) / 2;
        if (arr[i][mid] <= x)
        {
            lo = mid;
        }
        else
        {
            hi = mid - 1;
        }
    }
    return lo;
}

int main()
{
    fileio("movie.in", "movie.out");
    int t = 1;
    // cin >> t;
    while (t--)
    {
        cin >> n >> L;
        FOR(i, n)
        {
            cin >> d[i] >> c[i];
            FOR(j, c[i])
                cin >> arr[i][j];
        }

        FOR(i, (1 << n))
        dp[i] = -1;
        dp[0] = 0;
        int ans = -1;
        FOR(m, (1 << n))
        {
            if (dp[m] == -1)
                continue; // unreachable state

            if (dp[m] >= L)
            {
                int moo = __builtin_popcount(m);
                ans = (ans == -1 ? moo : min(ans, moo));
            }

            FOR(i, n)
            {
                if (m & (1 << i))
                    continue; // useless to watch, it's alr in m

                int nm = (m | (1 << i));
                int best = latest_possible(dp[m], i);

                int t = arr[i][best] + d[i];
                dp[nm] = max(dp[nm], t);
            }
        }
        cout << ans << endl;
    }
}