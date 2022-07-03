#include <bits/stdc++.h>

using namespace std;

int main()
{
	int n, h;
	cin >> n >> h;
	vector<pair<int, int> > v(n);
	for(int i = 0; i < n; i++)
	{
		int x, j; cin >> x >> j;
		v[i] = {x, j};
	}
	sort(v.begin(), v.end());
	int pre = 1;
	int mxd = 0;
	for(int i = 0; i < n; i++)
	{
		if(v[i].second > h)
		{
			mxd = max(mxd, v[i].first-pre-1);
			pre = v[i].first + 1;
		}
	}
	cout << max(v[n-1].first-pre, mxd) << endl;
}