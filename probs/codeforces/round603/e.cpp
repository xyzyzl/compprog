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

#define fileio(in, out)      \
    freopen(in, "r", stdin); \
    freopen(out, "w", stdout);

#define ll long long

typedef set<int> si;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef pair<int, pii> iii;
typedef vector<pii> vii;
typedef priority_queue<int> pqi;
typedef stack<int> sti;
typedef queue<int> qi;
typedef deque<int> di;
typedef map<int, int> mii;
#define f first
#define s second

#define LEFT(x) 2*x
#define RIGHT(x) 2*x+1

const int sz = 1 << 20;

iii st[2*sz];
int n;

iii next(iii a, iii b)
{
    int bsum = a.f + b.f;
    int nmin = min(a.s.f, a.f + b.s.f);
    int nmax = max(a.s.s, a.f + b.s.s);
    return mp(bsum, mp(nmin, nmax));
}

void upd(int x, int value)
{
    x += sz;
    st[x] = mp(value, mp(value, value));
    while(x > 1)
    {
        x /= 2;
        st[x] = next(st[LEFT(x)], st[RIGHT(x)]); // range bracket thing query
    }
}

int main()
{
    DUEHOANG;
    cin >> n;
    int x = 0;
    string s;
    cin >> s;
    FOR(i, n)
    {
        char c = s[i];
        if(c == 'L')
        {
            x = max(0, x-1);
        } else if(c == 'R')
        {
            x++;
        } else if(c == '(')
        {
            upd(x, 1);
        } else if(c == ')')
        {
            upd(x, -1);
        } else upd(x, 0);
        if(st[1].f > 0 || st[1].s.f < 0) cout << -1 << " ";
        else cout << st[1].s.s << " ";
    }
}