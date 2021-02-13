#include <bits/stdc++.h>

using namespace std;

int main()
{
	int t; cin >> t;
	while (t--)
	{
		int n, m; cin >> n >> m;
		string s; cin >> s;
		s = " " + s;
		s += " ";
		// prefix min/max
		vector<int> pmx(n+2), pmn(n+2), ps(n+2);
		for(int i = 1; i <= n; i++)
		{
			ps[i] = ps[i-1] + (s[i] == '+' ? 1 : -1);
			pmx[i] = max(pmx[i-1], ps[i-1] + (s[i] == '+' ? 1 : -1));
			pmn[i] = min(pmn[i-1], ps[i-1] + (s[i] == '+' ? 1 : -1));
		}
		vector<int> smx(n+2), smn(n+2);
		for(int i = n; i >= 1; i--)
		{
			smx[i] = max(0, smx[i+1]+(s[i] == '+' ? 1 : -1));
			smn[i] = min(0, smn[i+1]+(s[i] == '+' ? 1 : -1));
		}
		for(int i = 0; i < m; i++)
		{
			int l, r; cin >> l >> r; --l; ++r;
			int mn1 = pmn[l],       mx1 = pmx[l];
			int mn2 = ps[l]+smn[r], mx2 = ps[l]+smx[r];
			cout << (max(mx1, mx2) - min(mn1, mn2) + 1) << endl;
		}
	}
}