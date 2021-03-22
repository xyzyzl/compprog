#include <bits/stdc++.h>

using namespace std;

const int MAXN = 105;
const int MAXA = 60;
const int MAXS = (1 << 17)+1;
int n, a[MAXN], dp[MAXN][MAXS], ans[MAXN][MAXS], pf[MAXA], ret[MAXN];
int P[17] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59};
int main()
{
	cin >> n;
	for(int i = 1; i <= n; i++) cin >> a[i];
	for(int i = 1; i < MAXA; i++)
	{
		for(int j = 0; j < 17; j++) if(i%P[j]==0) pf[i]+=(1<<j);
	}
	for(int msk = 1; msk < (1 << 17); msk++) dp[0][msk] = (1e9+7);
	for(int i = 1; i <= n; i++)
	{
		for(int msk = 0; msk < (1 << 17); msk++) dp[i][msk] = (1e9+7);
		for(int msk = 0; msk < (1 << 17); msk++)
		{
			for(int j = 1; j < MAXA; j++)
			{
				if(msk & pf[j]) continue;
				int nms = msk | pf[j];
				if(dp[i][nms] > dp[i-1][msk] + abs(j-a[i]))
				{
					dp[i][nms] = dp[i-1][msk] + abs(j-a[i]);
					ans[i][nms] = j;
				}
			}
		}
	}
	int x = 0;
	for(int i = 0; i < (1 << 17); i++)
	{
		if(dp[n][x] > dp[n][i]) x=i;
	}
	int j = 0;
	for(int i = n; i > 0; i--)
	{
		ret[j] = ans[i][x];
		x ^= pf[ret[j++]];
	}
	while(j--) cout << ret[j] << " ";
	cout << endl;
}