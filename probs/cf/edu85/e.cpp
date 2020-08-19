// Time:
// Algorithms: 

#include <bits/stdc++.h>

#pragma GCC optimize("O3")

using namespace std;

#define MAXN 1000005

#define FOR(i, n) for (int i = 0; i < n; i++)
#define FORR(j, i, n) for (int i = j; i < n; i++)
#define FORD(i, n) for (int i = n - 1; i >= 0; i--)
#define F1R(i, n) for (int i = 1; i <= n; i++)
#define F1RD(i, n) for (int i = n; i >= 1; i--)
#define pb push_back
#define mp make_pair
#define endl '\n'
#define DUEHOANG                  \
	ios_base::sync_with_stdio(0); \
	cin.tie(NULL);                \
	cout.tie(NULL)

#define fileio(in, out)      \
	freopen(in, "r", stdin); \
	freopen(out, "w", stdout);

#define ll long long
// #define MOD (1e9*1)+7
#define MOD 998244353
#define INF (1e9*1)+5

typedef set<int> si;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef pair<int, pii> iii;
typedef vector<pii> vii;
typedef vector<iii> viii;
typedef priority_queue<int> pqi;
typedef stack<int> sti;
typedef queue<int> qi;
typedef deque<int> di;
typedef map<int, int> mii;
#define f first
#define s second

#define LEFT(x) 2 * x
#define RIGHT(x) 2 * x + 1

#define bitinc(x) x&-x

const int MAX(int &a, int b)
{
	return a = max(a, b); 
}
const int MIN(int &a, int b)
{
	return a = min(a, b); 
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

ll D;
int q;
vector<ll> primes;

int fact[101], fact_inv[101];

void read()
{
	cin >> D >> q;
	// each query will be processed online
	// but precomp can be done now
	for(ll i = 2; i * i <= D; i++)
	{
		if(D%i == 0)
		{
			primes.pb(i);
			while(D%i == 0) D /= i;
		}
	}
	if(D > 1) primes.pb(D);

	fact[0] = 1;
	F1R(i, 99)
	{
		fact[i] = mul(fact[i-1], i);
	}
	fact_inv[99] = inv(fact[99]);
	FORD(i, 99) fact_inv[i] = mul(fact_inv[i+1], i+1);
}

void solve()
{
	while(q--)
	{
		ll u, v;
		cin >> u >> v;
		// now find the gcd of u, v
		vi inc, dec; // which values to increase and which to decrease
		for(ll p : primes)
		{
			int ct = 0;
			while(u%p == 0)
			{
				ct--;
				u /= p;
			}
			while(v%p == 0)
			{
				ct++;
				v /= p;
			}
			if(ct < 0) dec.pb(-ct);
			else if(ct > 0) inc.pb(ct);
		}
		// now find # ways for this
		int ans = 1;
		int sm = 0;
		for(int x : inc)
			sm += x;
		MUL(ans, fact[sm]);
		for(int x : inc)
			MUL(ans, fact_inv[x]);
		// multinomial formula
		sm = 0;
		for(int x : dec)
			sm += x;
		MUL(ans, fact[sm]);
		for(int x : dec)
			MUL(ans, fact_inv[x]);
		cout << ans << endl;
	}
}

int main()
{
	DUEHOANG;
	int t = 1;
	// cin >> t; // uncomment if it's multitest
	while(t--)
	{
		read();
		solve();
	}
	
}
