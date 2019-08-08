#include <bits/stdc++.h>

using namespace std;

#define MAXN 200005

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
typedef priority_queue<int> pqi;
typedef stack<int> sti;
typedef queue<int> qi;
typedef deque<int> di;
typedef map<int, int> mii;
#define f first
#define s second

int n, m, k;
vi a1, a2;

int main()
{
	DUEHOANG;
	cin >> n >> m >> k;
	a1.resize(n);
	a2.resize(m);
	FOR(i, n)
	cin >> a1[i];
	FOR(i, m)
	cin >> a2[i];
	// sort(a1.begin(), a1.end());
	sort(a2.begin(), a2.end());
	int c = 0;
	FOR(i, n)
	{
		auto a = lower_bound(a2.begin(), a2.end(), a1[i]);
		auto b = upper_bound(a2.rbegin(), a2.rend(), a1[i], [](int p, int q) { return p >= q; });
		int j = *a;
		if(b != a2.rend())
		{
			if(a == a2.end())
				j = *b;
			else
			{
				if(abs(j-a1[i]) > abs(*b-a1[i]))
					j = *b;
			}
		} else if(a == a2.end()) continue;
		// cout << j << endl;
		if (abs(j - a1[i]) <= k)
		{
			c++;
			if(j == *a)
				a2.erase(a);
			else
				a2.erase(b.base());
		}
		cerr << c << endl;
	}
	cout << c << endl;
}