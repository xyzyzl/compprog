#include <bits/stdc++.h>

using namespace std;

const int MAXN = 505;

int n, k, dist[MAXN], par[MAXN];
int main()
{
	cin >> n >> k;
	memset(dist, 0x7f, sizeof dist);
	const int INF = dist[0];
	queue<int> q;
	dist[0] = 0;
	par[0] = -1;
	q.push(0);
	while(!q.empty())
	{
		int tp = q.front(); q.pop();
		// a l m o s t dp
		for(int i = 0; i <= k; i++)
		{
			if(i <= n-tp && k-i <= tp)
			{
				int x = tp + 2*i-k;
				if(dist[x] == INF)
				{
					dist[x] = dist[tp] + 1;
					par[x] = tp;
					q.push(x);
				}
			}
		}
	}
	if(dist[n] == INF)
	{
		cout << -1 << endl;
		return 0;
	}
	// now we need to output a list of all turns
	vector<int> p;
	int lst = n;
	while(lst != -1)
	{
		p.push_back(lst);
		lst = par[lst];
	}
	reverse(p.begin(), p.end());
	for(int x : p) cerr << x << ' ';
	cerr << endl;

	vector<int> on, off;
	for(int i = 1; i <= n; i++) off.push_back(i);
	int ans = 0;
	for(int i = 0; i < (int)p.size()-1; i++)
	{
		int dif = p[i+1]-p[i];
		int _on = (k+dif)/2;
		int _off = k-_on;
		vector<int> ton, toff;
		for(int j = 0; j < _on; j++)
		{
			ton.push_back(off.back());
			off.pop_back();
		}
		for(int j = 0; j < _off; j++)
		{
			toff.push_back(on.back());
			on.pop_back();
		}
		cout << "? ";
		for(int x : ton) cout << x << ' ';
		for(int x : toff) cout << x << ' ';
		cout << endl;
		cout.flush();
		for(int x : ton) on.push_back(x);
		for(int x : toff) off.push_back(x);
		int ret; cin >> ret;
		ans ^= ret;
	}
	cout << "! " << ans << endl;
	cout.flush();
}
