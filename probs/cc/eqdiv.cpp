#include <bits/stdc++.h>

using namespace std;

int K;
bool dp[35][20000000];
string S;
void do_dp()
{
	dp[0][0] = 1;
	vector<int> V, nV;
	V.push_back(0);
	for(int i = 1; i <= (1 << K+1); i++)
	{
		nV = V;
		for(int j : V)
		{
			dp[i][j + (int)pow(i, K)] |= dp[i-1][j];
			nV.push_back(j + (int)pow(i, K));
			dp[i][j] |= dp[i-1][j];
		}
		V = nV;
	}
	for(int i : V) cout << i << " " ;
	cout << endl;
}

void solve()
{
	int n; cin >> n;
	int ans = 0;
	for(int i = 1; i <= n; i++) ans += pow(i,K);
	ans /= 2;
	cerr << ans << endl;
	int md = INT_MAX;
	for(int i = 0; i <= ans; i++)
	{
		if(dp[(1 << K+1)][ans-i] || dp[(1 << K+1)][ans+i])
		{
			md = i;
			break;
		}
	}
	cout << md << endl;
}

int main()
{
	cin >> K;
	// literally garbage question holy
	if(K==1)
	{
		S = "1001";
	} else if(K==2)
	{
		S = "10010110";
	} else if(K==3)
	{
		S = "1001011001101001";
	} else
	{
		S = "10010110011010010110100110010110";
	}
	do_dp();
	int t; cin >> t;
	while(t--)
	{
		solve();
	}
}