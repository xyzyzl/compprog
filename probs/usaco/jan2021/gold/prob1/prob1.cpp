#include <bits/stdc++.h>

using namespace std;

int N;
string S;
vector<char> V = {'b', 'd', 'e', 'i', 'l', 'm', 'r', 's'};
map<char, int> id;
int dp[100005][520];
void onetofive()
{
	memset(dp, 0x7f, sizeof dp);
	// test cases 1..5
	for(int i = 0; i < 9; i++)
	{
		id[V[i]]=i;
	}
	dp[0][(1 << id[S[0]])] = 1;
	for(int i = 0; i < N; i++)
	{
		// start new one
		for(int j = 0; j < (1 << 9); j++)
		{
			dp[i][(1 << id[S[i]])]=min(dp[i][(1 << id[S[i]])], dp[i][j]+1);
			if(j & (1 << id[S[i]])) continue;
		}
	}
	int ans = INT_MAX;
	for(int j = 0; j < (1 << 9); j++) ans = min(ans, dp[N-1][j]);
	cout << ans << endl;
}

int main()
{
	cin >> S;
	N = S.length();
	onetofive();
}
