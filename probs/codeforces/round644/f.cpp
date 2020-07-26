#include <bits/stdc++.h>

using namespace std;

void solve()
{
	int n, m;
	cin >> n >> m;
	vector<string> v(n);
	for(int i = 0; i < n; i++)
	{
		cin >> v[i];
	}
	string ret;
	for(int i = 0; i < m; i++)
	{
		for(char to = 'a'; to <= 'z'; to++)
		{
			string s = v[0];
			s[i] = to;
			bool bad = 0;
			for(int j = 0; j < n; j++)
			{
				int diff = 0;
				for(int k = 0; k < m; k++)
				{
					if(v[j][k] != s[k]) diff++;
				}
				if(diff > 1)
				{
					bad = 1;
					break;
				}
			}
			if(!bad)
			{
				cout << s << endl;
				return;
			}
		}
	}
	cout << -1 << endl;
}

int main()
{
	int T;
	cin >> T;
	while(T--)
	{
		solve();
	}
}
