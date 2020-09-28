// Time:
// Algorithms: 

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> // pbds
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/detail/standard_policies.hpp>

#pragma GCC optimize("O3")

using namespace __gnu_pbds;
using namespace std;

#define MAXN 200005

#define FOR(i, n) for (int i = 0; i < n; i++)
#define FORR(j, i, n) for (int i = j; i < n; i++)
#define FORD(i, n) for (int i = n - 1; i >= 0; i--)
#define F1R(i, n) for (int i = 1; i <= n; i++)
#define F1RD(i, n) for (int i = n; i >= 1; i--)
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
#define MOD (1e9*1)+7
#define MOD2 998244353
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
// ordered_set
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> os;
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

int n, m, p[2010], sz[2010];
ll w, h;
iii pts[2010], vs[100010];

int find_set(int i)
{
    return (p[i] == i) ? i : (p[i] = find_set(p[i]));
}

bool union_set(int i, int j)
{
    int x = find_set(i);
    int y = find_set(j);
    if (x == y)
        return false;
    p[x] = p[y] = x;
    sz[x] += sz[y];
    return true;
}

void init()
{
    for(int i = 0; i < 2005; i++) p[i] = i;
    for(int i = 0; i < 2005; i++) sz[i] = 1;
}

double dist(pii a, pii b)
{
	return sqrt((a.f-b.f)*(a.f-b.f) + (a.s-b.s)*(a.s-b.s));
}

void solve()
{
	cin >> n >> m;
	cin >> w >> h;
	FOR(i, n)
	{
		cin >> pts[i].s.f >> pts[i].s.s >> pts[i].f;
	}
	FOR(i, m)
	{
		int r, c;
		cin >> r >> c;
		vs[i] = mp(r*2, mp(c-1, i));
	}
	vector<pair<double, pair<int, int> > > eg;
	FOR(i, n)
	{
		FORR(i+1,j,n)
		{
			eg.pb(mp(dist(pts[i].s, pts[j].s) - pts[i].f - pts[j].f, mp(i+4, j+4)));
		}
	}
	FOR(i, n)
	{
		eg.pb(mp(dist(pts[i].s, mp(0, pts[i].s.s)) - pts[i].f, mp(i+4, 0)));
		eg.pb(mp(dist(pts[i].s, mp(pts[i].s.f, 0)) - pts[i].f, mp(i+4, 1)));
		eg.pb(mp(dist(pts[i].s, mp(w, pts[i].s.s)) - pts[i].f, mp(i+4, 2)));
		eg.pb(mp(dist(pts[i].s, mp(pts[i].s.f, h)) - pts[i].f, mp(i+4, 3)));
	}
	sort(eg.begin(), eg.end());
	sort(vs, vs+m);
	init();
	int ind = 0;
	bool bad[4][4];
	memset(bad, 0, sizeof bad);
	for(auto e : eg)
	{
		while(ind < m && vs[ind].f <= e.f)
		{
			bool C[4][4];
			FOR(i, 4)
			{
				C[i][i] = 1;
				FORR(i+1, j, 4)
				{
					C[i][j] = find_set(i) == find_set(j);
					C[j][i] = C[i][j];
				}
			}
			iii cur = vs[ind];
			FOR(i, 4)
			{
				if(cur.s.f == i) continue;
				if(C[cur.s.f][(cur.s.f+1)%4] || C[i][(i+1)%4])
				{
					// cerr << "oh" << endl;
					bad[cur.s.s][i] = 1;
				}
				bool vblock = C[1][3];
				bool hblock = C[0][2];
				if(abs(cur.s.f - i) == 2)
				{
					// cerr << "my" << endl;
					if(vblock || hblock) bad[cur.s.s][i] = 1;
				} else if(cur.s.f + i == 3)
				{
					// cerr << "fucking" << endl;
					if(hblock) bad[cur.s.s][i] = 1;
				} else 
				{
					// cerr << "god" << endl;
					if(vblock) bad[cur.s.s][i] = 1;
				}
			}
			ind++;
			if(ind >= m) break;
		}
		union_set(e.s.f, e.s.s);
	}
	FOR(i, m)
	{
		FOR(j, 4)
		{
			if(!bad[i][j]) cout << (j+1);
		}
		cout << endl;
	}
}

signed main()
{
	DUEHOANG;
	int t = 1;
	// cin >> t; // uncomment if it's multitest
	while(t--)
	{
		solve();
	}
	
}
