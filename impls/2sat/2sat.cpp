#include <bits/stdc++.h>

using namespace std;

int n, m, num_scc, indeg[2000005];
vector<int> adj[2000005], adj2[2000005];

int tmw = 0;
int ind[2000005], low[2000005], head[2000005]; // index, lowest visitable vertex
bool stc[2000005];							// is this in the recursion stack
stack<int> rec;								// the recursion stack

void tarjan(int x)
{
	ind[x] = low[x] = ++tmw;
	cerr << x << endl;
	rec.push(x);
	stc[x] = 1;
	for (int y : adj[x])
	{
		cerr << y << " A" << endl;
		if (ind[y] == -1) // not visited
		{
			tarjan(y);
			low[x] = min(low[x], low[y]);
		}
		else if (stc[y]) // has been visited but is a backedge
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

vector<int> res;
bool topo()
{
	// no need to reset the adjacency list and things
	multiset<int> st;
	for(int i = 0; i < 2*n; i++)
	{
		if(!indeg[i])
		{
			st.insert(i);
			// cout << i << endl;
		}
	}
	for(int i = 0; i < 2*n; i++)
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
		// cout << u << endl;
	}
	return 1;
}

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
		int u, a, v, b; cin >> u >> a >> v >> b; --u; --v;
		// we want u=a or v=b
		int x = (a ? u : u+n); // one of x or y is 1
		int x0 = (a ? u+n : u);
		int y = (b ? v : v+n);
		int y0 = (b ? v+n : v);
		adj[x0].push_back(y);
		adj[y0].push_back(x);
	}
	memset(ind, -1, sizeof(ind));
	for (int i = 0; i < 2*n; i++)
		if (ind[i] == -1)
		{
			tarjan(i);
		}
	for (int i = 0; i < n; i++)
	{
		if(head[i] == head[i+n])
		{
			cout << "IMPOSSIBLE" << endl;
			return 0;
		}
	}
	cout << "POSSIBLE" << endl;
	for(int i = 0; i < n; i++)
	{
		for(int x : adj[i])
		{
			if(head[i] == head[x]) continue;
			adj2[head[i]].push_back(head[x]);
			indeg[head[x]]++;
		}
	}
	topo();
	map<int, int> I;
	for(int i = 0; i < 2*n; i++)
	{
		I[res[i]] = i;
	}
	vector<int> ans(n);
	for(int i = 0; i < n; i++)
	{
		if(I[i+n]<I[i]) ans[i] = 1;
		else ans[i] = 0;
	}
	for(int i = 0; i < n; i++)
	{
		cout << ans[i] << " ";
	}
	cout << endl;
}
