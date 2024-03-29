#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> // pbds
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/detail/standard_policies.hpp>

#pragma GCC optimize("O3")

using namespace __gnu_pbds;
using namespace std;

#define MAXN 5205

#define FOR(i, n) for (int i = 0; i < n; i++)
#define FORR(j, i, n) for (int i = j; i < n; i++)
#define FORD(i, n) for (int i = n - 1; i >= 0; i--)
#define F1R(i, n) for (int i = 1; i <= n; i++)
#define F1RD(i, n) for (int i = n; i >= 1; i--)
#define pb push_back
#define mp make_pair
#define ins insert
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
// ordered_set
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> os;
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

int n, a[MAXN][MAXN];

int base10(char hex) {
    return isdigit(hex) ? hex - '0' : hex - 'A' + 10;
}

void solve()
{
	cin >> n;
	F1R(i, n)
	{
		char str[n];
		cin >> str;
		reverse(str, str+n/4);
		FOR(j, n)
		{
			a[i][j+1] = (base10(str[j / 4]) >> j % 4) & 1;
		}
		/*
		F1R(j, n) 
		{
			cout << a[i][j] << ' ';
		}
		cout << endl;
		*/
	}
	F1R(i, n) F1R(j, n)
	{
		a[i][j] += a[i-1][j];
		a[i][j] += a[i][j-1];
		a[i][j] -= a[i-1][j-1];
	}
	int ans = 0;
	F1RD(x, n)
	{
		bool good=1;
		if(n%x) continue; // not divisible ==> not possible
		for(int i = 1; i <= n; i += x) for(int j = 1; j <= n; j += x)
		{
			int y = a[i+x-1][j+x-1]-a[i-1][j+x-1]-a[i+x-1][j-1]+a[i-1][j-1];
			if(y != 0 && y != x*x)
			{
				good = 0;
			}
		}
		if(good)
		{
			ans=x;
			break;
		}
	}
	cout << ans << endl;
}

signed main()
{
	DUEHOANG;
	int t = 1;
	// cin >> t; // uncomment if it's multitest
	while(t--)
	{
		solve();
	}
	
}
