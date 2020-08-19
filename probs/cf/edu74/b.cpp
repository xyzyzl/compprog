#include <bits/stdc++.h>

#pragma GCC optimize("O3")

using namespace std;

#define MAXN 300005
#define MOD 998244353

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

#define JaydenXia(in, out) \
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
#define x first
#define y second

int main()
{
	int q;
	cin >> q;
	while(q--)
	{
		int n, r;
		cin >> n >> r;
		si s;
		FOR(i,n)
		{
			int a;
			cin>>a;
			s.insert(a);
		}
		int cnt = 0;
		int shift = 0;
		while(!s.empty())
		{
			s.erase(prev(s.end()));
			shift += r;
			s.erase(s.begin(), s.upper_bound(shift));
			cnt++;
		}
		cout << cnt << endl;
	}
}