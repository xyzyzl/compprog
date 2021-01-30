// R = 1, B = 0 in the 2-SAT part of the problem
#include <bits/stdc++.h>

using namespace std;

int n, m, num_scc;
vector<int> adj[100005];

int tmw = 0;
int ind[100005], low[100005], head[100005]; // index, lowest visitable vertex
bool stc[100005];							// is this in the recursion stack
stack<int> rec;								// the recursion stack

void tarjan(int x)
{
	ind[x] = low[x] = ++tmw;
	rec.push(x);
	stc[x] = 1;
	for (int y : adj[x])
	{
		if (ind[y] == -1) // not visited
		{
			tarjan(y);
			low[x] = min(low[x], low[y]);
		}
		else if (stc[y])
			low[x] = min(low[x], ind[y]);
	}

	if (ind[x] == low[x])
	{
		// this is certain to be a head
		++num_scc;
		int k = -1;
		do
		{
			k = rec.top();
			rec.pop();
			stc[k] = 0;
			head[k] = num_scc;
		} while (x != k);
	}
}

const long long INF = 1e16 + 7; // must be long long for safety
long long mn[100005];			// minimum cost for this scc group
long long ways[100005];			// # ways
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);
	fill(ways, ways + 100005, 1);
	fill(mn, mn + 100005, INF);
	cin >> n >> m;
	for (int i = 0; i < m; i++)
	{
		int a1, a2, a3;
		bool b1, b2, b3;
		char c1, c2, c3;
		cin >> a1 >> c1 >> a2 >> c2 >> a3 >> c3;
		--a1; --a2; --a3;
		b1 = c1 == 'R';
		b2 = c2 == 'R';
		b3 = c3 == 'R';
	}
	memset(ind, -1, sizeof(ind));
	for (int i = 0; i < n; i++)
		if (ind[i] == -1)
		{
			tarjan(i);
		}
}
