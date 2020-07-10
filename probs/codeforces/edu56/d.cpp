#include <bits/stdc++.h>
 
using namespace std;
 
int n, m;
vector<int> adj[300005];
int dist[300005];
bool vis[300005];
vector<pair<int, int> > edges;
 
#define ll long long
#define MOD 998244353
namespace modOp
{
    int ad(int a, int b, int mod = MOD) { return (a+b)%mod; }
    int sub(int a, int b, int mod = MOD) { return (a-b+mod)%mod; }
    int mul(int a, int b, int mod = MOD) { return (ll)a*b%mod; }
 
    int AD(int& a, int b, int mod = MOD) { return a = ad(a,b,mod); }
    int SUB(int& a, int b, int mod = MOD) { return a = sub(a,b,mod); }
    int MUL(int& a, int b, int mod = MOD) { return a = mul(a,b,mod); }
 
    int po (int b, int p, int mod = MOD) { return !p?1:mul(po(mul(b,b,mod),p/2,mod),p&1?b:1,mod); }
    int inv (int b, int mod = MOD) { return po(b,mod-2,mod); }
 
    int invGeneral(int a, int b) { // 0 < a < b, gcd(a,b) = 1
        if (a == 0) return b == 1 ? 0 : -1;
        int x = invGeneral(b%a,a);
        return x == -1 ? -1 : ((1-(ll)b*x)/a+b)%b;
    }
}
 
using namespace modOp;
 
int passes = 0;
vector<int> cc[300005];
void bfs(int src)
{
	queue<int> q;
	q.push(src);
	dist[src] = 0;
	while(!q.empty())
	{
		int f = q.front();
		q.pop();
		if(vis[f]) continue;
		cc[passes].push_back(f);
		vis[f] = 1;
		for(int x : adj[f])
		{
			if(vis[x]) continue;
			dist[x] = dist[f] + 1;
			q.push(x);
		}
	}
	++passes;
}
 
int main()
{
	int T;
	cin >> T;
	while(T--)
	{
		passes = 0;
		edges.clear();
		cin >> n >> m;
		for(int i = 0; i < n; i++) adj[i].clear();
		for(int i = 0; i < n; i++) cc [i].clear();
		for(int i = 0; i < n; i++) vis [i] = 0;
		for(int i = 0; i < n; i++) dist[i] = 0;
		for(int i = 0; i < m; i++)
		{
			int a, b;
			cin >> a >> b;
			--a; --b;
			adj[a].push_back(b);
			adj[b].push_back(a);
			edges.push_back({a, b});
		}
		for(int i = 0; i < n; i++)
		{
			if(!vis[i]) bfs(i);
		}
		bool cannot = 0;
		for(int i = 0; i < m; i++)
		{
			int u = edges[i].first;
			int v = edges[i].second;
			if(dist[u] % 2 == dist[v] % 2)
				cannot = 1;
		}
		if(cannot)
		{
			cout << 0 << endl;
			continue;
		}
		int ans = 1;
		for(int k = 0; k < passes; k++)
		{
			int num_ev = 0;
			for(int i : cc[k])
			{
				if(dist[i] % 2 == 0) num_ev++;
			}
			MUL(ans,ad(po(2, num_ev), po(2, cc[k].size()-num_ev)));
		}
		cout << ans << endl;
	}
}
