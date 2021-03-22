#include <bits/stdc++.h>

using namespace std;
using ll=long long;

int n;
ll x, y;
string s;
int main()
{
	cin >> s;
	n = s.length();
	cin >> x >> y;
	ll tot = 0;
	int t = 0;
	for(int i = 0; i < n; i++)
	{
		if(s[i] != '1') tot += (i-t)*y, ++t;
		else tot += t*x;
	}
	ll ans = tot, res = tot;
	int l=0, r=t;
	for(int i=0; i < n; i++)
	{
		if(s[i] == '0') ++l, --r;
		if(s[i] == '?') --r, ans=min(ans, res=res-(i-l)*y-(n-i-1-r)*x+l*x+r*y);
	}
	res = tot;
	l=t, r=0;
	for(int i=n-1; i >= 0; i--)
	{
		if(s[i] == '0') --l, ++r;
		if(s[i] == '?') --l, ans=min(ans, res=res-(i-l)*y-(n-i-1-r)*x+l*x+r*y);
	}
	cout << ans << endl;
}