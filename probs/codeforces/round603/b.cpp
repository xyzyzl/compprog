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
typedef vector<pii> vii;
typedef priority_queue<int> pqi;
typedef stack<int> sti;
typedef queue<int> qi;
typedef deque<int> di;
typedef map<int, int> mii;
#define f first
#define s second

int t;

bool comp(pii a, pii b)
{
    return a.s < b.s;
}

int main()
{
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<string> v(n);
        FOR(i, n)
        {
            cin >> v[i];
        }
        set<char> usable; // as N < 10 this is ok!
        for(char c = '0'; c <= '9'; c++)
        {
            usable.insert(c);
        }
        FOR(i, n)
        {
            if(usable.count(v[i][0]))
            {
                usable.erase(v[i][0]);
            }
        }
        int ch = 0;
        FOR(i, n)
        {
            for(int j = i+1; j < n; j++)
            {
                if(v[i] == v[j])
                {
                    v[i][0] = *usable.begin();
                    usable.erase(usable.begin());
                    ch++;
                }
            }
        }
        cout << ch << endl;
        FOR(i, n) cout << v[i] << endl;
    }
}