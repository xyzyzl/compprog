// I tried solving it a while in, but there were quite a few technicalities
// I made an incorrect submission with T=1 hour, but it went wrong
// I went to other questions to try and debug
// I went back here at T=2 minutes, and realized why it went wrong
// Tried to code it and got it to work at T=-1 minutes, but then I couldn't submit.
#include <bits/stdc++.h>

using namespace std;

const int MAXN = 305;

int n, a[MAXN];
pair<int, set<int>> dp[MAXN][MAXN];
int main()
{
	cin >> n;
	for(int i = 0; i < n; i++) cin >> a[i];
	for(int i = 0; i < n; i++)
	{
		dp[i][i] = make_pair(1, set<int>());
		dp[i][i].second.insert(a[i]);
	}
	for(int L = 2; L <= n; L++)
	{
		for(int i = 0; i < n; i++)
		{
			int j = i+L-1;
			int a1 = dp[i+1][j].first;
			set<int> s1 = dp[i+1][j].second;
			s1.insert(a[i]);
			int a2 = dp[i][j-1].first;
			set<int> s2 = dp[i][j-1].second;
			s2.insert(a[j]);
			if(s1.size() < s2.size())
			{
				dp[i][j] = make_pair(s1.size(), s1);
			} else
			{
				dp[i][j] = make_pair(s2.size(), s2);
			}
		}
	}
	cout << dp[0][n-1].first << endl;
}