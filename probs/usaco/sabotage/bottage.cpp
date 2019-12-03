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

int n, x[MAXN];

int sp3(double x)
{
    return (int)(1000.0 * x + 0.5);
}

bool nice(double q)
{
    int total = 0;
    double best, cur;
    FOR(i, n)
    {
        total += x[i];
    }
    best = cur = x[1] - q;
    for(int i = 2; i < n-1; i++)
    {
        if(cur < 0) cur = 0;
        cur += x[i] - q;
        best = max(best, cur);
    }
    return best >= total - q*n;
}

int main()
{
    fileio("sabotage.in", "sabotage.out");
    int t = 1;
    // cin >> t;
    while(t--)
    {
        cin >> n;
        FOR(i, n) cin >> x[i];
        double lo = 0.0, hi = 10000.0;
        while(sp3(lo) != sp3(hi))
        {
            // cout << (sp3(lo) - sp3(hi)) << endl;
            double mid = (lo+hi)/2;
            if(nice(mid)) hi = mid;
            else lo = mid;
        }
        cout << setprecision(3) << fixed << lo << endl;
    }
}