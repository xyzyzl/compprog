#include <bits/stdc++.h>

using namespace std;

int n, q, par[200005][31];

int rec(int x, int k)
{
	for(int i = 0; i < 31; i++)
	{
		if(k & (1 << i))
			x = par[x][i];
	}
	return x;
}

int main()
{
	cin >> n >> q;
	for(int i = 1; i <= n; i++) { cin >> par[i][0]; }
	for(int j = 1; j < 31; j++) for(int i = 1; i <= n; i++)	{
		par[i][j] = par[par[i][j-1]][j-1];
	}
	while(q--)
	{
		int x, k; cin >> x >> k;
		cout << rec(x, k) << endl;
	}
}
