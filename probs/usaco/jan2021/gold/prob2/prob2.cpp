#include <bits/stdc++.h>

using namespace std;

#define mp make_pair

int n, k, b[50005], wt[50005];
vector<pair<int, int> > adj[50005];
vector<int> col[55];
bool W[55][55];

void dijk(int src)
{
	memset(wt, 0x7f, sizeof wt);
	set<pair<int, int> > pq;
	pq.insert({0, src});
	wt[src] = 0;
	while(!pq.empty())
	{
		auto tp = *pq.begin();
		pq.erase(pq.begin());
		for(auto x : adj[tp.second])
		{
			int w = x.first, ind = x.second;
			if(wt[ind] > wt[tp.second] + w)
			{
				pq.erase(mp(wt[ind], ind));
				wt[ind] = wt[tp.second] + w;
				pq.insert(mp(wt[ind], ind));
			}
		}
	}
}

int main()
{
	cin >> n >> k;
	for(int i = 0; i < n; i++)
	{
		cin >> b[i];
		--b[i];
		col[b[i]].push_back(i);
	}
	for(int i = 0; i < k; i++)
	{
		sort(col[b[i]].begin(), col[b[i]].end());
	}
	for(int i = 0; i < k; i++) for(int j = 0; j < k; j++)
	{
		char c; cin >> c;
		W[i][j] = (c=='1');
	}
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < k; j++) if(W[b[i]][j])
		{
			adj[i].push_back(mp(abs(i-col[j][0]), col[j][0]));
			adj[i].push_back(mp(abs(i-col[j].back()), col[j].back()));
			if(lower_bound(col[j].begin(), col[j].end(), i) != col[j].begin())
			{
				int l = prev(lower_bound(col[j].begin(), col[j].end(), i))-col[j].begin();
				adj[i].push_back(mp(abs(i-col[j][l]), col[j][l]));
			}
			if(lower_bound(col[j].begin(), col[j].end(), i) != col[j].end())
			{
				int r = lower_bound(col[j].begin(), col[j].end(), i)-col[j].begin(); if(col[j][r] == i) r++;
				if(col[j][r] < n) adj[i].push_back(mp(abs(i-col[j][r]), col[j][r]));
			}
		}
		sort(adj[i].begin(), adj[i].end());
		auto l = unique(adj[i].begin(), adj[i].end());
		adj[i].resize(distance(adj[i].begin(), l));
	}
	dijk(0);
	if(wt[n-1] >= 1e9) cout << -1 << endl;
	else cout << wt[n-1] << endl;
}
