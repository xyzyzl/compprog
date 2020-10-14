#include <bits/stdc++.h>

using namespace std;

int n, m, num_scc, is_pub[100005];
vector<int> adj[100005], adj2[100005];

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

vector<int> res;
int a[100005], indeg[100005], S, P, vis[100005];
bool topo(int X)
{
	// no need to reset the adjacency list and things
	multiset<int> st;
	for(int i = 1; i <= num_scc; i++)
	{
		if(!indeg[i])
		{
			st.insert(i);
			// cout << i << endl;
		}
	}
	for(int i = 1; i <= num_scc; i++)
	{
		int u = *st.begin();
		if(st.empty()) return 0;
		st.erase(st.begin());
		res.push_back(u);

		for(int v : adj2[u])
		{
			indeg[v]--;
			if(indeg[v] == 0) st.insert(v);
		}
	}
	return 1;
}

const long long INF = 1e16 + 7; // must be long long for safety
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
		int a, b;
		cin >> a >> b;
		--a;
		--b;
		adj[a].push_back(b);
	}
	memset(ind, -1, sizeof(ind));
	for (int i = 0; i < n; i++)
		if (ind[i] == -1)
		{
			tarjan(i);
		}
	vector<int> val(n);
	for(int i = 0; i < n; i++)
	{
		cin >> val[i];
	}
	cin >> S >> P;
	for(int i = 0; i < n; i++)
	{
		a[head[i]] += val[i];
		for(int x : adj[i])
		{
			if(head[x] != head[i])
			{
				adj2[head[i]].push_back(head[x]);
				indeg[head[x]]++;
			}
		}
	}
	for(int i = 0; i < P; i++)
	{
		int k; cin >> k;
		is_pub[--k]=1;
	}
	topo();
}
