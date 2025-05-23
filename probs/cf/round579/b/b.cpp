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
typedef priority_queue<int> pqi;
typedef stack<int> sti;
typedef queue<int> qi;
typedef deque<int> di;
typedef map<int, int> mii;
#define x first
#define y second

int main()
{
    int t=1;
    cin >> t;
    while(t--)
    {
        mii fr;
        int n;
        cin >> n;
        vi v(4*n);
        FOR(i, 4*n)
        {
            cin >> v[i];
            fr[v[i]]++;
        }
        sort(v.begin(), v.end());
        int prod = v[0] * v[4*n-1];
        bool y = 1;
        FOR(i, 2*n)
        {
            if(prod != v[i] * v[4*n-1-i] || fr[v[i]] % 2 || fr[v[4*n-1-i]] % 2)
            {
                y = 0;
                break;
            }
        }
        cout << (y ? "YES" : "NO") << endl;
    }
}