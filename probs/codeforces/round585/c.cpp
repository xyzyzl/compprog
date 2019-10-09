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

int n; // корки бучек
vi ab, ba;
vii out;
string a, b;
int main()
{
    cin >> n >> a >> b;
    FOR(i, n)
    {
        if(a[i] == 'a' && b[i] == 'b') ab.pb(i+1);
        else if(a[i] == 'b' && b[i] == 'a') ba.pb(i+1);
    }
    if(ab.size() % 2 != ba.size() % 2)
    {
        cout << -1 << endl;
        return 0;
    }
    // for(int i : ab) cout << i << endl;
    // for(int i : ba) cout << i << endl;
    for(int i = 0; i+1 < ab.size(); i+=2)
    {
        out.pb(mp(ab[i], ab[i+1]));
    }
    for(int i = 0; i+1 < ba.size(); i+=2)
    {
        out.pb(mp(ba[i], ba[i+1]));
    }
    if(ab.size() % 2 == 1)
    {
        out.pb(mp(ab[ab.size()-1], ab[ab.size()-1]));
        out.pb(mp(ab[ab.size()-1], ba[ba.size()-1]));
    }
    cout << out.size() << endl;
    for(pii p : out)
    {
        cout << p.f << " " << p.s << endl;
    }
}