// Time:
// Algorithms: 

#include <bits/stdc++.h>

#pragma GCC optimize("O3")

using namespace std;

#define MAXN 200005

#define FOR(i, n) for (int i = 0; i < n; i++)
#define FORR(j, i, n) for (int i = j; i < n; i++)
#define FORD(i, n) for (int i = n - 1; i >= 0; i--)
#define FOBIR(i, n) for (int i = 1; i <= n; i++)
#define FOBIRD(i, n) for (int i = n; i >= 1; i--)
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

int n, m, k, h[MAXN], fact[MAXN];

// credit to benq (i think the link has been deleted/moved)
int ad(int a, int b, int mod = MOD2) { return (a+b)%mod; }
int sub(int a, int b, int mod = MOD2) { return (a-b+mod)%mod; }
int mul(int a, int b, int mod = MOD2) { return (ll)a*b%mod; }
int po (int b, int p, int mod = MOD2) { return !p?1:mul(po(mul(b,b,mod),p/2,mod),p&1?b:1,mod); }
int inv (int b, int mod = MOD2) { return po(b,mod-2,mod); }
int ncr(int p, int q)
{
	return mul(fact[p], inv(mul(fact[q], fact[p-q])));
}

int main()
{
    int qt = 1;
    // cin >> t; // uncomment if it's multitest
    while(qt--)
    {
    	cin >> n >> k;
    	
    	fact[0] = 1;
    	FOBIR(i, n) 
    	{
    		fact[i] = mul(fact[i-1], i);
    	}
    	FOR(i, n)
    	{
    		cin >> h[i];
    	}
    	FOR(i, n)
    	{
    		if(h[i] != h[(i+1)%n]) m++;
    	}
    	// cout << m << endl;
    	int tot = po(k, n-m);
    	int sm = 0;
    	FOR(e, m)
    	{
    		int x = po(k-2, e);
    		int y = ncr(m, e);
    		int z;
    		if((m-e)%2) z = po(2, m-e-1);
    		else z = mul(sub(po(2, m-e), ncr(m-e, mul(m-e, inv(2)))), inv(2));
    		sm = ad(sm, mul(x, mul(y, z)));
    	}
    	tot = mul(tot, sm);
    	cout << tot << endl;
    }
    
}
