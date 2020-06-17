// Finally AC!!!!
// Algorithms: BFS
// Think of each mirror as an added weight. At each step, we find all of the acc-
// -essible fence posts and run a BFS to find the minimal distance to an end-post
// or identify its nonexsistence
// Things to watch out for: only needed to update each value once -- this is also
// an issue that i have run into during real USACO competitions, and I think that
// i should address it.

#include <bits/stdc++.h>

#pragma GCC optimize("O3")

using namespace std;

#define MAXN 100005

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

struct pairhash {
public:
  template <typename T, typename U>
  std::size_t operator()(const std::pair<T, U> &x) const
  {
    return std::hash<T>()(x.first) ^ std::hash<U>()(x.second);
  }
};

int n, lx, ly, tx, ty;
pii mir[MAXN];
unordered_map<int, vi> horz, vert;
unordered_map<pii, int, pairhash> dist;
void read()
{
	cin >> n >> lx >> ly >> tx >> ty;
	FOR(i, n)
	{
		cin >> mir[i].f >> mir[i].s;
		vert[mir[i].f].pb(mir[i].s);
		horz[mir[i].s].pb(mir[i].f);
	}
}

void solve()
{
	queue<pii> q; // each pii defines a line - its x coordinate (if vertical) / y coordinate (if vertical)
	// and its state (horizontal or vertical).
	q.push(mp(lx, 0)); // can use both
	q.push(mp(ly, 1)); // horizontal / vertical lines
	dist[mp(lx, 0)] = 0; // you originally only need 0 mirrors
	dist[mp(ly, 0)] = 0; // you originally only need 0 mirrors
	int ans = -1;
	while(!q.empty())
	{
		pii tp = q.front();
		q.pop();
		if(tp.s && tp.f == ty)
		{
			// horizontal
			ans = dist[tp];
			break;
		} else if(!tp.s && tp.f == tx)
		{
			// vertical
			ans = dist[tp];
			break;
		}
		// if not a return case:
		if(tp.s)
		{
			// is horizontal
			for(int x : horz[tp.f])
			{
				pii nx = mp(x, !tp.s);
				if(dist[nx] == 0)
				{
					dist[nx] = dist[tp] + 1;
					q.push(nx);
				}
			}
		} else
		{
			// is vertical
			for(int x : vert[tp.f])
			{
				pii nx = mp(x, !tp.s);
				if(dist[nx] == 0)
				{
					dist[nx] = dist[tp] + 1;
					q.push(nx);
				}
			}
		}
	}
	cout << ans << endl;
}

int main()
{
	fileio("lasers.in", "lasers.out");
	DUEHOANG;
	int t = 1;
	// cin >> t; // uncomment if it's multitest
	while(t--)
	{
		read();
		solve();
	}

}
