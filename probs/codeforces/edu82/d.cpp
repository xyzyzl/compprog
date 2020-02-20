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

#define int ll

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

signed main()
{
    int t = 1;
    cin >> t; // uncomment if it's multitest
    while(t--)
    {
        ll n;
        int m;
        cin >> n >> m;
        vi x(69);
        ll sm = 0;
        FOR(i, m)
        {
            int a; cin >> a;
            sm += a;
            x[(int)log2(a)]++;
        }
        if(sm < n)
        {
            cout << -1 << endl;
            continue;
        }
        ll ans = 0;
        int i = 0;
        while(i < 60)
        {
            if(n & (1ll << i))
            {
                if(x[i])
                {
                    x[i]--;
                } else 
                {
                    while(i < 60 && !x[i])
                    {
                        i++;
                        ans++;
                    }
                    x[i]--;
                    continue;
                }
            }
            x[i+1] += (x[i]/2);
            i++;
        }
        cout << ans << endl;
    }
    
}