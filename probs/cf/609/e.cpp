#include <bits/stdc++.h>

using namespace std;

const int MAXN = 200005;

int n, m, par[MAXN][20], wt[MAXN][20];
map<pair<int, int>, int> wei;
vector<int> adj[MAXN];

int tmp = 0, in[100005], ot[200005];

void dfs(int v, int p)
{
	in[v] = tmp;
	++tmp;
	par[v][0] = p;
	wt[v][0] = wei[{v,p}];
	for(int i = 1; i < 20; i++)
	{
		par[v][i] = par[par[v][i-1]][i-1];
		wt[v][i] = max(wt[par[v][i-1]][i-1], wt[v][i-1]);
	}
	for(int x : adj[v])
	{
		dfs(x,v);
	}
	ot[v] = tmp;
	++tmp;
}

bool anc(int u, int v)
{
	return (in[u] <= in[v] && ot[u] >= ot[v]);
}

// method finding all lca's
int lca(int u, int v)
{
	if(anc(u,v))
		return u;
	for(int i = 19; i >= 0; i--)
	{
		// as a verifier make sure par[u][i] >= 0 s.t. no array out of bounds
		if(par[u][i] >= 0 && !anc(par[u][i], v))
			u = par[u][i];
	}
	return par[u][0];
}

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

vector<pair<pair<int, int>, pair<int, int>> > eg;
int ans[MAXN];
int main()
{
	cin >> n >> m;
	for(int i = 0; i < m; i++)
	{
		int u, v, w; cin >> u >> v >> w;
		eg.push_back({{w, i}, {u, v}});
		--u; --v;
		wei[{u,v}] = w;
		wei[{v,u}] = w;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	sort(eg.begin(), eg.end());
	UnionFind uf(n);
	int cst = 0;
	vector<int> in_mst;
	for(int i = 0; i < m; i++)
	{
		pair<int, int> p = eg[i].second;
		if(!uf.isSameSet(p.first, p.second))
		{
			uf.unionSet(p.first, p.second);
			cst += eg[i].first.first;
			in_mst.push_back(eg[i].first.second);
		}
	}
	for(int x : in_mst)
	{
		ans[x] = cst;
	}
	cerr << "H" << endl;
	dfs(0, 0);
	for(int i = 0; i < n; i++)
	{
		cerr << wt[i][0] << endl;
	}
}
