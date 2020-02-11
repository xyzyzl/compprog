// Time:
// Algorithms: 

#include <bits/stdc++.h>

#pragma GCC optimize("O3")

using namespace std;

#define MAXN 100005
#define MAXLG 35

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

int n, arr[MAXN], expy[MAXN][MAXLG], blah[MAXN], freq[MAXLG], frst[MAXLG];
int main()
{
    int t = 1;
    // cin >> t; // uncomment if it's multitest
    while(t--)
    {
        cin >> n;
        FOR(i, n)
        {
            cin >> arr[i];
        }
        sort(arr, arr+n);
        FOR(i, n)
        {
            int x = arr[i];
            while(x > 0)
            {
                int y = (int) log2(x);
                expy[i][y] = 1;
                freq[y]++;
                frst[y] = i;
                x -= (1 << y);
                blah[i]++;
            }
        }
        int ind = 0;
        FORD(i, MAXLG)
        {
            if(freq[i] == 1)
            {
                ind = frst[i];
                break;
            }
        }
        
        cout << arr[ind] << " ";
        FOR(i, n)
        {
            if(i == ind) continue;
            cout << arr[i] << " ";
        }
        cout << endl;
    }
    
}