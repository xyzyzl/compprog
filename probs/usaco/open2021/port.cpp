#include <bits/stdc++.h>

using namespace std;

const int MAXN = 400005;

int N, cost[MAXN];
int vis[MAXN];
vector<int> P[MAXN/2];
vector<pair<int, int> > adj[MAXN];

void dfs(int v, int p, int c)
{
	if(vis[v]) return;
	vis[v] = c;
	for(auto x : adj[v])
	{
		if(x.second==p) continue;
		dfs(x.second, v, c);
	}
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

int main()
{
	cin >> N;
	for(int i = 0; i < N; i++)
	{
		cin >> cost[i];
		int p1, p2, p3, p4;
		p1 = 4*i, p2 = 4*i+1, p3 = 4*i+2, p4 = 4*i+3;
		adj[p1].push_back({0, p2});
		adj[p2].push_back({0, p1});
		adj[p3].push_back({0, p4});
		adj[p4].push_back({0, p3});
		cin >> p1 >> p2 >> p3 >> p4;
		--p1; --p2; --p3; --p4;
		P[p1].push_back(4*i+0);
		P[p2].push_back(4*i+1);
		P[p3].push_back(4*i+2);
		P[p4].push_back(4*i+3);
	}
	for(int i = 0; i < 2*N; i++)
	{
		adj[P[i][0]].push_back({0, P[i][1]});
		adj[P[i][1]].push_back({0, P[i][0]});
	}
	int col = 0;
	for(int i = 0; i < 4*N; i++)
	{
		if(!vis[i])
		{
			dfs(i, -1, ++col);
		}
	}
	vector<pair<int, pair<int, int> > > eg;
	for(int i = 0; i < N; i++)
	{
		if(vis[4*i] == vis[4*i+2]) continue;
		eg.push_back({cost[i], {vis[4*i]-1, vis[4*i+2]-1}});
	}
	int E = eg.size();
	if(E == 0)
	{
		cout << 0 << endl;
		return 0;
	}
	sort(eg.begin(), eg.end());
	UnionFind uf(N);
	int cst = 0;
	for(int i = 0; i < E; i++)
	{
		pair<int, pair<int, int> > fr = eg[i];
		if(!uf.isSameSet(fr.second.first, fr.second.second))
		{
			cst += fr.first;
			uf.unionSet(fr.second.first, fr.second.second);
		}
	}
	cout << cst << endl;
}