#include <bits/stdc++.h>

using namespace std;

#define MAXN 1005
#define ll long long
#define FOR(i, n) for(int i = 0; i < n; i++)
#define F1R(i, n) for(int i = 1; i <= n; i++)
#define mp make_pair

typedef pair<int, int> pii;
#define f first
#define s second

int n, m;
pii a[MAXN], b[MAXN];
ll dp[MAXN][MAXN];

pii get(char c)
{
	pii ret = mp(0,0);
	if(c == 'N')
	{
		ret.s++;
	} else if(c == 'S')
	{
		ret.s--;
	} else if(c == 'E')
	{
		ret.f++;
	} else 
	{
		ret.f--;
	}
	return ret;
}

ll sqd(pii x, pii y)
{
	return (ll)(x.f-y.f)*(ll)(x.f-y.f) + (ll)(x.s-y.s)*(ll)(x.s-y.s);
}

int main()
{
	freopen("radio.in", "r", stdin);
	freopen("radio.out", "w", stdout);
	cin >> n >> m;
	cin >> a[0].f >> a[0].s >> b[0].f >> b[0].s;
	F1R(i, n)
	{
		char c; cin >> c;
		a[i].f = a[i-1].f + get(c).f;
		a[i].s = a[i-1].s + get(c).s;
	}
	F1R(i, m)
	{
		char c; cin >> c;
		b[i].f = b[i-1].f + get(c).f;
		b[i].s = b[i-1].s + get(c).s;
	}
	dp[0][0] = 0;
	FOR(i, n+1)
	{
		FOR(j, m+1)
		{
			if(!i && !j) continue;
			dp[i][j] = sqd(a[i], b[j]);
			ll k = LLONG_MAX;
			if(i) k = min(k, dp[i-1][j]);
			if(j) k = min(k, dp[i][j-1]);
			if(i && j) k = min(k, dp[i-1][j-1]);
			dp[i][j] += k; 
		}
	}
	cout << dp[n][m] << endl;
}