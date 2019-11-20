#include <bits/stdc++.h>

#pragma GCC optimize("O3")

using namespace std;

#define MAXN 505

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

#define SRIRAAMSTER(in, out) \
	freopen(in, "r", stdin); \
	freopen(out, "w", stdout);

#define long long long

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

#define N 3

int n;
char gr[200][200];
pii arr[3];
int main()
{
    DUEHOANG;
    FOR(i, N)
    {
        cin >> arr[i].f >> arr[i].s;
        n += arr[i].f * arr[i].s;
    }
    int m = n;
    n = sqrt(n);
    if(n*n != m)
    {
        cout << -1 << endl;
        return 0;
    }
    // now we want to find the rectangle with side n and put it on top
    int top = 0, left = 0;
    int one = -1, two = -1;
    FOR(i, N)
    {
        if(arr[i].f == n)
        {
            top = arr[i].s;
            one = i;
            break;
        } else if(arr[i].s == n)
        {
            one = i;
            top = arr[i].f;
            break;
        }
    }
    // if none fit then return 0
    if(one == -1)
    {
        cout << -1 << endl;
        return 0;
    }
    int otop = top;
    FOR(i, otop) FOR(j, n) gr[i][j] = ('A' + one);
    FOR(i, N)
    {
        if(i==one)continue;
        if(arr[i].f == n)
        {
            top += arr[i].s;
            two = i;
            break;
        } else if(arr[i].s == n)
        {
            top += arr[i].f;
            two = i;
            break;
        }

        if(arr[i].f == n-top)
        {
            left = arr[i].s;
            two = i;
            break;
        } else if(arr[i].s == n-top)
        {
            left = arr[i].f;
            two = i;
            break;
        }
    }
    if(two == -1) 
    {
        cout << -1 << endl;
        return 0;
    }
    int three = -1;
    FOR(i, N)
    {
        if(i != one && i != two) three = i;
    }
    if(left)
    {
        for(int i = otop; i < n; i++)
        {
            FOR(j, left)
            {
                gr[i][j] = 'A'+two;
            }
            for(int j = left; j < n; j++)
            {
                gr[i][j] = 'A'+three;
            }
        }
    } else 
    {
        for(int i = otop; i < top; i++)
        {
            FOR(j, n)
            {
                gr[i][j] = 'A'+two;
            }
        }
        for(int i = top; i < n; i++)
        {
            FOR(j, n)
            {
                gr[i][j] = 'A'+three;
            }
        }
    }
    cout << n << endl;
    FOR(i, n)
    {
        FOR(j,n) cout << gr[i][j];
        cout << endl;
    }
}