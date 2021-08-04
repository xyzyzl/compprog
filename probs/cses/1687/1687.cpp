#include <bits/stdc++.h>

using namespace std;

const int MAXN = 200005;

int n, q;
int par[MAXN][21];
int main()
{
	cin >> n >> q;
	for(int i = 2; i <= n; i++)
	{
		cin >> par[i][0];
	}
	for(int j = 1; j < 20; j++) 
	{
		for(int i = 1; i <= n; i++)
		{
			par[i][j] = par[par[i][j-1]][j-1];
		}
	}
	while(q--)
	{
		int x, k; cin >> x >> k;
		int w = x;
		for(int j = 0; j < 20; j++) 
			if(k & (1 << j)) 
				w = par[w][j];
		cout << (w ? w : -1) << endl;
	}
}
