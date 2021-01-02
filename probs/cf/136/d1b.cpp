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

int n = 8;
viii pt;

bool perp(pii a, pii b)
{
    // we're treating vectors as pairs since they are 2d
    return !(a.f*b.f + a.s*b.s);
}

int sqdist(pii a, pii b)
{
    return (a.f-b.f)*(a.f-b.f) + (a.s-b.s)*(a.s-b.s);
}

int main()
{
    int t = 1;
    // cin >> t; // uncomment if it's multitest
    while(t--)
    {
        FOR(i, n) 
        {
            int a,b;
            cin >> a >> b;
            pt.pb(mp(i, mp(a,b)));
        }
        bool orz = 0;
        do
        {
            // two tasks:
            // check if rect
            // check if square
            // we can set first four to make a square and last four to make a rect

            // --- step 1: make a square --- //
            vii vs; // all the vectors
            bool fail = 0;
            si blah;
            FOR(i, 4)
            {
                int j = (i+1)%4;
                int d = sqdist(pt[i].s, pt[j].s);
                blah.insert(d);
                vs.pb(mp(pt[j].s.f - pt[i].s.f, pt[j].s.s - pt[i].s.s));
            }
            FOR(i, 4)
            {
                int j = (i+1)%4;
                if(!perp(vs[i], vs[j])) fail = 1;
            }
            if(blah.size() > 1)
            {
                fail = true;
            }

            if(fail) continue;

            vi a, b;
            FOR(i, 4) 
            {
                a.pb(pt[i].f);
            }

            // --- step 2: check if remaining ones form a rectangle --- //
            vs.clear();
            FOR(i, 4)
            {
                int x = i+4;
                int y = (i+1)%4+4;
                vs.pb(mp(pt[y].s.f - pt[x].s.f, pt[y].s.s - pt[x].s.s));
            }
            FOR(i, 4)
            {
                int j = (i+1)%4;
                if(!perp(vs[i], vs[j])) fail = 1;
            }
            if(fail) continue;

            FOR(i, 4) 
            {
                b.pb(pt[i+4].f);
            }

            cout << "YES" << endl;
            FOR(i, 4) cout << a[i]+1 << " ";
            cout << endl;
            FOR(i, 4) cout << b[i]+1 << " ";
            cout << endl;
            orz = 1;
            break;

            // --- now we have a rectangle and a square --- //
        } while(next_permutation(pt.begin(), pt.end()));
        if(!orz) cout << "NO" << endl;
    }
    
}