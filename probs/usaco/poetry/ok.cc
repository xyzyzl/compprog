#include <bits/stdc++.h> // :rage: :deciduous_tree:

#pragma GCC optimize("O3")

using namespace std;

#define MAXN 100005

#define FOR(i, n) for (int i = 0; i < n; i++)
#define FORR(j, i, n) for (int i = j; i < n; i++)
#define FORD(i, n) for (int i = n - 1; i >= 0; i--)
#define FOBIR(i, n) for (int i = 1; i <= n; i++)
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

typedef set<int> si;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef pair<int, pii> iii;
typedef vector<pii> vii;
typedef priority_queue<int> pqi;
typedef stack<int> sti;
typedef queue<int> qi;
typedef deque<int> di;
typedef map<int, int> mii;
#define f first
#define s second

#define MOD 1e9+7

#define LEFT(x) 2 * x
#define RIGHT(x) 2 * x + 1

#define bitinc(x) x&-x

#define int ll
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
#undef int

using namespace modOp;

ll n,m,k,w[MAXN],c[MAXN],dp[MAXN],a[MAXN];
map<char,int> f;
int main()
{
    fileio("poetry.in", "poetry.out");
    int t = 1;
    // cin >> t;
    while(t--)
    {
        cin >> n >> m >> k;
        FOR(i, n)
        {
            cin >> w[i] >> c[i];
        }
        dp[0] = 1;
        FOR(i, k)
        {
            FOR(j, n)
            {
                if(w[j]+i > k) continue;
                if(w[j]+i == k) AD(a[c[j]], dp[i]);
                else AD(dp[w[j]+i], dp[i]);
            }
        }
        FOR(i, m)
        {
            char c;
            cin >> c;
            f[c]++;
        }
        ll fin = 1;
        for(pii x : f)
        {
            int ex = x.s;
            // take each index to the power of this exponent, and 
            ll ans = 0;
            FOBIR(i, n)
            {
                AD(ans, po(a[i], ex));
            }
            MUL(fin, ans);
        }
        cout << fin << endl;
    }
}