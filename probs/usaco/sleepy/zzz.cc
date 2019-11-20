#include <bits/stdc++.h>

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

#define fileio(in, out) \
	freopen(in, "r", stdin); \
	freopen(out, "w", stdout);

#define long long long

typedef set<int> si;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef vector<pii> vii;
typedef priority_queue<int> pqi;
typedef stack<int> sti;
typedef queue<int> qi;
typedef deque<int> di;
typedef map<int, int> mii;
#define f first
#define s second

int n, arr[MAXN], bit[MAXN];

int sum(int ind)
{
	int sm = 0;
	while(ind > 0)
	{
		sm += bit[ind];
		ind -= ind&-ind;
	}
	return sm;
}
void upd(int ind, int val)
{
	while(ind <= n)
	{
		bit[ind] += val;
		ind += ind&-ind;
	}
}

int main()
{
    DUEHOANG;
    fileio("sleepy.in", "sleepy.out");
    cin >> n;
    FOR(i, n) cin >> arr[i];
    // take largest sorted suffix, we only insert things into here
    int len = n;
    vi v;
    FORD(i, n)
    {
        len--;
        v.pb(arr[i]);
        if(i == 0 || arr[i-1] > arr[i]) break;
    }
    for(int ind : v)
    {
        upd(ind, 1);
    }
    cout << len << endl;
    int k = len;
    FOR(i, len)
    {
        k--;
        cout << k + sum(arr[i]) << (i != len-1 ? " " : "");
        upd(arr[i], 1);
    }
    cout << endl;
}