// Time:
// Algorithms:

#include <bits/stdc++.h>

#pragma GCC optimize("O3")

using namespace std;

#define MAXN 200005

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

int n, k;
bool arr[MAXN];
void read()
{
	cin >> n >> k;
	FOR(i, n)
	{
		char c;
		cin >> c;
		arr[i] = c - '0';
	}
}

vi d;
vi l, r;
void solve()
{
	d.clear();
	l.clear();
	r.clear();
	int last_1 = -1;
	FOR(i, n)
	{
		if(arr[i])
		{
			l.pb(last_1 == -1);
			r.pb(0);
			d.pb(i - last_1 - 1);
			last_1 = i;
		}
	}

	l.pb(last_1 == -1);
	r.pb(1);
	d.pb(n-last_1-1);

	int m = d.size();
	int ans = 0;
	/*
	FOR(i, m)
	{
		cout << l[i] << " ";
	}
	cout << endl;
	FOR(i, m)
	{
		cout << r[i] << " ";
	}
	cout << endl;
	FOR(i, m)
	{
		cout << d[i] << " ";
	}
	cout << endl;
	*/
	FOR(i, m)
	{
		int to_div = d[i] - 2*k;
		if(l[i]) to_div += k;
		if(r[i]) to_div += k;
		to_div = max(to_div, 0);
		ans += (to_div+k) / (k+1);
	}
	cout << ans << endl;
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
