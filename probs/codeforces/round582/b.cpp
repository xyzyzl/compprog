
#include <bits/stdc++.h>

#pragma GCC optimize("O3")

using namespace std;

#define MAXN 105

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
#define f first
#define s second

int n;
int main()
{
	int T;
    cin >> T;
    while(T--)
    {
        cin >> n;
        vii a(n);
        FOR(i, n)
        {
            cin >> a[i].f;
            a[i].s = i;
        }
        sort(a.begin(), a.end());
        int max_value = 0, bad = 0;
        FOR(i, n)
        {
            max_value = max(max_value, a[i].s);
            if(max_value > a[i].s) bad++;
        }
        cout << bad << endl;
    }
}