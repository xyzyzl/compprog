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

#define O make_pair(0,0)

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
long double ans[MAXN];
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
    return (x == 2);
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
    int ymin = pts[0].s, mn = 0;
    FOBIR(i, n)
    {
        int y = pts[i].s;
        if(y < ymin)
        {
            ymin = y;
            mn = i;
        }
    }
    pii thing = pts[0];
    pts[0] = pts[mn];
    pts[mn] = thing;
    sort(pts+1, pts+n+1, comp); // sort the points
    // cerr << "tUrkmenistan" << endl;

    // cerr << pts[79976].f << " " << pts[79976].s << endl;
    int m = 1;
    FOBIR(i, n)
    {
        while(i < n && orientation(O,pts[i],pts[i+1]) == 0) i++;
        pts[m] = pts[i];
        ++m;
    }
    // cerr << "brug" << endl;
    if(m < 3)
    {
        FOR(i, m)
        {
            hull.pb(pts[i]);
        }
        return;
    }
    // cerr << m << endl;
    stack<pii> st;
    // cerr << "jldsljkfd" << endl;
    st.push(pts[0]);
    st.push(pts[1]);
    st.push(pts[2]);
    bool blah = 0;
    FORR(3, i, m)
    {
        // cerr << i << endl;
        while(st.size() > 2 && orientation(sec_to_top(st), st.top(), pts[i]) != 2)
        {
            if(!blah)
            {
                blah = 1;
                // cerr << st.top().f << endl;
            }
            st.pop();
        }
        st.push(pts[i]);
        if(i == 80000)
        {
            // cerr << "hello!" << endl;
        }
    }
    // cerr << "ajdflakdjflkadjf" << endl;
    while(!st.empty())
    {
        hull.pb(st.top());
        st.pop();
    }
    reverse(hull.begin(), hull.end());
    
    for(pii p : hull)
    {
        // if(p.f == 80001) cerr << p.s << endl;
        // cerr << p.f << " " << p.s << endl;
    }
}

signed main()
{
    DUEHOANG;
    // fileio("bruh.txt", "ok.txt");
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
        if(n == 1)
        {
            cout << setprecision(9) << fixed << (double)arr[1] << endl;
            return 0;
        }
        FOBIR(i, n)
        {
            pts[i].s = arr[i] + pts[i-1].s;
            pts[i].f = i;
        }
        pts[0] = mp(0, 0);
        // cerr << "bruh" << endl;
        convex(); // gives the entire convex hull, but we only care about the lower portion
        FOBIR(i, hull.size()-1)
        {
            // if(hull[i] < hull[i-1]) break;
            long double ret = (long double)(hull[i].s - hull[i-1].s)/(long double)(hull[i].f - hull[i-1].f);
            // if(ret == 79999.5) cerr << hull[i].f << " " << hull[i-1].f << endl;
            FORR(hull[i-1].f, j, hull[i].f)
            {
                cout << setprecision(9) << fixed << ret << endl;
            }
        }
    }
    
}