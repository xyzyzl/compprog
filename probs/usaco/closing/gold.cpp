#include <bits/stdc++.h> // :rage: :deciduous_tree:

#pragma GCC optimize("O3")

using namespace std;

#define MAXN 200005

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

class UnionFind
{
private:
	vector<int> p, rank;
public:
	UnionFind(int N)
	{
		rank.assign(N, 0);
		p.assign(N, 0);
		for (int i = 0; i < N; i++)
			p[i] = i;
	}
	int findSet(int i)
	{
		return (p[i] == i) ? i : (p[i] = findSet(p[i]));
	}
	bool isSameSet(int i, int j)
	{
		return findSet(i) == findSet(j);
	}
	void unionSet(int i, int j)
	{
		if (!isSameSet(i, j))
		{
			int x = findSet(i), y = findSet(j);
			if (rank[x] > rank[y])
				p[y] = x;
			else
			{
				p[x] = y;
				if (rank[x] == rank[y])
					rank[y]++;
			}
		}
	}
};

int n,m,ord[MAXN];
vi adj[MAXN];
bool open[MAXN], conn[MAXN];
int main()
{
    // 叶假金
    fileio("closing.in", "closing.out");
    DUEHOANG;
    int t = 1;
    // cin >> t;
    while(t--)
    {
        cin >> n >> m;
        FOR(i, m)
        {
            int x, y;
            cin >> x >> y;
            --x; --y;
            adj[x].pb(y);
            adj[y].pb(x);
        }
        FOR(i, n)
        {
            cin >> ord[n-i-1];
            ord[n-i-1]--;
        }
        UnionFind uf(n);
        int ns = 0;
        FOR(i, n)
        {
            ns++;
            open[ord[i]] = 1;
            for(int x : adj[ord[i]]) if(open[x])
            {
                if(uf.isSameSet(x, ord[i])) continue; 
                ns--;
                uf.unionSet(x, ord[i]);
            }
            if(ns <= 1) conn[n-i-1] = 1;
        }
        FOR(i, n) cout << (conn[i] ? "YES" : "NO") << endl;
    }
}