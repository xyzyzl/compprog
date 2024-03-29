#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> // pbds
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/detail/standard_policies.hpp>

#pragma GCC optimize("O3")

using namespace __gnu_pbds;
using namespace std;

#define MAXN 200005

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
#define fileio(file) freopen(file ".in", "r", stdin); freopen(file ".out", "w", stdout)
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

<<<<<<< HEAD
int n;
int arr[400005], frq[400005];

void solve()
{
	cin >> n;
	vi ans(n+1);
	FOR(i, n)
	{
		cin >> arr[i]; 
		frq[arr[i]]++;
	}
	bool pm = 1;
	F1R(i, n)
	{
		if(!frq[i])
			pm = 0;
	}
	// k=1 means that there must be a permutation.
	// k=n means that there must be a 1 in the list
	if(pm) ans[1] = 1;
	if(frq[1]) ans[n] = 1;
	// otherwise, needs a permutation of [2, n-k+1].
	int l = 0, r = n-1;
	F1RD(i, n)
	{
		if(!ans[n]) break;
		ans[i] = 1;
		int nx = n-i+1;
		if(--frq[nx] == 0 && (arr[l] == nx || arr[r] == nx) && frq[nx+1])
		{
			if(arr[l] == nx) l++;
			if(arr[r] == nx) r--;
			continue;
		}
		// none
		break;
	}
	F1R(i, n) cout << ans[i];
	cout << endl;
	FOR(i, n+1)
	{
		arr[i] = 0;
		frq[i] = 0;
	}
=======
void solve()
{
	int n; cin >> n;
	vi a(n), f(n+1), ans(n+1), a2(n+1);
	FOR(i, n)
	{
		cin >> a[i];
		f[a[i]]++;
	}
	if(f[1] > 0) ans[n] = 1;
	ans[1] = 1;
	F1R(i, n)
	{
		if(f[i] > 1) ans[1] = 0;
	}
	bool oops = 0;
	F1R(i, n-2)
	{
		if(a[i] == 1) oops = 1;
	}
	if(f[1] > 1 || f[1] == 0 || oops)
	{
		F1R(i, n) cout << ans[i];
		cout << endl;
		return;
	}
	if(a[n-1] == 1) reverse(a.begin(), a.end());
	F1R(i, n-2)
	{
		if(a[i] <= a[i-1] && a[i] <= a[i+1])
		{
			a2[i] = 1;
		}
	}
	int id = n+5;
	FORD(i, n) if(a2[i])
	{
		id = i;	
	}
	int mn = INT_MAX;
	F1R(i, id)
	{
		MIN(mn, a[i]);
	}
	if(mn > 3) 
	{
		if(a[n-1] == 2) ans[n-1] = 1;
	} else if(mn == 2)
	{
		ans[n-1] = 1;
	} else if(mn == 0)
	{
		if(ans[1])
		{
			F1R(i,n) ans[i] = 1;
		} else
		{
			FORR(3, i, n+1) ans[i] = 1;
		}
	} else
	{
		ans[n-1] = ans[n-2] = 1;
	}
	F1R(i, n) cout << ans[i];
	cout << endl;
>>>>>>> 292c208fd0f3cae3127f4c86a86359aee1fe25e7
}

signed main()
{
	// fileio("");
	DUEHOANG;
	int t = 1;
	cin >> t; // uncomment if it's multitest
	while(t--)
	{
		solve();
	}
	
}
