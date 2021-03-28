#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int N;
ll dp[705][705][3][3];
string S;

const int MOD = 1e9+7;
int msum(ll a, ll b)
{
	return (a+b)%MOD;
}
int mmul(ll a, ll b)
{
	return (a*b)%MOD;
}

ll rec(int i, int j, int ci, int cj)
{
	if(dp[i][j][ci][cj] != -1) return dp[i][j][ci][cj];
	ll ret = 0;
	if(j-i+1==2)
	{
		// either no color, two adjacent with same color, or an invalid matching pair
		if((ci && cj) || ci==cj) ret = 0;
		else ret = 1;
	} else 
	{
		int ct = 0, x = 1;
		for(int y = i; y <= j; y++)
		{
			if(S[y] == '(') ct++;
			else            ct--;
			if(ct == 0)
			{
				x=y;
				break;
			}
		}
		// this must be a matching pair!
		if(x==j)
		{
			if((ci && cj) || ci==cj) return dp[i][j][ci][cj] = 0;
			if(ci == 1)
			{
				ret += rec(i+1, j-1, 0, 0);
				ret += rec(i+1, j-1, 0, 1);
				ret += rec(i+1, j-1, 0, 2);
				ret += rec(i+1, j-1, 2, 0);
				ret += rec(i+1, j-1, 2, 1);
				ret += rec(i+1, j-1, 2, 2);
			}
			else if(ci == 2)
			{
				ret += rec(i+1, j-1, 0, 0);
				ret += rec(i+1, j-1, 0, 1);
				ret += rec(i+1, j-1, 0, 2);
				ret += rec(i+1, j-1, 1, 0);
				ret += rec(i+1, j-1, 1, 1);
				ret += rec(i+1, j-1, 1, 2);
			}
			else if(cj == 1)
			{
				ret += rec(i+1, j-1, 0, 0);
				ret += rec(i+1, j-1, 1, 0);
				ret += rec(i+1, j-1, 2, 0);
				ret += rec(i+1, j-1, 0, 2);
				ret += rec(i+1, j-1, 1, 2);
				ret += rec(i+1, j-1, 2, 2);
			}
			else if(cj == 2)
			{
				ret += rec(i+1, j-1, 0, 0);
				ret += rec(i+1, j-1, 1, 0);
				ret += rec(i+1, j-1, 2, 0);
				ret += rec(i+1, j-1, 0, 1);
				ret += rec(i+1, j-1, 1, 1);
				ret += rec(i+1, j-1, 2, 1);
			}
			ret %= MOD;
		} else 
		{
			if(ci == 0)
			{
				ret = msum(ret, mmul(rec(i, x, ci, 1), rec(x+1, j, 0, cj)));
				ret = msum(ret, mmul(rec(i, x, ci, 1), rec(x+1, j, 2, cj)));
				ret = msum(ret, mmul(rec(i, x, ci, 2), rec(x+1, j, 0, cj)));
				ret = msum(ret, mmul(rec(i, x, ci, 2), rec(x+1, j, 1, cj)));
			} else 
			{
				ret = msum(ret, mmul(rec(i, x, ci, 0), rec(x+1, j, 0, cj)));
				ret = msum(ret, mmul(rec(i, x, ci, 0), rec(x+1, j, 1, cj)));
				ret = msum(ret, mmul(rec(i, x, ci, 0), rec(x+1, j, 2, cj)));
			}
		}
	}
	return dp[i][j][ci][cj]=ret;
}

int main()
{
	cin >> S;
	N = S.length();
	memset(dp, -1, sizeof dp);
	ll ans = 0;
	for(int i = 0; i < 3; i++) for(int j = 0; j < 3; j++)
		ans = msum(ans, rec(0, N-1, i, j)); 
	cout << ans << endl;
}
