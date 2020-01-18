// Time:
// Algorithms: 

#include <bits/stdc++.h>

#pragma GCC optimize("O3")

using namespace std;

#define MAXN 1000005

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
typedef vector<long long> vi;
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

int n, B;
vi v, dp, fv;
int main()
{
    DUEHOANG;
    fileio("mooomoo.in", "mooomoo.out");
    int t = 1;
    // cin >> t; // uncomment if it's multitest
    while(t--)
    {
        dp.resize(1e6+5);
        cin >> n >> B;
        v.resize(B);
        FOR(i, B)
        {
            cin >> v[i];
        }
        fv.resize(n+1);
        fv[0] = 0;
        FOBIR(i, n)
        {
            cin >> fv[i];
        }
        fill(dp.begin(), dp.end(), INF);
        dp[0] = 0;
        FOR(i, 1e6+5)
        {
            FOR(j, B)
            {
                if(i >= v[j]) dp[i] = min(dp[i], 1ll + dp[i-v[j]]);
            }
        }
        int ans = 0;
        FOBIR(i, n)
        {
            int ls = max(fv[i-1]-1, 0ll);
            int x = fv[i] - ls;
            if(x < 0)
            {
                cout << -1 << endl;
                return 0;
            } else 
            {
                // cout << dp[x] << endl;
                if(dp[x] == INF)
                {
                    cout << -1 << endl;
                    // this is unattainable since there is no way for this 
                    // volume level
                }
                ans += dp[x];
            }
        }
        cout << ans << endl;
    }
    
}