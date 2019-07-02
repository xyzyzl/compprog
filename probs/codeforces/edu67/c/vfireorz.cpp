#include <bits/stdc++.h>

using namespace std;

#define MAXN 1005
#define INF (int)(1e9 + 7);
#define FOR(i, n) for (int i = 0; i < n; i++)
#define FORD(i, n) for (int i = n - 1; i >= 0; i--)
#define FOBIR(i, n) for (int i = 1; i <= n; i++)
#define pb push_back
#define mp make_pair
#define endl '\n'
#define DUEHOANG                  \
	ios_base::sync_with_stdio(0); \
	cin.tie();                    \
	cout.tie()

typedef set<int> si;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef pair<int, pii> iii; // remember that iii.f is an integer and that iii.s is a pair
typedef priority_queue<int> pqi;
typedef stack<int> sti;
typedef queue<int> qi;
typedef deque<int> di;
typedef map<int, int> mii;
#define f first
#define s second
typedef vector<pair<int, int>> vii;

int n, m, greed_is_good = 10000000;
int arr[MAXN], brr[MAXN], ww[MAXN];
iii que[MAXN];
int main()
{
	// vfire orz
	DUEHOANG;
	cin >> n >> m;
	FOR(i, m)
		cin >> que[i].f >> que[i].s.f >> que[i].s.s;
	fill(brr, brr+MAXN, -1);
	FOR(i, m)
	{
		if(que[i].f)
		{
			for(int j = que[i].s.f; j < que[i].s.s; j++) brr[j] = 0;
		}
	}
	arr[1] = 2*n;
	for(int i = 2; i <= n; i++)
	{
		arr[i] = arr[i-1] + brr[i-1];
	}
	// NO condition: Some unsorted thing in sorted portion, entirely sorted unsorted portion
	// Let "ww[x]" be the first instance after x such that the sort is broken.
	// If ww[left of unsorted] > ww[right of unsorted] then NO
	// if ww[left of sorted] <= ww[right of sorted] then NO
	ww[n] = n;
	for(int i = n-1; i > 0; i--)
	{
		if(arr[i] > arr[i+1]) ww[i] = i;
		else ww[i] = ww[i+1]; // it's not this one so just see what the next one is like
	}
	FOR(i, m)
	{
		if((ww[que[i].s.f] >= que[i].s.s && que[i].f == 0) || (ww[que[i].s.f] < que[i].s.s && que[i].f == 1))
		{
			cout << "NO" << endl;
			return 0;
		}
	}
	// YES condition: Sorted portions must be sorted, unsorted portions must have something breaking the sort
	cout << "YES" << endl;
	FOBIR(i, n) cout << arr[i] << " ";
}