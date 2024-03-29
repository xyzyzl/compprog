// Time:
// Algorithms: 

#include <bits/stdc++.h>

#pragma GCC optimize("O3")

using namespace std;

#define MAXN 50005

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

int n, bit[(1 << 17)];
pii arr[MAXN];
const int BIG = (1 << 17);

/* 
 * Issue was with BIT 
 */
int sum(int ind)
{
	int sm = 0;
	for(int i = ind-1; ind != 0; i &= i-1)
	{
		sm += bit[i];
		if(!i) break;
	}
	return sm;
}
void upd(int ind, int val)
{
	for(int i = ind | BIG; i < 2 * BIG; i += bitinc(i))
	{
		bit[i ^ BIG] += val;
	}
}

int main()
{
	fileio("circlecross.in", "circlecross.out");
    int t = 1;
    // cin >> t; // uncomment if it's multitest
    while(t--)
    {
		cin >> n;
		FOR(i, n)
		{
			arr[i].f = arr[i].s = -1;
		}
		FOR(i, 2*n)
		{
			int w;
			cin >> w;
			--w;
			if(arr[w].f == -1) arr[w].f = i;
			else arr[w].s = i;
		}
		// now all of the arr[i] are in place
		sort(arr, arr+n);
		int ans = 0;
		FOR(i, n)
		{
			ans += (sum(arr[i].s) - sum(arr[i].f)); // number of endpoints
			// up to 2nd index - # endpoints up to 1st index
			upd(arr[i].s, 1);
			// cout << sum(arr[i].s) << endl;
		}
		cout << ans << endl;
    }
    
}
