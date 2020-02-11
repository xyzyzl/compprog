// Time:
// Algorithms:

#include <bits/stdc++.h>

#pragma GCC optimize("O3")

using namespace std;

#define MAXN 100005

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
#define INF (1e9 * 1) + 5

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

#define bitinc(x) x & -x

const int MAX(int &a, int b)
{
    return a = max(a, b);
}
const int MIN(int &a, int b)
{
    return a = min(a, b);
}

int n;
pii poly[MAXN];
signed main()
{
    int t = 1;
    // cin >> t; // uncomment if it's multitest
    while (t--)
    {
        cin >> n;
        FOR(i, n)
        {
            cin >> poly[i].f >> poly[i].s;
        }
        if (n % 2)
        {
            cout << "no" << endl;
            // polygon is kil
            // no
        }
        else
        {
            int m = n / 2;
            bool nice_looking = 1;
            FOR(i, m)
            {
                pii x = poly[i];
                pii x2 = poly[i + m];
                // cout << i + m/2 << endl;
                pii y = poly[(i + 1) % n];
                pii y2 = poly[(i + m + 1) % n];
                // cout << (x.f - y.f) * (x.f - y.f) + (x.s - y.s) * (x.s - y.s) << endl;
                // cout << (x2.f - y2.f) * (x2.f - y2.f) + (x2.s - y2.s) * (x2.s - y2.s) << endl;
                // cout << "--" << endl;
                if(y.f-x.f == 0 || y2.f-x2.f == 0)
                {
                    nice_looking = nice_looking && (y.f-x.f == 0 && y2.f-x2.f == 0);
                    continue;
                }
                if ((double)(y.s-x.s)/(y.f-x.f) == (double)(y2.s-x2.s)/(y2.f-x2.f))
                {
                    nice_looking = (x.f - y.f) * (x.f - y.f) + (x.s - y.s) * (x.s - y.s) == (x2.f - y2.f) * (x2.f - y2.f) + (x2.s - y2.s) * (x2.s - y2.s);
                }
                else
                    nice_looking = 0;
            }
            if (nice_looking)
                cout << "yes" << endl;
            else
                cout << "nO" << endl;
        }
    }
}