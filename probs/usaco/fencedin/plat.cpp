#include <bits/stdc++.h>

using namespace std;

#define MAXN 25005
#define ll long long
int A,B,n,m;
ll v[MAXN],h[MAXN],dv[MAXN],dh[MAXN];
int main()
{
	freopen("fencedin.in", "r", stdin);
	freopen("fencedin.out", "w", stdout);
	cin >> A >> B >> n >> m;
	v[0] = 0;
	h[0] = 0;
	for(int i = 1; i <= n; i++) cin >> v[i];
	v[n+1] = A;
	for(int i = 1; i <= m; i++) cin >> h[i];
	h[m+1] = B;
	sort(v,v+n+2);
	sort(h,h+m+2);
	for(int i = 1; i <= n+1; i++)
	{
		dv[i-1] = v[i] - v[i-1];
	}
	for(int i = 1; i <= m+1; i++) 
	{
		dh[i-1] = h[i] - h[i-1];
	}
	sort(dv, dv+n+1);
	sort(dh, dh+m+1);
	ll ans = dv[0]*m+dh[0]*n;
	for(int i = 1, j = 1; i <= n && j <= m; )
	{
		if(dv[i] > dh[j])
		{
			ans += dh[j++]*(n-i+1);
		} else 
		{
			ans += dv[i++]*(m-j+1);
		}
	}
	cout << ans << endl;
}