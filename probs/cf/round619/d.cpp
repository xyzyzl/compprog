// Time:
// Algorithms: 

#include <bits/stdc++.h>

#pragma GCC optimize("O3")

using namespace std;

#define MAXN 1000005

#define FOR(i, n) for (int i = 0; i < n; i++)
#define FORR(j, i, n) for (int i = j; i < n; i++)
#define FORD(i, n) for (int i = n - 1; i >= 0; i--)
#define FOBIR(i, n) for (int i = 1; i <= n; i++)
#define FOBIRD(i, n) for (int i = n; i >= 1; i--)
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
#define INF (1e9*1)+5

typedef set<int> si;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef pair<int, pii> iii;
typedef vector<pii> vii;
typedef vector<iii> viii;
typedef priority_queue<int> pqi;
typedef stack<int> sti;
typedef queue<int> qi;
typedef deque<int> di;
typedef map<int, int> mii;
#define f first
#define s second

#define LEFT(x) 2 * x
#define RIGHT(x) 2 * x + 1

#define bitinc(x) x&-x

const int MAX(int &a, int b)
{
    return a = max(a, b); 
}
const int MIN(int &a, int b)
{
    return a = min(a, b); 
}

void print(vector<pair<int, string> > v)
{
    int w = v.size();
    for(auto x : v)
    {
        if(!x.f) --w;
    }
    cout << w << endl;
    for(auto x : v)
    {
        if(!x.f) continue;
        cout << x.f << " " << x.s << endl;
    }
}

int n,m,k;
int main()
{
    int t = 1;
    // cin >> t; // uncomment if it's multitest
    while(t--)
    {
        cin >> n >> m >> k;
        if(k > 2*(n*(m-1) + m*(n-1))) 
        {
            cout << "NO" << endl;
            continue;
        }
        vector<pair<int, string> > v;
        cout << "YES" << endl;
        if(k >= m-1)
        {
            k -= m-1;
            v.pb(mp(m-1, "R"));
            // cout << m-1 << " R" << endl;
            if(k >= m-1)
            {
                k -= m-1;
                v.pb(mp(m-1, "L"));
                // cout << m-1 << " L" << endl;
            } else 
            {
                v.pb(mp(k, "L"));
                // cout << k << " L" << endl;
                k=0;
                print(v);
                return 0;
            }
        } else 
        {
            v.pb(mp(k, "R"));
            // cout << k << " R" << endl;
            k=0;
            print(v);
            return 0;
        }
        int ct = 0;
        while(ct < n-1)
        {
            ++ct;
            if(!k)
            {
                print(v);
                return 0;
            }
            v.pb(mp(1, "D"));
            // cout << "1 D" << endl;
            --k;
            // cout << k << endl;
            if(!k)
            {
                print(v);
                return 0;
            }
            if(k >= m-1)
            {
                v.pb(mp(m-1, "R"));
                // cout << m-1 << " R" << endl;
                k -= m-1;
            } else 
            {
                v.pb(mp(k, "R"));
                print(v);
                // cout << k << " R" << endl;
                return 0;
            }
            if(k >= 3*(m-1))
            {
                v.pb(mp(m-1, "UDL"));
                k -= 3*(m-1);
                continue;
            }
            FOR(i, m-1)
            {
                if(!k)
                {
                    print(v);
                    return 0;
                }
                if(k >= 3)
                {
                    k -= 3;
                    v.pb(mp(1, "UDL"));
                    continue;
                }
                v.pb(mp(1, "U"));
                // cout << "1 U" << endl;
                --k;
                if(!k)
                {
                    print(v);
                    return 0;
                }
            
                v.pb(mp(1, "D"));
                // cout << "1 D" << endl;
                --k;
                if(!k)
                {
                    print(v);
                    return 0;
                }
            
                v.pb(mp(1, "L"));
                // cout << "1 L" << endl;
                --k;
                if(!k)
                {
                    print(v);
                    return 0;
                }
            }
            // k -= 1+2*(m-1)+2*(m-1);
            // cout << "umm" << endl;
        }
        if(k)
        {
            v.pb(mp(k, "U"));
        }
        print(v);

    }
    
}