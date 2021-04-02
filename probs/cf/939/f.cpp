#include <bits/stdc++.h>

using namespace std;
const int MAXN = 100005;
using pii = pair<int, int>;
#define f first
#define s second

int n, k, dp[MAXN][105];
pii P[MAXN];
int main()
{
	cin >> n >> k;
	for(int i = 0; i < n; i++)
	{
		int l, r; cin >> l >> r;
		P[i] = {l, r};
	}
	for(int i = 0; i < k; i++)
	{
		int l = 1, r = 0;
		for(int j = P[i].s; j >= 0; j--)
		{
			while(l <= r && dp[i-1][r] >= dp[i-1][P[i].s-j]) r--;
		}
	}
}