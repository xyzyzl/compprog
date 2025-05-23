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
        int n;
        cin >> n;
        vi v(n);
        FOR(i, n)
        {
            cin >> v[i];
            if(v[i] == n) v[i] = 0;
        }
        int start = v[0];
        bool a = 1, b = 1;
        FOBIR(i, n-1)
        {
            start++;
            // cout << start;
            start %= n;
            if(v[i] != start)
            {
                a = 0;
                break;
            }
        }
        // cout << " ";
        start = v[0];
        FOBIR(i, n-1)
        {
            start--;
            start = (start+n)%n;
            // cout << start;
            if(v[i] != start)
            {
                b = 0;
                break;
            }
        }
        cout << ((a || b) ? "YES" : "NO") << endl;
    }
}