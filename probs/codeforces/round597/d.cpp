:x


using namespace std;

#define MAXN 2005

#define f first
#define s second
int n;
long long adj[MAXN][MAXN];
long long k[MAXN];
pair<int, int> p[MAXN];
vector<int> ans_s;
vector<pair<int, int> > ans_w;

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

int main()
{
	vector<pair<long long, pair<int, int> > > edges;
	cin >> n;
	for(int i = 1; i <= n; i++)
	{
		cin >> p[i].f >> p[i].s;
	}
	for(int i = 1; i <= n; i++)
	{
		int c;
		cin >> c;
		adj[0][i] = c;
		adj[i][0] = c;
		edges.push_back(make_pair(c, make_pair(0, i)));
	}
	for(int i = 1; i <= n; i++)
	{
		cin >> k[i];
	}
	for(int i = 1; i <= n; i++)
	{
		for(int j = i+1; j <= n; j++)
		{
			adj[i][j] = adj[j][i] = (k[i] + k[j]) *
				(abs(p[i].f - p[j].f) + abs(p[i].s - p[j].s));
			edges.push_back(make_pair(adj[i][j], make_pair(i, j)));
		}
	}
	UnionFind uf(n+1);
	long long cost = 0;
	sort(edges.begin(), edges.end());
	for(int i = 0; i < edges.size(); i++)
	{
		pair<long long, pair<int, int> > x = edges[i];
		if(!uf.isSameSet(x.s.f, x.s.s))
		{
			if(x.s.f == 0) ans_s.push_back(x.s.s);
			else if(x.s.s == 0) ans_s.push_back(x.s.f);
			else
			{
				ans_w.push_back(make_pair(x.s.f, x.s.s));
			}
			cost += x.f;
			uf.unionSet(x.s.f, x.s.s);
		}
	}
	cout << cost << endl;
	cout << ans_s.size() << endl;
	for(int x : ans_s) cout << x << " ";
	cout << endl;
	cout << ans_w.size() << endl;
	for(pair<int, int> x : ans_w) cout << x.f << " " << x.s << endl;
}
