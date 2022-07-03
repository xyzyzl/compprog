#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve()
{
	int n; cin >> n;
	string s; cin >> s;
	vector<ll> freq(2*n+5), fr3q(3);
	int bal = n+1;
	freq[bal]++;
	fr3q[bal%3]++;
	ll ans = 0;
	for(int i = 0; i < n; i++)
	{
		int baln = bal;
		if(s[i] == '-')
		{
			baln--;
			fr3q[baln%3] += freq[baln];
			ans += fr3q[baln%3];
			freq[baln]++;
			fr3q[baln%3]++;
		} else 
		{
			fr3q[baln%3] -= freq[baln];
			baln++;
			ans += fr3q[baln%3];
			freq[baln]++;
			fr3q[baln%3]++;
		}
		bal = baln;
	}
	cout << ans << endl;
}

int main()
{
	int t; cin >> t;
	while(t--) solve();
}