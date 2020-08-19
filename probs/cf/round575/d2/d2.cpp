// TIME: 27:56

#include <bits/stdc++.h>
 
using namespace std;

#define MAXN 200005

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

int n, k, a[MAXN], inc[MAXN];
int main()
{
    int qqqq;
    cin >> qqqq;
    while(qqqq--)
    {
        cin >> n >> k;
        FOR(i, n)
        {
            char c;
            cin >> c;
            if(c == 'R') a[i] = 0;
            else if(c == 'G') a[i] = 1;
            else a[i] = 2;
        }
        int ans = INT_MAX;
        FOR(off, 3)
        {
            fill(inc, inc+n, 0);
            FOR(i, n)
            {
                if(a[i] != (i+off)%3) inc[i]=1;
                // cout << inc[i] << " ";
            }
            int cur = 0;
            FOR(i, k)
            {
                if(inc[i]) cur++;
            }
            FOR(i, n-k)
            {
                ans = min(ans, cur);
                cur -= inc[i];
                cur += inc[i+k];
            }
            ans = min(ans, cur);
        }
        cout << ans << endl;
    }
}