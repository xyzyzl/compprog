#include <bits/stdc++.h>

using namespace std;

int main()
{
	int n, k;
	cin >> n >> k;
	vector<int> m(n);
	for(int i = 0; i < n; i++) cin >> m[i];
	sort(m.begin(), m.end());
	vector<int> c(k);
	for(int i = 0; i < k; i++) cin >> c[i];
	int mxtc = 0;
	for(int i = 0; i < n; i++)
	{
		int x = ceil((double)(n-i)/(double)c[m[i]-1]);
		// cerr << n-i << " " << c[m[i]] << endl;
		mxtc = max(mxtc, x);
	}
	cout << mxtc << endl;
	vector<vector<int> > ans(mxtc);
	for(int i = 0; i < n; i++)
	{
		ans[i % mxtc].push_back(m[i]);
	}
	for(int i = 0; i < mxtc; i++)
	{
		cout << ans[i].size() << " ";
		for(int x : ans[i]) cout << x << " ";
		cout << endl;
	}
}
