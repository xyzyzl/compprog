// Time:
// Algorithms: 

#include <bits/stdc++.h>

#pragma GCC optimize("O3")

using namespace std;

#define MAXN 505

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

int n, arr[MAXN], psum[MAXN], inds[MAXN];
void solve()
{
	cin >> n;
	FOR(i, n+1)
	{
		cin >> arr[i];
	}
	vi ans;
	FOR(iter, n+1)
	{
		vi v, psum;
		FOR(i, n+1)
		{
			if(i != iter) v.pb(arr[i]);
		}
		sort(v.begin(), v.end());
		reverse(v.begin(), v.end());
		psum.pb(v[0]);
		FOBIR(i, n-1)
		{
			psum.pb(psum.back() + v[i]);
		}
		bool ok = 1;
		if(psum.back()%2)
		{
			continue;
		}
		FOR(k, n)
		{
			int l = psum[k];
			int r = k*(k+1);
			FORR(k+1, i, n)
			{
				r += min(v[i], k+1);
			}
			// cout << l << " " << r << endl;
			if(l > r)
			{
				ok = 0;
				break;
			}
		}
		if(ok) ans.pb(iter+1);
	}
	cout << ans.size() << endl;
	for(int x : ans) cout << x << endl;
}

int main()
{
	fileio("fcount.in", "fcount.out");
	int t = 1;
	// cin >> t; // uncomment if it's multitest
	while(t--)
	{
		solve();
	}
	
}
