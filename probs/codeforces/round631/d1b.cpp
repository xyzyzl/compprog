/*input
10
1 1000000000
2 999999999
3 99999998
4 9999997
5 999996
6 99995
7 9994
8 993
9 92
10 1
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

int mul(int a, int b, int mod=MOD)
{
	ll x = a;
	ll y = b;
	return (int)(x*y%mod);
}

int MUL(int& a, int b, int mod)
{
	return a = mul(a,b,mod);
}

void solve()
{
	int d,m;
	cin>>d>>m;
	int res = 1;
	FOR(i, 30)
	{
		if((1 << i) > d) break;
		MUL(res, min(d, (1 << (i+1))-1)-(1 << i)+2, m);
	}
	res = (res-1+m)%m;
	cout << res << endl;
}

int main()
{
	// fileio("d1b.in", "d1b.out");
	int t = 1;
	cin >> t; // uncomment if it's multitest
	while(t--)
	{
		solve();
	}
	
}
