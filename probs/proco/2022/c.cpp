#include <bits/stdc++.h>

using namespace std;

int main()
{
	int n, p; cin >> n >> p;
	vector<pair<double, int> > v(n);
	for(int i = 0; i < n; i++)
	{
		int t; cin >> t;
		v[i] = {(double)t/p, i};
	}
	sort(v.begin(), v.end());
	for(int i = 0; i < n; i++)
	{
		if(v[i].first < i+1)
		{
			cout << "FAILED!" << endl;
			return 0;
		}
	}
	cout << "SUCCESSFUL!" << endl;
	for(int i = 0; i < n; i++)
	{
		cout << v[i].second+1 << endl;
	}
}