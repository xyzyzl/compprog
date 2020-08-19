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

ll xz, yz, ax, ay, bx, by;
ll sx, sy, mt;
int n;

ll man_dist(ll x1, ll y1, ll x2, ll y2)
{
    return abs(x2-x1) + abs(y2-y1);
}

int main()
{
    int t = 1;
    // cin >> t; // uncomment if it's multitest
    while(t--)
    {
        cin >> xz >> yz >> ax >> ay >> bx >> by;
        cin >> sx >> sy >> mt;        
        vector<ll> x, y;
        ll top = 1e18+1;
        // cout << top << endl;
        x.pb(xz);
        y.pb(yz);
        while((top-bx)/ax >= x.back() && (top-by)/ay >= y.back())
        {
            // init all possible values of data points
            x.pb(ax*x.back() + bx);
            y.pb(ay*y.back() + by);
        }

        n = x.size();
        int ans = 0;
        FOR(i, n) FOR(j, n)
        {
            ll common_dist = man_dist(x[i], y[i], x[j], y[j]);
            if(mt >= min(man_dist(sx, sy, x[i], y[i]) + common_dist, man_dist(sx, sy, x[j], y[j]) + common_dist)) MAX(ans, j-i+1); // must be in a contiguous segment up/right
        }
        // otherwise you will be going up to get something then down to get something else, which is bad, or you're skipping something
        // that you could have gotten in the same time amount
        cout << ans << endl;
        
    }
    
}