#include <bits/stdc++.h>

using namespace std;

int n, m, ct[20][20], slo[(1 << 20) + 5][20], lb[(1 << 20) + 5];
int dp[(1 << 20) + 5]; // we assume that the current keyboard is [msk] and we try to add more chars
string S;
int main()
{
	cin >> n >> m >> S;
	for(int i = 1; i < n; i++)
	{
		ct[S[i-1]-'a'][S[i]-'a']++;
		ct[S[i]-'a'][S[i-1]-'a']++;
	}
	for(int i = 0; i < (1 << m); i++) for(int j = 0; j < m; j++) if(i & (1 << j))
	{
		lb[i] = j; break;
	}
	for(int i = 0; i < (1 << m); i++) for(int j = 0; j < m; j++)
	{
		// slo[i][j] is the added slowness by adding characters j to the mask i
		slo[i][j] = slo[(i ^ (1 << lb[i]))][j] + ct[j][lb[i]];
	}
	memset(dp, 0x7f, sizeof dp);
	dp[0] = 0; // no keyboard = no slowness
	for(int i = 0; i < (1 << m); i++) for(int j = 0; j < m; j++)
	{
		if(i & (1 << j)) continue;
		int ki = __builtin_popcount(i); // we add j to the keyboard
		dp[i | (1 << j)] = min(dp[i | (1 << j)], dp[i] + ki*(slo[i][j] - slo[((1 << m)-1) ^ (i | (1 << j))][j]));
		// add all instances of character j at once; ki is the position of j in the keyboard. 
	}
	cout << dp[(1 << m)-1] << endl;
}