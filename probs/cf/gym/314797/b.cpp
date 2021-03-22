#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1000005;
int n, r, c, l[MAXN], par[MAXN][22];
string a[MAXN];
int main()
{
	cin >> n >> r >> c;
	for(int i = 1; i <= n; i++)
	{
		cin >> a[i];
		l[i] = a[i].length()+1;
	}
	int j = 0, sm = l[0];
	for(int i = 1; i <= n; i++)
	{
		while(j <= n && sm <= 1+c)
		{
			j++;
			if(j <= n) sm += l[j];
		}
		par[i][0] = j;
		sm -= l[i];
	}
	for(int j = 1; j <= log2(n); j++)
	{
		for(int i = 1; i <= n; i++)
		{
			par[i][j] = par[par[i][j-1]][j-1];
		}
	}
	int sta = 1, len = 0;
	for(int i = 1; i <= n; i++)
	{
		int k = i;
		for(int j = 0; j <= log2(r); j++)
		{
			if((1 << j) & r) k = par[k][j];
		}
		if(len < k-i) 
		{
			len = k-i;
			sta = i;
		}
	}
	int cur = sta, nxt = par[sta][0];
	for(int i = 0; i < r; i++)
	{
		if(cur == nxt)
		{
			break;
		}
		// cerr << cur << " " << nxt << endl;
		int j;
		for(j = cur; j < nxt-1; j++)
		{
			cout << a[j] << " ";
		}
		cout << a[j];
		cout << endl;
		cur = par[cur][0];
		nxt = par[nxt][0];
	}
}
