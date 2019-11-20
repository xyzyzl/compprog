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

int n, bit[2*MAXN];
pii arr[MAXN];

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
    fileio("bphoto.in", "bphoto.out");
    DUEHOANG;
    cin >> n;
    FOR(i, n)
    {
        cin >> arr[i].f;
        arr[i].s=i;
    }
    sort(arr, arr+n);
    reverse(arr, arr+n);
    int ct = 0;
    FOR(i, n)
    {
        // there must be i cows taller.
        // either they're on the left or the right.
        // if they're on the left then they will be covered by bit up to arr[i].f
        int l = sum(arr[i].s+1);
        int r = i-l;
        if(min(l,r)*2 < max(l,r))
        {
            ct++;
        }
        upd(arr[i].s+1, 1);
    }
    cout << ct << endl;
}