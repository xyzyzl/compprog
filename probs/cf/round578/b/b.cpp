// DakDak huuuge orz

#include <bits/stdc++.h>
 
using namespace std;
 
#define MAXN 1005
 
#define int long long
 
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
#define f first
#define s second
 
int t;
signed main()
{
    cin >> t;
    while(t--)
    {
        int k, m, n;
        int arr[105];
        cin >> n >> m >> k;
        // note that it's always the inclines that cause problems
        // on the drops you can only gain blocks
        FOR(i, n)
        {
            cin >> arr[i];
        }
        bool b = 0;
        FOR(i, n-1)
        {
            if(arr[i] < arr[i+1] - k)
            {
                m -= max((arr[i+1] - arr[i]) - k, 0ll);
                if(m < 0)
                {
                    cout << "NO" << endl;
                    b=1;
                    break;
                }
            } else 
            {
                m += arr[i] - max(arr[i+1] - k, 0ll);
            }
        }
        // cout << m << endl;
        if(!b) cout << "YES" << endl;
    }
}