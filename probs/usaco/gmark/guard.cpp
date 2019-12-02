#include <bits/stdc++.h> // :pig: :flag_us:

#pragma GCC optimize("O3")

using namespace std;

#define MAXN 25

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

#define INF 1e15+7

int n, h[MAXN], w[MAXN], s[MAXN];
ll x, safety[(1 << 21)+5], psum[(1 << 21) + 5];
int main()
{
    fileio("guard.in", "guard.out");
    cin >> n >> x;
    FOR(i, n)
    {
        cin >> h[i] >> w[i] >> s[i];
    }
    psum[0] = 0;
    FOBIR(i, (1 << n) - 1)
    {
        FOR(j, n)
        {
            if(i & (1 << j)) psum[i] += w[j];
        }
    }
    safety[0] = INF;
    ll ans = -1;
    // cout << psum[13] << endl;
    FOBIR(i, (1 << n) - 1)
    {
        // determine which cows to use
        vi v;
        ll th = 0;
        FOR(j, n)
        {
            if(i & (1 << j))
            {
                // use cow #j
                v.pb(j);
                th += h[j];
            }
        }
        ll mx = -1;
        for(int k : v)
        {
            ll res = min(safety[i - (1 << k)], s[k] - psum[i - (1 << k)]);
            mx = max(mx, res);
        }
        safety[i] = mx;
        if(th >= x) ans = max(ans, mx);
    }
    if(ans < 0) cout << "Mark is too tall" << endl;
    else cout << ans << endl;
}