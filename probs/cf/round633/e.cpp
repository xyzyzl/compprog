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

ll n, a, b, c;
void read()
{
	cin >> n;
}

void solve_solve()
{
	vi qq = { 0, 2, 3, 1 };
	ll x = 1, y = 1;
	int i=0;
	while(y + x <= n)
	{
		y+=x;
		x*=4;
		i+=2;
	}
	i -= 2;
	a = x+n-y;
	b = x*2;
	while(i >= 0)
	{
		int j = (a >> i) & 3;
		b |= (ll)(qq[j]) << i; // turn into mapped value
		i -= 2;
	}
	c = a^b;
}

void solve()
{
	ll q = n%3;
	n = (n+2ll)/3ll;
	solve_solve();
	if(q == 0)
	{
		cout << c << endl;
	} else if(q == 1)
	{
		cout << a << endl;
	} else 
	{
		cout << b << endl;
	}
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
