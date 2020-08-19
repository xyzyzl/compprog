#include <bits/stdc++.h>

using namespace std;

int main()
{
	int t;
	cin >> t;
	while(t--)
	{
		string s;
		cin >> s;
		map<char, int> occ;
		for(int i = 0; i < s.length(); i++)
		{
			occ[s[i]]++;
		}
		char ans = 'n';
		if(occ['R'] >= occ['S'] && occ['R'] >= occ['P'])
		{
			ans = 'P';
		} else if(occ['S'] >= occ['P'] && occ['S'] >= occ['R'])
		{
			ans = 'R';
		} else 
		{
			ans = 'S';
		}
		for(int i = 0; i < s.length(); i++) cout << ans;
		cout << endl;
	}
}
