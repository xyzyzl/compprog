#include <bits/stdc++.h>
 
using namespace std;

#define MAXN 201

#define FOR(i, n) for(int i = 0; i < n; i++)
#define FORD(i, n) for(int i = n-1; i >= 0; i--)
#define FOBIR(i, n) for(int i = 1; i <= n; i++)
#define pb push_back
#define mp make_pair
#define endl '\n'
#define DUEHOANG ios_base::sync_with_stdio(0); cin.tie(); cout.tie()
 
typedef set<int> si;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef vector<pii> vii;
typedef priority_queue<int> pqi;
typedef stack<int> sti;
typedef queue<int> qi;
typedef deque<int> di;
typedef map<int, int> mii;
#define x first
#define y second

int n, r;

bool comp(pii a, pii b)
{
    return max(a.x, -a.y) + a.y > max(b.x, -b.y) + b.y;
}

int main()
{
    cin >> r >> n;
    vii pos, neg;
    FOR(i, r)
    {
        int a, b;
        cin >> a >> b;
        if(b >= 0) pos.pb(mp(a, b));
        else neg.pb(mp(a, b));
    }
    sort(pos.begin(), pos.end());
    for(pii p : pos)
    {
        if(n < p.x)
        {
            cout << "NO" << endl;
            return 0;
        }
        n += p.y;
    }
    sort(neg.begin(), neg.end(), comp);
    for(pii p : neg)
    {
        if(n < p.x || n < 0)
        {
            cout << "NO" << endl;
            return 0;
        }
        n += p.y;
    }
    cout << (n>=0 ? "YES" : "NO") << endl;
}