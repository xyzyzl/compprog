#include <bits/stdc++.h>

using namespace std;

#define MAXN 5005
#define ll long long

int n,q,vis[MAXN][MAXN];
ll a[MAXN],dp[MAXN][MAXN],frq[200005];

ll rec(int l, int r)
{
	if(l > r) 
	{
		return -1;
	}
	if(l == r || vis[l][r]) return dp[l][r];
	vis[l][r] = 1;
	ll x = rec(l+1, r);
	ll y = rec(l, r-1);
	ll z = rec(l+1, r-1);
	if(x==-1||y==-1||z==-1) return 0;
	dp[l][r] += x+y-z;
	return dp[l][r];
}

int main()
{
	freopen("threesum.in", "r", stdin);
	freopen("threesum.out", "w", stdout);
	cin >> n >> q;
	for(int i=0; i < n; i++) cin >> a[i];
	for(int i=0; i < n; i++)
	{
		for(int j = i+1; j < n; j++)
		{
			dp[i][j] = frq[100005-a[i]-a[j]];
			frq[100005+a[j]]++;
		}
		for(int j = i+1; j < n; j++) frq[100005+a[j]]--;
	}
	rec(0,n-1);
	while(q--)
	{
		int l,r;
		cin >> l >> r;
		--l; --r;
		cout << dp[l][r] << endl;
	}
}
