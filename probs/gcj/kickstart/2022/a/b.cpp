#include <bits/stdc++.h>

using namespace std;

void solve()
{
	string s; cin >> s;
	int n = s.length();
	// always best to add just one digit
	int sod = 0;
	for(int i = 0; i < n; i++)
	{
		sod += (s[i]-'0');
	}
	sod %= 9;
	sod = 9-sod;
	sod %= 9;
	bool added = 0;
	for(int i = 0; i < n; i++)
	{
		if(sod == 0 && i == 0)
		{
			cout << s[i];
			continue;
		}
		if(!added && sod < (s[i]-'0'))
		{
			cout << sod;
			added = 1;
		}
		cout << s[i];
	}
	if(!added) cout << sod;
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