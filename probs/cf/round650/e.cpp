// Time: too long
// Algorithms: this question was actually quite simple but i had just overcomplicated it
// it's obvious that we need to find the number of occurrences of each character.
// then we just make cyclic groups i -> i+k -> etc mod m for all m
// note that every cyclic group must be covered by one letter -- if there aren't
// enough letters, Too bad! and you just go on to the next smaller index

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

int n, k;
vi freq;
void read()
{
	cin >> n >> k;
	freq.clear();
	freq.resize(26);
	FOR(i, n)
	{
		char c;
		cin >> c;
		freq[c - 'a']++;
	}
	sort(freq.begin(), freq.end());
}

void solve()
{
	int ans;
	F1RD(m, n)
	{
		ans = m;
		vi vis(m);
		vi cyc_groups_sizes;
		FOR(i, m)
		{
			// generate cyclic groups
			if(vis[i]) continue; // if it's alr in a group don't put it in one lol
			cyc_groups_sizes.pb(1);
			vis[i] = 1;
			int j = (i + k) % m;
			while(!vis[j])
			{
				vis[j] = 1;
				cyc_groups_sizes.back()++;
				j = (j + k) % m;
			}
		}
		vi _freq(freq);
		bool brk = 1;
		while(!cyc_groups_sizes.empty())
		{
			if(_freq.back() < cyc_groups_sizes.back())
			{
				brk = 0;
				break;
			}
			_freq.back() -= cyc_groups_sizes.back();
			cyc_groups_sizes.pop_back();
			sort(_freq.begin(), _freq.end());
		}
		if(brk) break;
	}
	cout << ans << endl;
}

int main()
{
	DUEHOANG;
	int t = 1;
	cin >> t; // uncomment if it's multitest
	while(t--)
	{
		read();
		solve();
	}

}
