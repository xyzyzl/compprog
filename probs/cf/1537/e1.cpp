#include <bits/stdc++.h>

using namespace std;

int n, k;
string s;
int main()
{
	cin >> n >> k;
	cin >> s;
	string ans;
	for(int i = 0; i < k; i++)
	{
		ans += '~';
	}
	for(int i = 0; i < n; i++)
	{
		string pref = s.substr(0, i+1);
		while(pref.length() < k) pref += pref;
		pref = pref.substr(0, k);
		ans = min(ans, pref);
	}
	cout << ans << endl;
}