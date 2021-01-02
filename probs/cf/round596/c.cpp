
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

#define mrduehoang(in, out) \
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

int n,p;
int main()
{
    DUEHOANG;
    cin >> n >> p;
    FOBIR(i,31)
    {
        // check if:
        // n-xp has <=x ones and must be >=x.
        int m = n-i*p, ones=0;
        if(m < i)
        {
            cout << -1 << endl;
            return 0;
        }
        while(m != 0)
        {
            if(m%2) ones++;
            m/=2;
        }
        if(ones > i)
        {
            continue;
        }
        // otherwise i is the best!
        cout << i << endl;
        return 0;
    }
    cout << -1 << endl;
    return 0;
}