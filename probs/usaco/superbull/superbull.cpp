#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
#define pb push_back
#define int long long

int n, mat[2005][2005], vis[2005], wt[2005];
vi a;

void prim()
{
	for(int i = 0; i < n; i++)
	{
		wt[i] = 1; 
		vis[i] = 0;
	}
	wt[0] = 0;
	// make n-1 edges
	for(int ct = 0; ct < n-1; ct++)
	{
		// for all vertices
		int mn = 1, v = -1;
		for(int i = 0; i < n; i++)
		{
			if(!vis[i] && wt[i] < mn)
			{
				v = i;
				mn = wt[i];
			}
		}
		// should be sped up with a priority queue
		// for all children
		vis[v] = 1;
		for(int x = 0; x < n; x++)
		{
			if(!vis[x] && mat[v][x] < wt[x])
			{
				wt[x] = mat[v][x];
			}
		}
	}
	int ans = 0;
	for(int i = 1; i < n; i++)
	{
		ans -= wt[i];
	}
	cout << ans << endl;
}

signed main()
{
	freopen("superbull.in", "r", stdin);
	freopen("superbull.out", "w", stdout);
	cin >> n;
	for(int i = 0; i < n; i++)
	{
		int x; cin >> x; a.pb(x);
	}
	for(int i = 0; i < n; i++) for(int j = 0; j < n; j++)
	{
		mat[i][j] = -(a[i]^a[j]);
	}
	// do prim
	prim();
}