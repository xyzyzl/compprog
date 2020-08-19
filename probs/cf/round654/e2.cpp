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

int n;
ll p;
ll a[MAXN];
ll m;
void read()
{
	cin >> n >> p;
	FOR(i, n) 
	{
		cin >> a[i];
		m = max(m, a[i]);
	}
	sort(a, a+n);
}

int mod(int a)
{
	if(a % p >= 0) return a % p;
	a = (-a) % p;
	return (p-a)%p;
}

ll b[MAXN*2];
int freq[MAXN];
void solve()
{
	FOR(i, n) b[max(0ll, a[i]-(m-n))]++;
	F1R(i, MAXN*2-2) b[i] += b[i-1];
	FOR(i, n) freq[mod(i+(m-n) - b[i])]++;
	vi best;
	FORR(m-n, i, m+1)
	{
		int x = mod(i);
		if(freq[x] == 0) best.pb(i);
		freq[mod(i  -  b[ i-(m-n) ])]--;
		freq[mod(i+n - b[i+n-(m-n)])]++;
	}
	cout << best.size() << endl;
	for(int x : best) cout << x << " ";
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
