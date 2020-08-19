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

int main()
{
    int t = 1;
    cin >> t; // uncomment if it's multitest
    while(t--)
    {
        int n;
        cin >> n;
        string q;
        cin >> q;
        int dec = 1;
        FOR(i, n-1)
        {
            if(q[i] == '>')
            {
                dec++;
            }
        }
        vi arr(n);
        arr[0] = dec;
        int lt = 0;
        int g = n;
        FOR(i, n)
        {
            if(i == n-1 || q[i] == '>')
            {
                for(int j = i; j >= lt; j--)
                {
                    arr[j] = g--;
                }
                lt = i+1;
            }
        }
        FOR(i, n)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
        fill(arr.begin(), arr.end(), 0);
        g=1;
        lt = 0;
        FOR(i, n)
        {
            if(i == n-1 || q[i] == '<')
            {
                for(int j = i; j >= lt; j--)
                {
                    arr[j] = g++;
                }
                lt = i+1;
            }
        }
        FOR(i, n)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
    
}