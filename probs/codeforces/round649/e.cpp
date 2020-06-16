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

int qry(int a, int b)
{
	cout << "? " << a << " " << b << endl;
	cout.flush();
	int ret;
	cin >> ret;
	assert(ret != -1);
	return ret;
}

int n;
int p[2050];
int a[11]; // a[i] has a value of 0 at bit i
void read()
{
	cin >> n;
	fill(a, a+11, -1);
}

int retrieve(int x)
{
	int ret = (1 << 11) - 1;
	FOR(i, 11)
	{
		if(x != a[i]) ret &= qry(x, a[i]);
		else if(ret & (1 << i)) ret ^= (1 << i);
	}
	return ret;
}

void solve()
{
	// use rand to find proper 0-indices
	while(count(a, a+11, -1))
	{
		int x = rand()%n+1;
		int y = rand()%n+1;
		if(x == y) continue;
		int z = qry(x, y);
		FOR(i, 11)
		{
			if(!(z & (1 << i)))
			{
				a[i] = x; // p[x] must be 0 for z to be 0
			}
		}
	}
	// can use these 0-indices to find p[x] from x. but doing that manually would be n lg n, which is
	// too slow!
	int zero = 1, pof = retrieve(1);
	FORR(2, i, n+1)
	{
		if(qry(zero, i) == pof)
		{
			zero = i;
			pof = retrieve(i);
		}
	}
	F1R(i, n)
	{
		if(i != zero) p[i] = qry(i, zero);
	}
	cout << '!';
	F1R(i, n)
	{
		cout << " " << p[i];
	}
	cout << endl;
	cout.flush();
}

int main()
{
	DUEHOANG;
	srand(time(NULL));
	int t = 1;
	// cin >> t; // uncomment if it's multitest
	while(t--)
	{
		read();
		solve();
	}

}
