#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef pair<int, int> pii;
#define f first
#define s second

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

int V, E;
int main()
{
	vector<pair<int, pii> > edges;
	cin >> V;
	// int adj_mat[V][V];
	for(int i = 0; i < V; i++)
	{
		for(int j = 0; j < V; j++)
		{
			int s;
			cin >> s;
			edges.push_back(make_pair(s, make_pair(i, j)));
		}
	}
	E = edges.size();
	sort(edges.begin(), edges.end());

	UnionFind uf(V);
	int cost = 0;
	for(int i = 0; i < E; i++)
	{
		pair<int, pii> fr = edges[i];
		if(!uf.isSameSet(fr.s.f, fr.s.s))
		{
			cost += fr.f;
			uf.unionSet(fr.s.f, fr.s.s);
		}
	}
	cout << cost << endl;
}
