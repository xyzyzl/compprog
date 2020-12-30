#include <bits/stdc++.h>

using namespace std;

#define FOR(i, n) for(int i = 0; i < n; i++)

int n, m, gd[105], dp[105][105][105];
vector<int> vd, nvd; // any positions on a row s.t. no two artilleries attack each other
int main()
{
	cin >> n >> m; 
	for(int i = 0; i < (1 << m); i++)
	{
		if(i & 2*i || i & 4*i) continue;
		vd.push_back(i);
		nvd.push_back(__builtin_popcount(i));
		// cerr << i << " ";
	}
	cerr << endl;
	int sz = (int)vd.size();
	for(int i = 0; i < n; i++) for(int j = 0; j < m; j++)
	{
		char c; cin >> c;
		gd[i] += (c == 'H');
		gd[i] *= 2;
	}
	for(int i = 0; i < n; i++) gd[i] /= 2;
	if(n > 1) FOR(j1, sz) 
	{
		int m1 = vd[j1];
		if(m1 & gd[1]) continue;
		FOR(j2, sz)
		{
			int m2 = vd[j2];
			if(m2 & gd[0]) continue;
			if(m1 & m2) continue;
			dp[1][j1][j2] = nvd[j1] + nvd[j2];
		}
	} else
	{
		int ans = 0;
		FOR(j1, sz)
		{
			int m1 = vd[j1];
			if(gd[0] & m1) continue;
			ans = max(ans, nvd[j1]);
		}
		cout << ans << endl;
		return 0;
	}
	
	for(int i = 2; i < n; i++)
	{
		FOR(j1, sz)
		{
			int m1 = vd[j1];
			if(m1 & gd[i]) continue;
			FOR(j2, sz)
			{
				int m2 = vd[j2];
				if(m2 & gd[i-1]) continue;
				if(m2 & m1) continue;
				FOR(j3, sz)
				{
					int m3 = vd[j3];
					if(m3 & gd[i-2]) continue;
					if(m3 & m2) continue;
					if(m3 & m1) continue;
					// cerr << m1 << " " << m2 << " " << m3 << endl;
					dp[i][j1][j2] = max(dp[i][j1][j2], nvd[j1] + dp[i-1][j2][j3]);
				}
			}
		}
	}
	int ans = 0;
	FOR(j1, sz) FOR(j2, sz)
	{
		ans = max(ans, dp[n-1][j1][j2]);
	}
	cout << ans << endl;
}