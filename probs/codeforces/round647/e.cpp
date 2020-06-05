// Time:
// Algorithms: 

/**
 * How I screwed up:
 * 
 * (1) skipping all identical indices was not a very good idea
 * should have used another variable to iterate through "identical"
 * plus that would've only iterated once anyway??
 * (2) k < n, not k < n-1 !!!!!!
 */

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
#define MOD (1e9*1)+7
#define MOD2 998244353
#define INF (1e9*1)+7

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

int n, p, a[MAXN];
void read()
{
	cin >> n >> p;
	FOR(i, n) cin >> a[i];
	sort(a, a+n);
	reverse(a, a+n);
}

void solve()
{
	ll t = 0;
	int ans = 0;
	bool big = 0; // eesti BIG
	int pre_ind = MAXN; // so that we can actually consider i=0
	int k = 0;
	FOR(i, n)
	{
		int tmp = a[i];
		int d = pre_ind - tmp;
		// cerr << d << endl;
		pre_ind = tmp;
		MUL(ans, po(p, d));
		FOR(j, min(d, 20))
		{
			t *= p;
			if(t > MAXN) big = 1;
		}
		while(k < n && a[k] == tmp)
		{
			// cout << big << endl;
			k++;
			if(big || t > 0)
			{
				t--;
				SUB(ans, 1);
			} else 
			{
				t++;
				AD(ans, 1);
			}
		}
	}
	// cout << ans << endl;
	MUL(ans, po(p, a[n-1]));
	cout << ans << endl;
}

int main()
{
	DUEHOANG;
	int t = 1;
	cin >> t; // uncomment if it's multitest
	while(t--)
	{
		read();
		solve();
	}
	
}
