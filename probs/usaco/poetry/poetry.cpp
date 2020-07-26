#include <bits/stdc++.h>

#define ll long long

using namespace std;

const int MAXN = 5005;
const int MOD = 1000000007;

int ad(int a, int b, int mod = MOD) { return (a+b)%mod; }
int sub(int a, int b, int mod = MOD) { return (a-b+mod)%mod; }
int mul(int a, int b, int mod = MOD) { return (ll)a*b%mod; }
 
int AD(int& a, int b, int mod = MOD) { return a = ad(a,b,mod); }
int SUB(int& a, int b, int mod = MOD) { return a = sub(a,b,mod); }
int MUL(int& a, int b, int mod = MOD) { return a = mul(a,b,mod); }
 
int po (int b, int p, int mod = MOD) { return !p?1:mul(po(mul(b,b,mod),p/2,mod),p&1?b:1,mod); }
int inv (int b, int mod = MOD) { return po(b,mod-2,mod); }
 
int invGeneral(int a, int b) { // 0 < a < b, gcd(a,b) = 1
	if (a == 0) return b == 1 ? 0 : -1;
	int x = invGeneral(b%a,a);
	return x == -1 ? -1 : ((1-(ll)b*x)/a+b)%b;
}

int n, m, k, w[MAXN], c[MAXN], dp[MAXN], frq[MAXN], val[MAXN];
int main()
{
	freopen("poetry.in", "r", stdin);
	freopen("poetry.out", "w", stdout);
	cin >> n >> m >> k;
	for(int i = 0; i < n; i++)
	{
		cin >> w[i] >> c[i];
		--c[i];
	}
	dp[0] = 1;
	for(int i = 0; i < k; i++)
	{
		for(int j = 0; j < n; j++)
		{
			if(i + w[j] > k) continue;
			if(i + w[j] == k)
			{
				AD(val[c[j]], dp[i]);
			} else
			{
				AD(dp[i+w[j]], dp[i]);
			}
		}
	}
	for(int i = 0; i < m; i++)
	{
		char c;
		cin >> c;
		frq[c-'A']++;
	}
	int ans = 1;
	for(int i = 0; i < 26; i++)
	{
		if(!frq[i]) continue;
		int sub = 0;
		for(int j = 0; j < n; j++)
		{
			if(!val[j]) continue;
			AD(sub, po(val[j], frq[i]));
		}
		MUL(ans, sub);
	}
	cout << ans << endl;
}
