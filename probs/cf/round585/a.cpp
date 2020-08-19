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

int a1,a2,k1,k2,n;
int main()
{
    cin >> a1 >> a2 >> k1 >> k2 >> n;
    cout << max(n-(k1-1)*a1-(k2-1)*a2, 0) << " ";
    if(k1 > k2)
    {
        int rem = a2*k2;
        int m = n-rem;
        if(m < 0)
        {
            cout << n/k2 << endl;
        } else 
        {
            cout << a2+m/k1 << endl;
        }
    } else 
    {
        int rem = a1*k1;
        int m = n-rem;
        if(m < 0)
        {
            cout << n/k1 << endl;
        } else 
        {
            cout << a1 + m/k2 << endl;
        }
    }
}