#include <bits/stdc++.h>

using namespace std;

void solve()
{
	string s, t; cin >> s >> t;
	int n = s.length();
	int m = t.length();

	int i = 0, j = 0;
	while(i < n && j < m)
	{
		if(s[i] == t[j])
		{
			i++; j++;
		} else 
		{
			j++;
		}
	}
	if(i != n)
	{
		cout << "IMPOSSIBLE" << endl;
	} else 
	{
		cout << m-n << endl;
	}
}

int main()
{
	int t; cin >> t;
	for(int i = 1; i <= t; i++)
	{
		cout << "Case #" << i << ": ";
		solve();
	}
}