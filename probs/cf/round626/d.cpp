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

int n, arr[MAXN];
void read()
{
	cin >> n;
	F1R(i, n) cin >> arr[i];
	// sort(arr, arr+n);
}

void solve()
{
	int highest = arr[n-1];
	int ans = 0;
	FORD(k, 27)
	{
		// vi v(n);
		// FOR(i, n) v[i] = arr[i] & ((1 << (k+1)) - 1);
		F1R(i, n) arr[i] &= ((1 << (k+1)) - 1);
		sort(arr+1, arr+n+1);
		// sort(v.begin(), v.end());
		F1R(i, n)
		{
			auto a = lower_bound(arr+1, arr+i, (1 << k) - arr[i]);
			auto b = upper_bound(arr+1, arr+i, (1 << (k+1)) - arr[i] - 1);
			auto c = lower_bound(arr+1, arr+i, (1 << (k+1)) + (1 << k) - arr[i]); // WA because I arranged the parentheses wrong
			// note to self: (a << b) must always be surrounded by parentheses to work
			// if there are bit operations and code seems right check if bit ops are parenthesized right
			auto d = upper_bound(arr+1, arr+i, ((1 << (k+2)) - 2) - arr[i]);
			int int1 = b-a;
			if(int1 % 2)
				ans ^= (1 << k);
			int int2 = d-c;
			if(int2 % 2)
				ans ^= (1 << k);
		}
	}
	cout << ans << endl;
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
