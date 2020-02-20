// Time:
// Algorithms: 

#include <bits/stdc++.h>

#pragma GCC optimize("O3")

using namespace std;

#define MAXN 1000055

#define int long long

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

#define O mp(0,0)

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

int n, arr[MAXN];
pii pts[MAXN];

unsigned int dist_2(pii p1, pii p2)
{
    return (((unsigned int)p1.f-p2.f)*(p1.f-p2.f) + ((unsigned int)p1.s-p2.s)*(p1.s-p2.s));
}

int orientation(pii p, pii q, pii r) 
{ 
    int val = (q.s - p.s) * (r.f - q.f) - (q.f - p.f) * (r.s - q.s);
    if (val == 0) return 0;
    return (val > 0)? 1: 2;
}

bool comp(pii a, pii b)
{
    int x = orientation(O, a, b);
    if(x == 0)
    {
        return (dist_2(O, b) >= dist_2(O, a));
    }
    return (x == 1);
}

pii sec_to_top(stack<pii> &st)
{
    pii tp = st.top();
    st.pop();
    pii ret = st.top();
    st.push(tp);
    return ret;
}

vii hull;
void convex()
{
    sort(pts+1, pts+n+2, comp); // sort the points
    // cerr << "tUrkmenistan" << endl;

    // cerr << pts[79976].f << " " << pts[79976].s << endl;
    int m = 1;
    FOBIR(i, n+1)
    {
        while(i < n+1 && orientation(O,pts[i],pts[i+1]) == 0) i++;
        pts[m] = pts[i];
        ++m;
    }
    // cerr << "brug" << endl;
    // cerr << m << endl;
    stack<pii> st;
    // cerr << "jldsljkfd" << endl;
    FOR(i, m)
    {
        // cerr << i << endl;
        while(st.size() >= 2 && orientation(sec_to_top(st), st.top(), pts[i]) != 1)
        {
            st.pop();
        }
        st.push(pts[i]);
    }
    // cerr << "ajdflakdjflkadjf" << endl;
    while(!st.empty())
    {
        // cout << st.top().f << endl;
        hull.pb(st.top());
        st.pop();
    }
    reverse(hull.begin(), hull.end());
}

ll l[MAXN], r[MAXN];
signed main()
{
    DUEHOANG;
    fileio("balance.in", "balance.out");
    int t = 1;
    // cin >> t; // uncomment if it's multitest
    while(t--)
    {
        cin >> n;
        FOBIR(i, n)
        {
            // cerr << i << endl;
            cin >> arr[i];
        }
        
        FOBIR(i, n)
        {
            pts[i].s = arr[i];
            pts[i].f = i;
        }
        pts[0] = mp(0, 0);
        pts[n+1] = mp(n+1, 0);
        // cerr << "bruh" << endl;
        convex(); // gives the entire convex hull, but we only care about the upper portion
        FOR(i, hull.size()-1)
        {
            FORR(hull[i].f + 1, j, hull[i+1].f)
            {   
                l[j] = hull[i].f;
                r[j] = hull[i+1].f;
            }
            l[hull[i].f] = r[hull[i].f] = hull[i].f;
        }
        l[n+1] = r[n+1] = hull.back().f;
        FOBIR(i, n)
        {
            if(l[i] == r[i])
            {
                cout << 100000ll * arr[i] << endl;
            } else 
            {
                cout << 100000ull * (((unsigned int)(r[i] - i) * (unsigned int)arr[l[i]]) + ((unsigned int)(i - l[i]) * (unsigned int)arr[r[i]])) / ((unsigned int) r[i] - l[i]) << endl;
            }
        }
    }
    
}