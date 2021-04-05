#include <bits/stdc++.h>

using namespace std;
const int MAXN = 100005;
using pii = pair<int, int>;
#define f first
#define s second

int n, k, dp[2][200005];
pii P[MAXN];
int main()
{
	cin >> n >> k;
	for(int i = 0; i < k; i++)
	{
		int l, r; cin >> l >> r;
		P[i] = {l, r};
	}
	deque<int> mq;
	memset(dp, 0x7f, sizeof dp);
	dp[0][0] = 0;
	// look at each interval
	for(int i = 0; i < k; i++)
	{
		// we nothing
		for(int j = 0; j <= P[i].s; j++) dp[1][j] = dp[0][j];
		// we flip
		while(!mq.empty()) mq.pop_back();
		// j seconds on this side = P[i].s-j seconds on the other side
		for(int j = P[i].s; j >= 0; j--)
		{
			// try to remove everything that is too large
			while(!mq.empty() && dp[1][mq.back()] >= dp[1][P[i].s-j]) mq.pop_back();
			while(!mq.empty() && mq.front() < P[i].f-j) mq.pop_front();
			// we can add the current timestamp
			mq.push_back(P[i].s-j);
			// then we add one to the minimum value in [j-x, j]. we need a deque for this
			dp[0][j] = min(dp[0][j], dp[1][mq.front()]+1);
		}
		while(!mq.empty()) mq.pop_back();
		// we flippy flip
		for(int j = 0; j <= P[i].s; j++)
		{
			// we do the same thing here, except its j seconds on this side, so we adjust the values accordingly
			while(!mq.empty() && dp[1][mq.back()] >= dp[1][j]) mq.pop_back();
			while(!mq.empty() && mq.front() < j-P[i].s+P[i].f) mq.pop_front();
			mq.push_back(j);
			dp[0][j] = min(dp[0][j], dp[1][mq.front()]+2);
		}
	}
	if(dp[0][n] < dp[0][2*n+1]) cout << "Full" << "\n" << dp[0][n] << endl;
	else cout << "Hungry" << endl;
}
