#include <bits/stdc++.h>

using namespace std;

string s;
int dp[(1 << 21)];
int main()
{
	cin >> s;
	for(int i = 0; i < s.length(); i++)
	{
		vector<bool> v(21);
		int msk = 0;
		for(int x = 1; x <= 20; x++)
		{
			if(i+x-1 >= s.length()) break;
			if(v[s[i+x-1]-'a']) break;
			v[s[i+x-1]-'a']=1;
			msk |= (1 << (s[i+x-1]-'a'));
			dp[msk] = x;
		}
	}
	for(int i = 0; i < (1 << 20); i++)
	{
		for(int k = 0; k < 20; k++)
		{
			if(i & (1 << k)) dp[i] = max(dp[i], dp[i^(1<<k)]);
		}
	}
	int ans = 0;
	for(int i = 0; i < (1 << 20); i++)
	{
		if(dp[i] == __builtin_popcount(i))
			ans = max(ans, dp[i] + dp[i ^ ((1 << 20)-1)]);
	}
	cout << ans << endl;
}
