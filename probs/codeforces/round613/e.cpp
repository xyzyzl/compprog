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

mii seg;
// initial # segments
int init(vii segs)
{
    int ret = 0;
    int curr_l = INT_MIN, curr_r = INT_MIN;
    sort(segs.begin(), segs.end());
    FOR(i, segs.size())
    {
        // cout << curr_r << endl;
        if(segs[i].f > curr_r)
        {
            ret++;
            if(curr_l != INT_MIN) seg[curr_l] = 0;
            curr_l = segs[i].f;
            curr_r = segs[i].s;
        } else 
        {
            MAX(curr_r, segs[i].s); // extend the segment
        }
    }
    seg[curr_l] = 0;
    return ret;
}

// sweep sweep!
void sweep(viii queries, vi& ans)
{
    si curr;
    FOR(i, queries.size())
    {
        vi x, o;
        int j = i-1;
        while(j+1 < queries.size() && queries[j+1].f == queries[i].f)
        {
            j++;
            if(queries[j].s.s == 1)
            {
                x.pb(queries[j].s.f);
            } else
            {
                o.pb(queries[j].s.f);
            }
        }
        if(curr.size() == 1 && !x.empty())
        {
            // can add new segment!
            ans[*curr.begin()]++;
        }
        for(int xo : x)
        {
            curr.insert(xo);
        }
        for(int xo : o)
        {
            curr.erase(xo);
        }
        i = j;
    }
}

void blah()
{
    seg.clear();
    int n;
    cin >> n;
    viii qu;
    
    vii v;
    FOR(i, n)
    {
        int o, c;
        cin >> o >> c;
        v.pb({o,c});
        qu.pb(mp(o, mp(i, 1)));
        qu.pb(mp(c, mp(i, -1)));
    }
    sort(qu.begin(), qu.end());

    vi ans(n);
    fill(ans.begin(), ans.end(), 0);
    int x = init(v);
    // cout << x << endl;
    sweep(qu, ans);

    FOR(i, n)
    {
        if(seg.count(v[i].f))
        {
            seg[v[i].f]++;
        }
    }
    FOR(i, n) // tmw orz
    {
        if(seg[v[i].f] == 1)
        {
            ans[i]--;
        }
    }

    int best = INT_MIN;
    for(int x : ans)
    {
        MAX(best, x);
    }
    cout << best + x << endl;
}

int main()
{
    int t = 1;
    cin >> t; // uncomment if it's multitest
    while(t--)
    {
        blah(); // idk i'm scared that test cases will spillover
        // so although it makes me morally appalled, i will not use globals
    }
    
}