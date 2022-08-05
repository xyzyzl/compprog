#include <bits/stdc++.h>

using namespace std;

int main()
{
	int t; cin >> t;
	while(t--)
	{
		int n; cin >> n;
		pair<int, int> T; cin >> T.first >> T.second;
		vector<pair<int, int>> g(n);
		for(int i = 0; i < n; i++) 
		{
			cin >> g[i].first >> g[i].second;
		}
		sort(g.begin(), g.end());
		int dif=0;
		if(lower_bound(g.begin(), g.end(), T) == g.end())
		{
			dif = g[0].first*60+g[0].second - (T.first*60+T.second) + 1440;
		} else 
		{
			pair<int, int> U = *lower_bound(g.begin(), g.end(), T);
			dif = U.first*60+U.second - (T.first*60+T.second);
		}
		cout << (dif/60) << " " << (dif%60) << endl;
	}
}