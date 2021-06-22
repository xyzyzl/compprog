#include <bits/stdc++.h>

using namespace std;

void solve()
{
	int n; cin >> n;
	vector<int> h(n);
	for(int i = 0; i < n; i++) cin >> h[i];
	sort(h.begin(), h.end());
	int id = 0, best = INT_MAX;
	for(int i = 1; i < n; i++) 
	{
		if(h[i]-h[i-1] < best)
		{
			best = h[i]-h[i-1];
			id = i;
		}
	}
	vector<int> r;
	r.push_back(h[id-1]);
	for(int i = id+1; i < n; i++) r.push_back(h[i]);
	for(int i = 0; i < id-1; i++) r.push_back(h[i]);
	r.push_back(h[id]);
	for(int x : r) cout << x << ' ';
	cout << endl;
}

int main()
{
	int t; cin >> t; while(t--) solve();
}