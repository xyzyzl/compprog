/**
ID: albert.28
LANG: C++14
PROB: poetry
**/
 
/// Time:
 
#include <bits/stdc++.h>
 
/**
Mod operations in O(lg n)
Source: Benjamin Qi, https://github.com/bqi343/USACO/blob/master/Implementations/11%20-20(4)/Operators/modOp.cpp?fbclid=IwAR0m2afS-1xVg9kgeF8q8EJIeP9TP3Lct8dYb_hPJuI5gqHP1Utp5EkiOQ8
**/
 
using namespace std;
 
#define MAXN 100005
#define MOD 1000000007
 
#define FOR(g,i,n) for(int i = g; i < n; i++)
#define FORD(g,i,n) for(int i = g; i >= n; i--)
 
#define apple() ios_base::sync_with_stdio(0)
#define hentai() cin.tie(); cout.tie()
 
#define mp make_pair
#define pb push_back
#define	ll long long
#define int ll
#define INF (1e9*1)+5
#define LL_INF (1e18*1)+5
#define bitinc(s) (s&-s)
#define endl '\n'
 
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef set<int> si;
typedef map<int, int> mi;
#define f first
#define s second
typedef vector<pii> vii;
typedef set<pii> sii;
typedef map<pii, pii> mii;
 
void fileio(char* in, char* out)
{
	freopen(in, "r", stdin);
	freopen(out, "w", stdout);
}
 
namespace modOp
{
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
}
 
using namespace modOp;
 
int n, m, arr[MAXN], dp[MAXN][105];
int32_t main() {
	cin >> n >> m;
	int first_nz = -1, start = 0;
	for(int i = 1; i <= n; i++)
	{
		cin >> arr[i];
		if(arr[i] != 0 && first_nz == -1) first_nz = arr[i];
	}
	if(arr[1] == 0) // all zeroes
	{
		fill(dp[1] + 1, dp[1] + m + 1, 1);
	} else
	{
		start = first_nz;
	}
	// cout << dp[0][0] << endl;
	if(start) dp[1][start] = 1;
	for(int i = 2; i <= n; i++)
	{
		if(arr[i] == 0) for(int j = 1; j <= m; j++)
		{
			// we are at arbitrary number. check j-1, j+1, j
			dp[i][j] = (dp[i-1][j-1] + dp[i-1][j] + dp[i-1][j+1]) % MOD;
			// cout << dp[i][j] << endl;
		} else
		{
			int j = arr[i];
			dp[i][j] = (dp[i-1][j-1] + dp[i-1][j] + dp[i-1][j+1]) % MOD;
		}
	}
	int aq = 0;
	for(int i = 1; i <= m; i++) aq = (aq + dp[n][i]) % MOD;
	cout << aq << endl;
}