#include <bits/stdc++.h> // :rage: :deciduous_tree:

#pragma GCC optimize("O3")

using namespace std;

#define MAXN 100005

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

int n, k, w[MAXN], t[MAXN];
ll dp[MAXN];

bool attainable(int x)
{
    FOR(i, k+1) dp[i] = -1e15-7;
    dp[0] = 0;
    FOR(i, n)
    {
        ll a = 1000*(ll)t[i] - x*(ll)w[i];
        int inc = w[i];
        FORD(j, k+1)
        {
            int ind = min(k, j+inc);
            dp[ind] = max(dp[ind], dp[j] + a);
        }
    }
    // cout << dp[k] << endl;
    return dp[k] >= 0;
}

int main()
{
    fileio("talent.in", "talent.out");
    int ASFD = 1;
    // cin >> t;
    while(ASFD--)
    {
        cin >> n >> k;
        FOR(i, n)
        {
            cin >> w[i] >> t[i];
        }
        int lo = 0, hi = 250*1000*1000+1;
        while(lo + 1 < hi)
        {
            int mid = (lo+hi)/2;
            if(attainable(mid))
            {
                lo = mid;
            } else 
            {
                hi = mid;
            }
        }
        cout << lo << endl;
    }
}