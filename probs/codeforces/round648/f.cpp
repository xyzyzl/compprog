// Time: 1:20
// Algorithms: well literally just common sense. for some reason it TLE'd because i unnecessarily sorted things (constant factor ...!!!!)
// overall algo *should* be O(n lg n) but constant factor may cause it to go over.

// things to check for: literally that (i, n-i-1) pair is kept intact + middle element (for odd n).

#include <bits/stdc++.h>

#pragma GCC optimize("O3")

using namespace std;

#define MAXN 505

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

int n, a[MAXN], b[MAXN];
void read()
{
	cin >> n;
	FOR(i, n)
	{
		cin >> a[i];
	}
	FOR(i, n)
	{
		cin >> b[i];
	}
}

void solve()
{
	if(n%2 == 1 && a[n/2] != b[n/2])
	{
		cout << "no" << endl;
		return;
	}
	map<pii, int> pairs;
	FOR(i, n/2)
	{
		int j = n-i-1;
		pairs[mp(min(a[i], a[j]), max(a[i], a[j]))]++;
	}
	FOR(i, n/2)
	{
		int j = n-i-1;
		if(0 >= pairs[mp(min(b[i], b[j]), max(b[i], b[j]))]--)
		{
			cout << "no" << endl;
			return;
		}
	}
	cout << "yes" << endl;
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
