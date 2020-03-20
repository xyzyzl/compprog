// Time:
// Algorithms: 

#include <bits/stdc++.h>

#pragma GCC optimize("O3")

using namespace std;

#define MAXN 305

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

int n, blw[MAXN][MAXN], ans[MAXN];
pii pts[MAXN];

bool y_below(pii a, pii p) // a below p
{
	return (a.f == p.f && a.s < p.s); 
}

bool p_below_seg(pii a, pii b, pii p)
{
	int dx = (a.f - b.f);
	int dy = (a.s - b.s);
	double x = p.f, y = p.s;
	if(x <= min(a.f, b.f) || x >= max(a.f, b.f)) return 0;
	return (y < ((double)dy/(double)dx) * (double)(x-a.f) + (double)a.s);
}

int below_ln(pii a, pii b)
{
	int dx = (a.f - b.f);
	int dy = (a.s - b.s);
	int ct=0;
	FOR(i, n)
	{
		double x = pts[i].f, y = pts[i].s;
		// eliminate the ones that don't count
		if(x < min(a.f, b.f) || x > max(a.f, b.f)) continue;
		if(x == min(a.f, b.f)) ct+= y_below(pts[i], min(a,b));
		else if (x == max(a.f, b.f)) ct+= y_below(pts[i], max(a,b));
		else if(y < ((double)dy/(double)dx) * (double)(x-a.f) + (double)a.s)
		{
			// cout << ((double)dy/(double)dx) * (double)(x-a.f) + (double)a.s << endl;
			ct+=2;
		}
	}
	return ct;
}
void iterate() // precomputes # points below line
{
	FOR(i, n)
	{
		FOR(j, i)
		{
			if(pts[i].f == pts[j].f) continue;
			blw[i][j] = below_ln(pts[i], pts[j]);
			blw[j][i] = -blw[i][j]; // sign is useful for
			// top/bottom edge
		}
	}
}
void solve()
{
	cin >> n;
	FOR(i, n) cin >> pts[i].f >> pts[i].s;
	sort(pts, pts+n);
	// foreach edge find # pts below line
	iterate();
	// cerr << blw[4][3] << " " << blw[3][0] << " " << blw[0][4] << endl;
	// now loop through all triangles
	FOR(i, n) FOR(j, i) FOR(k, j)
	{
		int x = abs(blw[i][j] + blw[j][k] + blw[k][i])/2;
		pii a = pts[i], b = pts[j], c = pts[k];

		x -= (p_below_seg(a,b,c));
		x -= (p_below_seg(b,c,a));
		x -= (p_below_seg(c,a,b));
		// if(x == 2) cout << i << " " << j << " " << k << endl;
		ans[x]++;
	}
	FOR(i, n-2) cout << ans[i] << endl;
}

int main()
{
	fileio("triangles.in", "triangles.out");
	int t = 1;
	// cin >> t; // uncomment if it's multitest
	while(t--)
	{
		solve();
	}
	
}
