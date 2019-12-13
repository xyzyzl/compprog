#include <bits/stdc++.h>

#pragma GCC optimize("O3")

using namespace std;

#define MAXN 505

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

const int MAX(int &a, int b)
{
    return a = max(a, b); 
}
const int MIN(int &a, int b)
{
    return a = min(a, b); 
}

int n, m;
pair<pii, bool> pt[MAXN];
vi y_cd;
int main()
{
    fileio("cowrect.in", "cowrect.out");
    cin >> n;
    FOR(i, n)
    {
        char c;
        cin >> pt[i].f.f >> pt[i].f.s >> c;
        pt[i].s = c=='H';
        y_cd.pb(pt[i].f.s);
    }
    sort(pt, pt+n);
    // FOR(i, n) cout << pt[i].s << " ";
    // cout << endl;
    unique(y_cd.begin(), y_cd.end());
    sort(y_cd.begin(), y_cd.end());
    /*
    FOR(i, y_cd.size())
    {
        cout << y_cd[i] << " ";
    }
    */
    // cout << endl;
    m = y_cd.size();
    int cow = 0, area = INT_MAX;
    FOR(i, m)
    {
        FORR(i+1, j, m)
        {
            // cout << "fortnite is haram!" << endl;
            bool pure = 0;
            int pre_x = -1;
            int c_cow = 0;
            for(int l = 0; l < n;)
            {
                int r = l;
                int ho = 0, gu = 0;
                while(r < n && pt[r].f.f == pt[l].f.f)
                {
                    if(y_cd[i] > pt[r].f.s || pt[r].f.s > y_cd[j])
                    {
                        r++;
                        continue;
                    }
                    // of all the points with this x-value, see if it's pure.
                    if(pt[r].s) ho++;
                    else gu++; // this is bad.
                    r++;
                }
                if(gu)
                {
                    pure = 0;
                    c_cow = 0;
                }
                else if(ho+gu)
                {
                    // there is a suitable cow here
                    if(!pure)
                    {
                        pure = 1;
                        pre_x = pt[l].f.f;
                    }
                    c_cow += ho;
                    int c_are = (y_cd[j] - y_cd[i]) * (pt[l].f.f - pre_x); 
                    if(c_cow > cow || (c_cow == cow && area > c_are))
                    {
                        // cout << y_cd[i] << ", " << y_cd[j] << endl;
                        // cout << y_cd[j] - y_cd[i] << " " << pt[l].f.f - pre_x << endl;
                        cow = c_cow;
                        area = c_are;
                    }
                }
                l=r;
            }
        }
    }
    printf("%d\n%d\n", cow, area);
}