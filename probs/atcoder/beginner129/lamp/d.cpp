/**
ID: albert.28
LANG: C++14
PROB: poetry
**/

/// Time: like a billion years

#include <bits/stdc++.h>

/**
Mod operations in O(lg n)
Source: Benjamin Qi, https://github.com/bqi343/USACO/blob/master/Implementations/11%20-20(4)/Operators/modOp.cpp?fbclid=IwAR0m2afS-1xVg9kgeF8q8EJIeP9TP3Lct8dYb_hPJuI5gqHP1Utp5EkiOQ8
**/

using namespace std;

#define MAXN 2005
#define MOD 1000000007

#define FOR(g,i,n) for(int i = g; i < n; i++)
#define FORD(g,i,n) for(int i = g; i >= n; i--)

#define apple() ios_base::sync_with_stdio(0)
#define hentai() cin.tie(); cout.tie()

#define mp make_pair
#define pb push_back
#define	ll long long
// #define int ll
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

int n,m;
bool grid[MAXN][MAXN];
int dp[4][MAXN][MAXN]; // 0->u, 1->l, 2->d, 3->r
int main()
{
	apple();
	hentai();
	cin >> n >> m;
	for(int i = 0; i < n; i++) for(int j = 0; j < m; j++)
	{
		char c;
		cin >> c;
		grid[i][j] = c=='.';
	}
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < m; j++)
		{
			if(grid[i][j])
			{
				if(i==0) dp[0][i][j] = 1;
				else dp[0][i][j] = dp[0][i-1][j]+1;
				if(j==0) dp[1][i][j] = 1;
				else dp[1][i][j] = dp[1][i][j-1]+1;
			}
		}
	}
	for(int i = n-1; i >= 0; i--)
	{
		for(int j = m-1; j >= 0; j--)
		{
			if(grid[i][j])
			{
				if(i==n-1) dp[2][i][j] = 1;
				else dp[2][i][j] = dp[2][i+1][j]+1;
				if(j==m-1) dp[3][i][j] = 1;
				else dp[3][i][j] = dp[3][i][j+1]+1;
			}
		}
	}
	int w = 0;
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < m; j++)
		{
			int our_sum = 0;
			for(int k = 0; k < 4; k++) our_sum += dp[k][i][j];
			w = max(w, our_sum);
		}
	}
	cout << w-3 << endl;
}
