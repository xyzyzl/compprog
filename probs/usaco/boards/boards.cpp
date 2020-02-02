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
typedef pair<pii, int> iii;
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

int n, p;
ll dp[MAXN];
pair<pii, pii> bb[MAXN];
viii lst;
int main()
{
    fileio("boards.in", "boards.out");
    int t = 1;
    // cin >> t; // uncomment if it's multitest
    while(t--)
    {
        cin >> n >> p;
        FOBIR(i, p)
        {
            int x1, y1, x2, y2;
            cin >> x1 >> y1 >> x2 >> y2;
            bb[i] = (mp(mp(x1, y1), mp(x2, y2)));
            lst.pb(mp(mp(x2, y2), i));
        }
        lst.pb(mp(mp(-1, -1), INT_MIN));
        lst.pb(mp(mp(0,0), 0));
        lst.pb(mp(mp(n,n), p+1));
        sort(lst.begin(), lst.end());
        bb[0] = mp(mp(0, 0), mp(0, 0));
        bb[p+1] = mp(mp(n, n), mp(n, n));
        fill(dp, dp+p+4, 1e15+5);
        dp[0] = 0;
        FOBIR(i, p+1)
        {
            for(auto it = prev(upper_bound(lst.begin(), lst.end(), mp(bb[i].f, INT_MAX))); it != lst.begin(); it--)
            {
                int j = it->s;
                if(i == j) continue;
                if(bb[j].s.s > bb[i].f.s || bb[j].s.f > bb[i].f.f) continue;
                dp[i] = min(dp[i], dp[j] + (ll)(bb[i].f.f - bb[j].s.f + bb[i].f.s - bb[j].s.s));
            }
        }
        cout << dp[p+1] << endl;
    }
    
}