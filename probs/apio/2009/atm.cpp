#include <bits/stdc++.h>

using namespace std;

int n, m, num_scc;
vector<vector<int> > adj, adj2;

int tmw = 0;
int ind[500005], low[500005], head[500005]; // index, lowest visitable vertex
bool stc[500005];							// is this in the recursion stack
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
			head[k] = num_scc-1;
		} while (x != k);
	}
}

vector<int> res, a, indeg;
vector<bool> is_pub;
int S, P;
bool topo()
{
	// no need to reset the adjacency list and things
	multiset<int> st;
	for(int i = 0; i < num_scc; i++)
	{
		if(!indeg[i])
		{
			st.insert(i);
			// cout << i << endl;
		}
	}
	for(int i = 0; i < num_scc; i++)
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
	st.clear();
	return 1;
}

const long long INF = 1e9 + 7; // must be long long for safety
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n >> m;
	adj.resize(n);
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
	adj2.resize(num_scc);
	is_pub.resize(num_scc);
	a.resize(num_scc);
	indeg.resize(num_scc);
	for(int i = 0; i < n; i++)
	{
		int val; cin >> val;
		a[head[i]] += val;
	}
	cin >> S >> P;
	--S;
	for(int i = 0; i < n; i++)
	{
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
		is_pub[head[--k]] =1;
	}
	topo();
	vector<int> ans(num_scc);
	for(int i = 0; i < num_scc; i++)
		ans[i] = -INF;
	ans[head[S]]=a[head[S]];
	for(int x : res)
	{
		if(ans[x] == -INF) continue;
		for(int y : adj2[x])
		{
			ans[y] = max(ans[y], ans[x]+a[y]);
		}
	}
	int mx = 0;
	for(int i = 0; i < num_scc; i++) 
	{
		if(is_pub[i]) mx = max(mx, ans[i]);
	}
	cout << mx << endl;
}
