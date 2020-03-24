// Time:
// Algorithms: 

#include <bits/stdc++.h>

#pragma GCC optimize("O3")

using namespace std;

#define MAXN 50005

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

int n, e[MAXN], pre[MAXN], suf[MAXN];
si b;
void solve()
{
	cin >> n;
	F1R(i, n)
	{
		cin >> e[i];
	}
	F1R(i, 2*n)
	{
		b.insert(i);
	}
	F1R(i, n) b.erase(e[i]);
	F1R(i, n)
	{
		auto x = b.upper_bound(e[i]);
		if(x == b.end())
		{
			pre[i] = pre[i-1];
			continue;
		}
		b.erase(x);
		pre[i] = pre[i-1] + 1;
	}
	b.clear();
	F1R(i, 2*n)
	{
		b.insert(i);
	}
	F1R(i, n) b.erase(e[i]);
	F1RD(i, n)
	{
		auto x = b.lower_bound(e[i]);
		if(x == b.begin())
		{
			suf[i] = suf[i+1];
			continue;
		}
		b.erase(prev(x));
		suf[i] = suf[i+1] + 1;
	}
	int ans = 0;
	FOR(i, n+1)
	{
		MAX(ans, pre[i] + suf[i+1]);
	}
	cout << ans << endl;
}

int main()
{
	fileio("cardgame.in", "cardgame.out");
	int t = 1;
	// cin >> t; // uncomment if it's multitest
	while(t--)
	{
		solve();
	}
	
}
