#include <bits/stdc++.h>

using namespace std;

int main()
{
	long long s, x; cin >> s >> x;
	if(s < x)
	{
		cout << 0 << endl;
		return 0;
	}
	if((s-x)%2 != 0)
	{
		cout << 0 << endl;
		return 0;
	}	
	long long a = (s-x)/2;
	long long ans = 1;
	int ct = 0;
	for(int bit = 0; (1ll << bit) <= s; bit++)
	{
		if((a & (1ll << bit)) && (x & (1ll << bit)))
		{
			cerr << bit << endl;
			cout << 0 << endl;
			return 0;
		} else 
		{
			if(x & (1ll << bit))
			{
				ans *= 2;
			}
			if(a & (1ll << bit))
			{
				ct++;
			}
		}
	}
	if(!ct) ans -= 2;
	cout << ans << endl;
}