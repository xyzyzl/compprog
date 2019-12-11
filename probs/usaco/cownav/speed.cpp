#include <bits/stdc++.h> // :rage: :deciduous_tree:

#pragma GCC optimize("O3")

using namespace std;

#define MAXN 22

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

#define bitinc(x) x&-x

int n, gd[MAXN][MAXN], dist[MAXN][MAXN][4][MAXN][MAXN][4];

int dy[4] = {0, 1, 0, -1};
int dx[4] = {1, 0, -1, 0};

struct state
{
    int adir, ax, ay;
    int bdir, bx, by;
    state(int ax, int ay, int adir, int bx, int by, int bdir)
    {
        this->ax = ax;
        this->ay = ay;
        this->adir = adir;
        this->bx = bx;
        this->by = by;
        this->bdir = bdir;
    }
};

state fw(state cur)
{
    int nax = cur.ax, nay = cur.ay;
    int nbx = cur.bx, nby = cur.by;

    if(nax < n-1 || nay < n-1)
    {
        nax += dx[cur.adir];
        nay += dy[cur.adir];
    }

    if(nbx < n-1 || nby < n-1)
    {
        nbx += dx[cur.bdir];
        nby += dy[cur.bdir];
    }

    if(nax < 0 || nax >= n || nay < 0 || nay >= n)
    {
        nax = cur.ax;
        nay = cur.ay;
    } else if(gd[nax][nay])
    {
        nax = cur.ax;
        nay = cur.ay;
    }
    if(nbx < 0 || nbx >= n || nby < 0 || nby >= n) 
    {
        nbx = cur.bx;
        nby = cur.by;
    } else if(gd[nbx][nby])
    {
        nbx = cur.bx;
        nby = cur.by;
    }

    return state(nax, nay, cur.adir, nbx, nby, cur.bdir);
}

state tl(state cur)
{
    return state(cur.ax, cur.ay, (cur.adir + 3)%4, cur.bx, cur.by, (cur.bdir + 3)%4);
}

state tr(state cur)
{
    return state(cur.ax, cur.ay, (cur.adir + 1)%4, cur.bx, cur.by, (cur.bdir + 1)%4);
}

int main()
{
    fileio("cownav.in", "cownav.out");
    int t = 1;
    // cin >> t;
    while(t--)
    {
        cin >> n;
        FOR(i, n) FOR(j, n)
        {
            char c;
            cin >> c;
            gd[n-i-1][j] = (c=='E') ? 0 : 1;
        }
        
        queue<state> q;
        q.push(state(0, 0, 0, 0, 0, 1));
        
        dist[0][0][0][0][0][1] = 1;
        while(!q.empty())
        {
            state fr = q.front();
            q.pop();
            if(fr.ax == n-1 && fr.ay == n-1 && fr.bx == n-1 && fr.by == n-1)
            {
                cout << dist[fr.ax][fr.ay][fr.adir][fr.bx][fr.by][fr.bdir] - 1 << endl;
                return 0;
            }

            vector<state> v;
            v.pb(fw(fr));
            v.pb(tl(fr));
            v.pb(tr(fr));
            for(state st : v)
            {
                if(!dist[st.ax][st.ay][st.adir][st.bx][st.by][st.bdir])
                {
                    /*
                    cout << st.ax << " " << st.ay << " " << st.adir << " " << st.bx << " " << st.by << " " << st.bdir << endl;
                    cout << fr.ax << " " << fr.ay << " " << fr.adir << " " << fr.bx << " " << fr.by << " " << fr.bdir << endl;
                    cout << "0" << endl;
                    */
                    dist[st.ax][st.ay][st.adir][st.bx][st.by][st.bdir] = dist[fr.ax][fr.ay][fr.adir][fr.bx][fr.by][fr.bdir] + 1;
                    q.push(st);
                }
            }
        }
    }
}