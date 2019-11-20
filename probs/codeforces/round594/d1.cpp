#include <bits/stdc++.h>

#pragma GCC optimize("O3")

using namespace std;

#define MAXN 505

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

#define GURBANGULY(in, out) \
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

int n, b, mb, bal[MAXN];
string s;
int main()
{
    DUEHOANG;
    cin >> n >> s;
    FOR(i, n)
    {
        bal[i] = (s[i] == '(' ? 1 : -1);
    }
    FOR(i, n)
    {
        b += bal[i];
    }
    if(b != 0)
    {
        cout << 0 << endl << 1 << " " << 1 << endl;
        return 0;
    }
    int bi = 1, bj = 1, mx = 0;
    FOR(i, n)
    {
        FOR(j, i)
        {
            int _mb = 0;
            int c = 0;
            FOR(ind, n)
            {
                int r = ind;
                if(ind == i) r = j;
                else if(ind == j) r = i;
                c += bal[r];
                _mb = min(_mb, c);
            }
            int ct = 0;
            FORD(ind, n)
            {
                if(_mb == 0) ct++;
                int r;
                r = ind;
                if(ind == j) r = i;
                else if(ind == i) r = j;
                _mb += bal[r];
                // if(i == 7 && j == 6) cout << _mb << endl;
            }
            if(ct > mx)
            {
                mx = ct;
                bi = i+1;
                bj = j+1;
            }
        }
    }
    cout << mx << endl << bi << " " << bj << endl;
}