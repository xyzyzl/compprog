#include <bits/stdc++.h>

using namespace std;

int main()
{
	int t;
	cin >> t;
	while(t--)
	{
		int n,m;
		cin >> n >> m;
		vector<vector<int> > v(m+n, vector<int>(2, 0));
		for(int i = 0; i < n; i++)
		{
			for(int j = 0; j < m; j++)
			{
				int k;
				cin >> k;
				v[i+j][k]++;
			}
		}
		int ans = 0;
		for(int i = 0; i < (n+m)/2; i++)
		{
			// cerr << i << " " << n+m-i-2 << endl;
			if(n+m-i-2 == i) break;
			int z = v[i][0] + v[n+m-i-2][0];
			int o = v[i][1] + v[n+m-i-2][1];
			ans += min(z,o);
		}
		cout << ans << endl;
	}
}
