
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

int main()
{
    int T;
    cin >> T;
    while(T--)
    {
        long n, m;
        cin >> n >> m;
        long d = n/m;
        long w = m%10;
        long sm = 0;
        FOR(i, 10)
        {
            sm += (i*w)%10;
        }
        // cout << sm << " sm" << endl;
        long fsm = 0;
        FOBIR(i, d%10)
        {
            fsm += (i*w)%10;
        }
        // cout << fsm << " fsm" << endl;
        cout << sm*(d/10) + fsm << endl;
    }
}