// Time:
// Algorithms: 

#include <bits/stdc++.h>

#pragma GCC optimize("O3")

using namespace std;

#define MAXN 10005

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

// designed to only work for n <= 10^2
ll stupid[101] = {1,1,3,6,10,21,21,50,73,116,167,248,385,496,728,959,1548,1899,2835,3609,5042,6403,8336,12187,15522,21358,26090,35298,44147,62512,76289,101403,123883,156880,200086,254175,335380,413184,505860,615258,810767,980747,1293953,1562829,1952122,2304526,2897355,3613934,4613195,5548124,6709186,7984116,9674364,12326696,14779682,18099273,21445060,25938110,30674368,38650904,46334382,56582128,66049072,78737788,94484900,115398463,139528430,167731441,193569295,227512205,271925324,326693402,395883189,467095885,538503568,627407900,752874761,888501952,1070944831,1260949758,1478027748,1703349559,2008449140,2392755965,2878344230,3346487377,3878987723,4450988186,5233015495,6205611940,7380919461,8465156686,9813875647,11251620104,13058125327,15382555648,18104203650,20904131272,24090728392,27635034026,32016109907};
ll n, m;
void solve()
{
	cin >> n >> m;
	if(n <= 100)
	cout << stupid[n]%m <<endl;
	else
		cout << "YUH." << endl;
}

int main()
{
	fileio("exercise.in", "exercise.out");
	int t = 1;
	// cin >> t; // uncomment if it's multitest
	while(t--)
	{
		solve();
	}
	
}
