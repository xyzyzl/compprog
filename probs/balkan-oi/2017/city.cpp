#include <iostream>
#include <vector>
#include <algorithm>

#define MAXN 300005

using namespace std;
using ll = long long;

typedef pair<int, int> pii;
#define f first
#define s second

int N, A[MAXN];
ll K;
pii dp[MAXN];
vector<int> adj[MAXN];

void dfs(int v, int p)
{
	for (int x : adj[v])
	{
		if (x == p)
			continue;
		// cerr << v << " " << x << " " << p << endl;
		dfs(x, v);
		dp[v] = min(dp[v], min(make_pair(1 - A[x], x), make_pair(dp[x].f + 1, dp[x].s)));
	}
}

pii dp_p[MAXN];
int ans[MAXN][2];
void pdfs(int v, int p)
{
	dp[v] = min(dp[v], dp_p[v]);
	for (int w = 0; w < 2; w++)
	{
		pii tmp = {dp_p[v].f + 1, dp_p[v].s};
		tmp = min(tmp, {1 - A[v], v});
		for (int x : adj[v])
		{
			if (x == p)
				continue;
			dp_p[x] = min(dp_p[x], tmp);
			tmp = min(tmp, min(make_pair(dp[x].first + 2, dp[x].second), make_pair(2 - A[x], x)));
		}
		reverse(adj[v].begin(), adj[v].end());
	}
	for (int x : adj[v])
	{
		if (x != p)
			pdfs(x, v);
	}
}

signed main()
{
	cin >> N >> K;
	for (int i = 0; i < N; i++)
		cin >> A[i];
	for (int i = 1; i < N; i++)
	{
		int a, b;
		cin >> a >> b;
		--a;
		--b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	for (int i = 0; i < N; i++)
	{
		dp_p[i] = dp[i] = {1e9 + 7, -1};
	}
	dfs(0, -1);
	pdfs(0, -1);
	for (int i = 0; i < N; i++)
	{
		ans[i][0] = dp[i].s;
	}
	int pt = (K%2 ? ans[0][0] : 0);
	for (int i = 1; i <= 63; i++)
	{
		for (int j = 0; j < N; j++)
		{
			ans[j][i%2] = ans[ans[j][(i+1)%2]][(i+1)%2];
		}
		if(K & (1ll << i)) {
			pt = ans[pt][i%2];
		}
	}
	cout << 1+pt << endl;
}