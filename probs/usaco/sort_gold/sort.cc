#include <bits/stdc++.h> // :rage: :deciduous_tree:

#pragma GCC optimize("O3")

using namespace std;

#define MAXN 100005

#define FOR(i, n) for (int i = 0; i < n; i++)
#define FORR(j, i, n) for (int i = j; i < n; i++)
#define FORD(i, n) for (int i = n - 1; i >= 0; i--)
#define FOBIR(i, n) for (int i = 1; i <= n; i++)
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

typedef set<int> si;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef pair<int, pii> iii;
typedef vector<pii> vii;
typedef priority_queue<int> pqi;
typedef stack<int> sti;
typedef queue<int> qi;
typedef deque<int> di;
typedef map<int, int> mii;
#define f first
#define s second

#define bitinc(x) x&-x

#define LEFT(x) 2 * x
#define RIGHT(x) 2 * x + 1

ll n, bit[2 * MAXN];
pii arr[MAXN];

int sum(int ind)
{
	int sm = 0;
	while(ind > 0)
	{
		sm += bit[ind];
		ind -= bitinc(ind);
	}
	return sm;
}
void upd(int ind, int val)
{
	while(ind <= n)
	{
		bit[ind] += val;
		ind += bitinc(ind);
	}
}

int main()
{
    fileio("sort.in", "sort.out");
    int t = 1;
    // cin >> t;
    while(t--)
    {
        cin >> n;
        FOBIR(i, n)
        {
            cin >> arr[arr[i].s = i].f;
        }
        sort(arr+1, arr+n+1);
        int best = 1;
        FOBIR(i, n)
        {
            // cout << "Nurlan Nasip" << endl;
            upd(arr[i].s, 1); // increment for each visited
            best = max(best, i-sum(i)); // find amount unvisited
        }
        cout << best << endl;
    }
}