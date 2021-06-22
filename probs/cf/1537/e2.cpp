#include <bits/stdc++.h>

using namespace std;

int n, k;
string s;
int main()
{
	cin >> n >> k >> s;
	int lp = 1;
	for(int i = 1; i < n; i++)
	{
		if(s[i%lp] > s[i])
		{
			lp = i+1;
		}
	}
	string pref = s.substr(0, lp);
	while(pref.length() < k)
	{
		pref += pref;
	}
	cout << pref.substr(0, k) << endl;
}