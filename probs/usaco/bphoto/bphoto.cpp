#include <bits/stdc++.h>

using namespace std;

int n, h[100005], sh[100005], g[100005], bit[200005], tal[100005][2];
map<int, int> mp;

void upd(int k)
{
	while(k <= n+5)
	{
		bit[k]++;
		k += (k&-k);
	}
}

int sum(int k)
{
	int ret = 0;
	while(k > 0)
	{
		ret += bit[k];
		k -= (k&-k);
	}
	return ret;
}

int main()
{
	freopen("bphoto.in", "r", stdin);
	freopen("bphoto.out", "w", stdout);
	cin >> n;
	for(int i = 1; i <= n; i++)
	{
		cin >> h[i];
		sh[i] = h[i];
	}
	sort(sh+1,sh+n+1);
	for(int i = 1; i <= n; i++) 
	{
		if(!mp[sh[i]]) mp[sh[i]] = i;
	}
	for(int i = 1; i <= n; i++)
	{
		g[i] = mp[h[i]];
		cerr << g[i] << endl;
	}
	for(int i = 1; i <= n; i++)
	{
		upd(g[i]);
		tal[i][0] = i-sum(g[i]);
	}
	memset(bit, 0, sizeof bit);
	for(int i = n; i > 0; i--)
	{
		upd(g[i]);
		tal[i][1] = (n-i+1)-sum(g[i]);
	}
	int ans = 0;
	for(int i = 1; i <= n; i++)
	{
		if(tal[i][0] > 2*tal[i][1] || tal[i][1] > 2 * tal[i][0])
		{
			ans++;
		}
	}
	cout << ans << endl;
}