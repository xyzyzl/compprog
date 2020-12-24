#include <bits/stdc++.h>

using namespace std;

int n, m, deg[505];
vector<int> adj[505];
char A[505];
int main()
{
	cin >> n >> m;
	for(int i = 0; i < m; i++)
	{
		int a, b; cin >> a >> b;
		--a; --b;
		deg[a]++; deg[b]++;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	for(int i = 0; i < n; i++)
	{
		if(deg[i] == n-1)
		{
			A[i] = 'b';
		}
	}
	int na = 0;
	for(int i = 0; i < n; i++)
	{
		if(deg[i] < n-1)
		{
			na++;
			A[i] = 'a';
			for(int x : adj[i]) 
			{
				if(A[x] != 'b')
				{
					A[x] = 'a';
					na++;
				}
			}
			break;
		}
	}
	int nc = 0;
	for(int i = 0; i < n; i++)
	{
		if(!A[i])
		{
			A[i] = 'c';
			nc++;
		}
	}
	int nb = n-na-nc;
	for(int i = 0; i < n; i++)
	{
		if(A[i] == 'a')
		{
			int nx = 0;
			for(int x : adj[i]) 
			{
				if(A[x] == 'c')
				{
					cout << "NO" << endl;
					return 0;
				}
				nx += (A[x] == 'a');
			}
			if(nx < na-1)
			{
				cout << "NO" << endl;
				return 0;
			}
		}
		if(A[i] == 'c')
		{
			int nx = 0;
			for(int x : adj[i]) 
			{
				nx += (A[x] == 'c');
			}
			if(nx < nc-1)
			{
				cout << "NO" << endl;
				return 0;
			}
		}
	}
	cout << "YES" << endl;
	for(int i = 0; i < n; i++) cout << A[i];
	cout << endl;
}