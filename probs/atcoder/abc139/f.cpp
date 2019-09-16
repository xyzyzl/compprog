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

#define ll long long

typedef set<int> si;
typedef vector<int> vi;
typedef pair<ll, ll> pii;
typedef vector<pii> vii;
typedef priority_queue<int> pqi;
typedef stack<int> sti;
typedef queue<int> qi;
typedef deque<int> di;
typedef map<int, int> mii;
#define f first
#define s second
#define EPS 1e-9

int n;
pii psum[MAXN];
pii a[MAXN];

bool ang(pii p, pii q)
{
    return atan2(p.f, p.s) < atan2(q.f, q.s);
}

int main()
{
    cin >> n;
    FOR(i, n)
    {
        cin >> a[i].f >> a[i].s;
    }
    sort(a, a+n, ang);
    // FOR(i, n) cout << a[i].f << " " << a[i].s << " a" << endl;
    
    
    ll ans = 0;
    FOR(i, n)
    {
        ll x = 0;
        ll y = 0;
        FOR(j, n)
        {
            x += a[(i+j)%n].f;
            y += a[(i+j)%n].s;
            // cout << x << " " << y << endl;
            ans = max(ans, x*x+y*y);
        }
    }
    cout << setprecision(25) << fixed << sqrt(ans) << endl;
}