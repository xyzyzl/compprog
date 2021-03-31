#include <bits/stdc++.h>

using namespace std;

void solve()
{
	int N; cin >> N;
	vector<int> a(N);
	vector<vector<int> > seg;
	vector<int> g(N+1);
	for(int i = 0; i < N; i++)
	{
		cin >> a[i];
		g[a[i]]++;
	}
	seg.push_back(vector<int>{a[0]});
	for(int i = 1; i < N; i++)
	{
		if(a[i] == a[i-1])
		{
			seg.push_back(vector<int>{a[i]});
		} else 
		{
			seg.back().push_back(a[i]);
		}
	}
	vector<int> f(N+1);
	for(vector<int> v : seg)
	{
		f[v[0]]++;
		f[v.back()]++;
	}
	int fmax = 0, gmax = 0;
	for(int i = 1; i <= N; i++)
	{
		fmax = max(fmax, f[i]);
		gmax = max(gmax, g[i]);
	}
	if(gmax > (N+1)/2) cout << -1 << endl;
	else cout << seg.size()-1+max(0, fmax-(int)seg.size()-1) << endl;
}

int main()
{
	int t; cin >> t;
	while(t--) solve();
}