// Time:
// Algorithms: 

#include <bits/stdc++.h>

#pragma GCC optimize("O3")

using namespace std;

#define MAXN 1005

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

int n, m;
vii adj[MAXN];
map<pii, double> fl;
int wt[MAXN];

int not_prim(int src, int min_flow)
{
	fill(wt, wt + n, INF);

	set<pii> pq;
	pq.insert(mp(0, src));

	wt[src] = 0;

	int ct = 0;
	while (!pq.empty())
	{
		pii tp = *pq.begin();
		pq.erase(pq.begin());

		for (pii gu : adj[tp.s])
		{
			int w = gu.f;
			int ind = gu.s;
            if (fl[{tp.s, ind}] < min_flow) continue;
			if (wt[tp.s] + w < wt[ind])
			{
				pq.erase(mp(wt[ind], ind));
				wt[ind] = wt[tp.s] + w;
				pq.insert(mp(wt[ind], ind));
			}
		}
	}
    return wt[n-1];
}

vi v;
int main()
{
    fileio("pump.in", "pump.out");
    int t = 1;
    // cin >> t; // uncomment if it's multitest
    while(t--)
    {
        cin >> n >> m;
        FOR(i, m)
        {
            int a, b, c, f;
            cin >> a >> b >> c >> f;
            v.pb(f);
            a--; b--;
            adj[a].pb(mp(c, b));
            adj[b].pb(mp(c, a));
            fl[{a,b}] = f;
            fl[{b,a}] = f;
        }
        ll num, den, bnum = 0, bden = 1;
        for(int x : v)
        {
            num = x;
            den = not_prim(0, x);
            // FOR(i, n) cout << wt[i] << " " << endl;
            // cout << num << " " << den << endl;
            if(den != -1 && den != INF)
            {
                // is num, den better than bnum, bden??
                if(den * bnum < num * bden)
                {
                    // cout << num << endl;
                    bnum = num;
                    bden = den;
                }
            }            
        }
        // cout << bnum << " " << bden << endl;
        cout << (1000000LL * bnum) / bden << endl;
    }  
}