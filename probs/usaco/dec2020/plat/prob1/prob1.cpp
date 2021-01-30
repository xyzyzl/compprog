#include <bits/stdc++.h>

using namespace std;
const int MOD = 1e9+7;

int N, S[3005], T[3005], dp[6005][3005][2]; // ui is the current index, i is the number of unpaired cows,
// j is whether or not the cow has a pair
int main()
{
	memset(S, 0x7f, sizeof S);
	memset(T, 0x7f, sizeof T);
	cin >> N;
	for(int i = 0; i < N; i++) cin >> S[i];
	for(int i = 0; i < N; i++) cin >> T[i];
	sort(S, S+N);
	sort(T, T+N);
	dp[0][0][0] = 1;
	int si = 0, ti = 0, ui = 0;
	while(si < N || ti < N)
	{
		if(S[si] <= T[ti])
		{
			// should pick a cow and decide if the cow has been skipped over or not
			for(int i = 0; i < N; i++) for(int j = 0; j < 2; j++)
			{
				// take the cow
				dp[ui+1][i+1][j] = (dp[ui+1][i+1][j] + dp[ui][i][j])%MOD;
				// skip the cow -- must be 1
				dp[ui+1][i][1] = (dp[ui+1][i][1] + dp[ui][i][j])%MOD;
			}
			si++;
		} else
		{
			// should pick a barn
			for(int i = 0; i < N; i++) for(int j = 0; j < 2; j++)
			{
				if(i==0) continue; // actually can't pick a barn in this case oops
				// pair with the barn
				dp[ui+1][i-1][j] = (long long)(dp[ui+1][i-1][j] + ((long long)(i)*(dp[ui][i][j])) % MOD)%MOD;
			}
			// skip over the barn
			for(int i = 0; i < N; i++) dp[ui+1][i][0] = (long long)(dp[ui+1][i][0] + dp[ui][i][0]) % MOD;
			ti++;
		}
		++ui;
	}
	cout << ((long long)(dp[ui][0][0] + dp[ui][0][1])%MOD) << endl;
}