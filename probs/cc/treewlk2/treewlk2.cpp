#include <bits/stdc++.h>

#pragma GCC optimize("O3")

using namespace std;

int N, K, L, P[100005], Q[100005], Pp[200005], Qp[200005], dep[100005], par[100005][20];
vector<int> adj[100005];

int in[100005], ot[100005], tmp;
void dfs(int v, int p, int d)
{
	in[v]=tmp++;
	dep[v] = d;
	par[v][0] = p;
	for(int i = 1; i < 20; i++)
		par[v][i] = par[par[v][i-1]][i-1];
	for(int x : adj[v])
	{
		if(x != p) dfs(x, v, d+1);
	}
	ot[v]=tmp++;
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

int dist(int u, int v)
{
	int w = lca(u,v);
	return dep[u]-dep[w]+dep[v]-dep[w];
}

// move k should take O(lg k)
int nk(int u, int k)
{
	int ct = 0;
	while(k)
	{
		if(k%2) u = par[u][ct];
		ct++;
		k /= 2;
	}
	return u;
}

int go(int u, int v, int k)
{
	int w = lca(u, v);
	if(dep[u]-dep[w] >= k)
		return nk(u, k);
	else 
	{
		k -= dep[u]-dep[w];
		return nk(v, dep[v]-dep[w] - k);
	}
}

int get(int u, int v, int w)
{
	int ww = lca(u,v);
	if(nk(w, dep[w]-dep[ww]) == ww)
	{
		// ww is a parent of w
		int g = lca(u, w);
		if(g == ww)
		{
			return lca(v, w);
		} else 
		{
			return g;
		}
	}
	return ww;
}

bool on_path(int u, int v, int w)
{
	return dist(u, v) == dist(u, w) + dist(w, v);
}

void solve()
{
	memset(par, -1, sizeof par);
	memset(Pp, 0, sizeof Pp);
	memset(Qp, 0, sizeof Qp);
	cin >> N >> K >> L;
	for(int i = 1; i < N; i++) 
	{
		int a, b; cin >> a >> b; --a; --b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	for(int i = 0; i < K; i++)
	{
		cin >> P[i];
		--P[i];
	}
	for(int i = 0; i < L; i++)
	{
		cin >> Q[i];
		--Q[i];
	}
	dfs(0, -1, 1);
	int ia = 0, ib = 0;
	int m = 0;
	Pp[m] = P[m];
	Qp[m] = Q[m];
	// finding equal-length segments for each path. this way we can determine when
	// each point is reached by looking at the shortest paths
	// O(min(K, L) * log(N))
	while(ia < K && ib < L)
	{
		int da = dist(Pp[m], P[ia]);
		int db = dist(Qp[m], Q[ib]);
		++m;
		if(da == db)
		{
			Pp[m] = P[ia++];
			Qp[m] = Q[ib++];
		} else if(da < db)
		{
			Pp[m] = P[ia++];
			Qp[m] = go(Qp[m-1], Q[ib], da);
		} else 
		{
			Pp[m] = go(Pp[m-1], P[ia], db);
			Qp[m] = Q[ib++];
		}
	}

	// find the number of intersections for each segment
	// should be O((m-1) * log(N))
	long long ans = 0;
	for(int i = 0; i < m-1; i++)
	{
		int s = get(Pp[i], Pp[i+1], Qp[i]);
		int t = get(Pp[i], Pp[i+1], Qp[i+1]);
		if(!on_path(Qp[i], Qp[i+1], s)) continue;
		if(!on_path(Qp[i], Qp[i+1], t)) continue;
		if(dist(Pp[i],s) <= dist(Pp[i],t))
		{
			if(dist(Pp[i],s) != dist(Qp[i],s)) continue;
			ans += dist(s,t)+1;
		} else 
		{
			int d1 = dist(Qp[i],s);
			int d2 = dist(Pp[i],s);
			int d3 = dist(Qp[i],t);
			int d4 = dist(Pp[i],t);
			if(d1>d2) continue;
			if(d3<d4) continue;
			if(abs(d1-d2)%2==0) ans++;
		}
	}
	// remove any double-counted joints.
	for(int i = 1; i < m-1; i++) if(Pp[i] == Qp[i]) ans--;
	cout << ans << endl;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);
	int t; cin >> t;
	while(t--) solve();
}
