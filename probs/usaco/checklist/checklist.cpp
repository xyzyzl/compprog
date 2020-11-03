#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define MAXN 1005
#define FOR(i, n) for(int i = 0; i < n; i++)
#define F1R(i, n) for(int i = 1; i <=n; i++)
typedef pair<int, int> pii;
#define f first
#define s second

int H, G;
ll dp[MAXN][MAXN][2];
pii h[MAXN], g[MAXN];

ll sqd(pii x, pii y)
{
	return (ll)(x.f-y.f)*(ll)(x.f-y.f)+(ll)(x.s-y.s)*(ll)(x.s-y.s);
}

int main()
{
	freopen("checklist.in", "r", stdin);
	freopen("checklist.out", "w",stdout);
	cin >> H >> G;
	F1R(i, H) cin >> h[i].f >> h[i].s;
	F1R(i, G) cin >> g[i].f >> g[i].s;
	FOR(i, H+1) FOR(j, G+1) dp[i][j][0] = dp[i][j][1] = (1ll << 40);
	dp[1][0][0] = 0;
	FOR(i, H+1) FOR(j, G+1)
	{
		if(!i && !j) continue;
		if(i-1 >= 0)
		{
			dp[i][j][0] = min(dp[i-1][j][0]+sqd(h[i-1],h[i]), dp[i][j][0]);
			dp[i][j][0] = min(dp[i-1][j][1]+sqd(g[j],  h[i]), dp[i][j][0]);
		}
		if(j-1 >= 0)
		{
			dp[i][j][1] = min(dp[i][j-1][0]+sqd(h[i],  g[j]), dp[i][j][1]);
			dp[i][j][1] = min(dp[i][j-1][1]+sqd(g[j-1],g[j]), dp[i][j][1]);
		}
	}
	cout << dp[H][G][0] << endl;
}
