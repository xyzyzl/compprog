// Time:  1:28:45 (w/ bathroom break)
// Algorithms: NT

#include <bits/stdc++.h>

#pragma GCC optimize("O3")

using namespace std;

#define MAXN 500005
#define A 10000005

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

int mul(int a, int b, int mod = MOD) { return (ll)a*b%mod; }
int po (int b, int p, int mod = MOD) { return !p?1:mul(po(mul(b,b,mod),p/2,mod),p&1?b:1,mod); }

int n;
int a[MAXN], bad[MAXN];
// ndivs[i] is the number of prime divisors of i
int ndivs[A+5];
// divs[i][j] is the list of i prime divisors of j
int divs[A+5];
int pow_div[MAXN];
void read()
{
	cin >> n;
	FOR(i, n)
	{
		cin >> a[i];
	}
}

void solve()
{
	F1R(i, A)
	{
		ndivs[i] = 0;
	}
	FORR(2, i, A)
		if(!ndivs[i])
			for(int j = i; j <= A; j += i)
			{
				if(!ndivs[j])
				{
					divs[j] = i;
				}
				ndivs[j]++;
			}
	/*
	FOR(i, n)
	{
		cout << divs[a[i]] << endl;
	}
	*/
	FOR(i, n)
	{
		int z = a[i];
		int w = 0;
		while(!(z%divs[a[i]]))
		{
			z /= divs[a[i]];
			++w; // @Aryansh-S
		}
		pow_div[i] = w;
		if(po(divs[a[i]], pow_div[i]) == a[i])
		{
			bad[i] = 1;
		}
	}
	FOR(i, n)
	{
		if(bad[i])
		{
			cout << -1 << " ";
		} else
		{
			cout << po(divs[a[i]], pow_div[i]) << " ";
		}
	}
	cout << endl;
	FOR(i, n)
	{
		if(bad[i])
		{
			cout << -1 << " ";
		} else
		{
			cout << a[i] / po(divs[a[i]], pow_div[i]) << " ";
		}
	}
	cout << endl;
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
