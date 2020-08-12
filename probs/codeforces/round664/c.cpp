#include <bits/stdc++.h>

using namespace std;

int main()
{
	int n, m;
	cin >> n >> m;
	vector<int> a(n);
	vector<int> b(m);
	for(int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	for(int j = 0; j < m; j++)
	{
		cin >> b[j];
	}
	/*
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < m; j++)
		{
			cout << (a[i]&b[j]) << ' ';
		}
		cout << endl;
	}
	*/
	sort(a.begin(), a.end());
	reverse(a.begin(), a.end());
	sort(b.begin(), b.end());
	int ans = 0;
	for(int i = 0; i < n; i++)
	{
		int mn = 555;
		for(int j = 0; j < m; j++)
		{
			int x = a[i]&b[j];
			for(int k = 0; k < 9; k++)
			{
				if(ans & (1 << k))
				{
					if(x & (1 << k)) x -= (1 << k);
				}
			}
			mn = min(mn, x);
		}
		ans |= mn;
	}
	cout << ans << endl;
}
