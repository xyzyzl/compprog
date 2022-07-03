#include <bits/stdc++.h>

using namespace std;

void solve()
{
	int r, c; cin >> r >> c;
	vector<vector<char> > v(r, vector<char>(c));
	for(int i = 0; i < r; i++) for(int j = 0; j < c; j++) cin >> v[i][j];
	cout << "E";
	for(int i = 0; i < r; i+=2)
	{
		for(int j = 1; j < c; j++)
		{
			cout << "EE";
		}
		cout << "S";
		for(int j = c-1; j > 0; j--)
		{
			if(i+1 < r && v[i+1][j] == '*') cout << "SSWNNW";
			else cout << "WW";
		}
		if(i < r-2) cout << "SSS";
		else if(i < r-1) cout << "SS";
	}
	cout << "W";
	for(int i = 0; i < 2 * r - 1; i++)
	{
		cout << "N";
	}
	cout << endl;
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