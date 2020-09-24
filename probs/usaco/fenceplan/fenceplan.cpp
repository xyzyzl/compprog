#include <bits/stdc++.h>

using namespace std;

int n, m, c=1, ar[100005], vs[100005];
long long X[100005], Y[100005], mnX[100005], mnY[100005], mxX[100005], mxY[100005];
vector<int> adj[100005];

void dfs(int v, int p)
{
	vs[v] = 1;
	ar[v] = c;
	for(int x : adj[v])
	{
		if(x==p || vs[x]) continue;
		dfs(x,v);
	}
}

int main()
{
	freopen("fenceplan.in", "r", stdin);
	freopen("fenceplan.out", "w", stdout);
	cin >> n >> m;
	for(int i = 0; i < n; i++) cin >> X[i] >> Y[i];
	for(int i = 0; i < m; i++)
	{
		int a, b;
		cin >> a >> b;
		--a; --b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	for(int i = 0; i < n; i++)
	{
		if(!ar[i])
		{
			dfs(i, -1);
			c++;
		}
	}
	for(int i = 0; i < c; i++) mnX[i] = mnY[i] = LLONG_MAX;
	for(int i = 0; i < n; i++)
	{
		mnX[ar[i]] = min(mnX[ar[i]], X[i]);
		mnY[ar[i]] = min(mnY[ar[i]], Y[i]);
		mxX[ar[i]] = max(mxX[ar[i]], X[i]);
		mxY[ar[i]] = max(mxY[ar[i]], Y[i]);
	}
	long long mA = LLONG_MAX;
	for(int i = 1; i < c; i++)
	{
		long long a = mxX[i] - mnX[i];
		long long b = mxY[i] - mnY[i];
		// cerr << a << " " << b << endl;
		mA = min(mA, 2*a+2*b);
	}
	cout << mA << endl;
}