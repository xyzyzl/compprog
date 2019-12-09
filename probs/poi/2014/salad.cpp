#include <bits/stdc++.h> // :rage: :deciduous_tree:

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

#define LEFT(x) 2 * x
#define RIGHT(x) 2 * x + 1

#define bitinc(x) x&-x

int n, arr[MAXN],psum[MAXN];
int main()
{
    int t = 1;
    // cin >> t;
    while(t--)
    {
        cin >> n;
        FOBIR(i, n)
        {
            char c;
            cin >> c;
            if(c == 'j') arr[i]=1;
            else arr[i] = -1;
        }
        int ans = 0;
        FOR(moo, 2)
        {
            memset(psum, 0, sizeof(psum));
            FOBIR(i, n) psum[i] = psum[i-1] + arr[i];
            int m = INT_MIN;
            FOBIRD(i, n)
            {
                // i is the endpoint
                int lo = 1;
                int hi = i;
                while(lo + 1 < hi)
                {
                    int mid = (lo+hi)/2;
                    if(psum[i] - psum[mid-1] >= 0) lo = mid;
                    else hi = mid;
                }  
                m = max(m, i-lo);
            }
            ans = max(ans, m);
            reverse(arr, arr+n);
        }
        cout << ans << endl;
    }
}