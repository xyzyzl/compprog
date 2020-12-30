#include <bits/stdc++.h>

using namespace std;

int n;
#define ll long long
ll C[100005], dp[100005][2];
string S[100005][2];
int main()
{
	cin >> n;
	for(int i = 0; i < n; i++) cin >> C[i];
	for(int i = 0; i < n; i++)
	{
		string s; cin >> s;
		S[i][0] = s;
		reverse(s.begin(), s.end());
		S[i][1] = s;
	}
	for(int i = 0; i < n; i++) for(int j = 0; j < 2; j++) dp[i][j] = 1e16+7;
	ll INF = dp[0][0];
	dp[0][0] = 0;
	dp[0][1] = C[0];
	for(int i = 1; i < n; i++) for(int j = 0; j < 2; j++)
	{
		if(S[i][j] >= S[i-1][0] && dp[i-1][0] < INF) dp[i][j] = min(dp[i][j], dp[i-1][0] + C[i]*j);
		if(S[i][j] >= S[i-1][1] && dp[i-1][1] < INF) dp[i][j] = min(dp[i][j], dp[i-1][1] + C[i]*j);
	}
	cout << (min(dp[n-1][0], dp[n-1][1]) >= INF ? (-1) : min(dp[n-1][0], dp[n-1][1])) << endl;
}