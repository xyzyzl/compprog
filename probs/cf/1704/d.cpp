#include <bits/stdc++.h>

using namespace std;

int main()
{
	// freopen("d.in", "r", stdin);
	int t; cin >> t;
	while(t--)
	{
		int n, m; cin >> n >> m;
		vector<vector<long long>> c(n, vector<long long>(m));
		for(int i = 0; i < n; i++) for(int j = 0; j < m; j++)
		{	
			cin >> c[i][j];
		}
		map<long long, long long> fs;
		vector<long long> s(n);
		for(int i = 0; i < n; i++)
		{
			long long s0 = 0;
			for(int j = 0; j < m; j++)
			{
				s0 += c[i][j]*j;
			}
			s[i] = s0;
			// cerr << s0 << endl;
			fs[s0]++;
		}
		for(int i = 0; i < n; i++) 
		{
			if(fs[s[i]] == 1)
			{
				cout << i+1 << ' ' << (s[i] - s[(i+1)%n]) << endl;
			}
		}
	}
}