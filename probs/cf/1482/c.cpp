#include <bits/stdc++.h>

using namespace std;

void solve()
{
	int n, m;
	cin >> n >> m;
	vector<vector<int> > f(m+5);
	vector<vector<int> > d(n+5);
	for(int i = 0; i < m; i++)
	{
		int k; cin >> k;
		for(int j = 0; j < k; j++)
		{
			int q; cin >> q;
			f[i].push_back(q);
			d[q].push_back(i);
		}
	}
	vector<int> C(n+5);
	vector<int> used(m+5);
	for(int i = 0; i < m; i++) 
	{
		C[f[i][0]]++;
		used[i] = f[i][0];
	}
	int g = -1;
	for(int i = 1; i <= n; i++)
	{
		if(C[i] > (m+1)/2)
		{
			g = i;
			break;
		}
	}
	if(~g)
	{
		for(int i = 0; i < m && C[g] > (m+1)/2; i++) if(used[i] == g)
		{
			for(auto h : f[i])
			{
				if(C[h] < (m+1)/2)
				{
					used[i] = h;
					C[g]--;
					C[h]++;
					break;
				}
			}
		}
		if(C[g] > (m+1)/2)
		{
			cout << "NO" << endl;
		} else 
		{
			cout << "YES" << endl;
			for(int i = 0; i < m; i++) cout << used[i] << " ";
			cout << endl;
		}
	} else 
	{
		cout << "YES" << endl;
		for(int i = 0; i < m; i++) cout << used[i] << " ";
		cout << endl;
	}
}

int main()
{
	int t; cin >> t;
	while(t--) solve();
}
