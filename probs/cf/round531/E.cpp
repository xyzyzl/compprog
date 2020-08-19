/*input
5
1 2 1 2 3
*/

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

int ad(int a, int b, int mod = MOD2) { return (a+b)%mod; }
int sub(int a, int b, int mod = MOD2) { return (a-b+mod)%mod; }
int mul(int a, int b, int mod = MOD2) { return (ll)a*b%mod; }

int AD(int& a, int b, int mod = MOD2) { return a = ad(a,b,mod); }
int SUB(int& a, int b, int mod = MOD2) { return a = sub(a,b,mod); }
int MUL(int& a, int b, int mod = MOD2) { return a = mul(a,b,mod); }

int po (int b, int p, int mod = MOD2) { return !p?1:mul(po(mul(b,b,mod),p/2,mod),p&1?b:1,mod); }
int inv (int b, int mod = MOD2) { return po(b,mod-2,mod); }

int invGeneral(int a, int b) { // 0 < a < b, gcd(a,b) = 1
 	if (a == 0) return b == 1 ? 0 : -1;
   	int x = invGeneral(b%a,a);
   	return x == -1 ? -1 : ((1-(ll)b*x)/a+b)%b;
} 

int n, a[MAXN], ans;
mii freq, run;
si curr;
void solve()
{
	cin >> n;
	FOR(i, n)
	{
		cin >> a[i];
		freq[a[i]]++;
	}
	FOR(i, n)
	{
		if(!run[a[i]]) curr.insert(a[i]);
		run[a[i]]++;
		if(run[a[i]] == freq[a[i]]) curr.erase(a[i]);
		if(curr.size() == 0) ans++;
	}
	cout << po(2, ans-1) << endl;
}

int main()
{
	// fileio("1.txt", "e.txt");
	int t = 1;
	// cin >> t; // uncomment if it's multitest
	while(t--)
	{
		solve();
	}
	
}
