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
#define int ll

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

int n;
pii c[MAXN];

ll sweep()
{
    multiset<int> lhs, rhs;
    FOR(i, n)
    {
        rhs.insert(c[i].s);
    }
    ll mx = 1e15+7;
    FOR(i, n-1)
    {
        lhs.insert(c[i].s);
        auto x = rhs.find(c[i].s);
        if(x != rhs.end()) rhs.erase(x);
        mx = min(mx, (ll)(c[i].f - c[0].f) * (ll)(*lhs.rbegin() - *lhs.begin())
                + (ll)(c[n-1].f - c[i+1].f) * (ll)(*rhs.rbegin() - *rhs.begin()));
        // if(i == 4) cout << mx << endl;
    }
    return mx;
}

signed main()
{
    // 台湾肯定是因为要给别人机会考IOI才拒绝tmw
    fileio("split.in", "split.out");
    int t = 1;
    // cin >> t;
    while(t--)
    {
        cin >> n;
        FOR(i, n) cin >> c[i].f >> c[i].s;
        sort(c, c+n);
        ll tot = 0;
        // sweepline
        int minx = c[0].f;
        int maxx = c[n-1].f;
        tot = max(tot, sweep());
        FOR(i, n)
        {
            int a = c[i].f;
            c[i].f = c[i].s;
            c[i].s = a;
        }
        sort(c, c+n);
        // same sweepline
        tot = min(tot, sweep());
        int miny = c[0].f;
        int maxy = c[n-1].f;
        cout << (maxx - minx) * (maxy - miny) - tot << endl;
    }
}