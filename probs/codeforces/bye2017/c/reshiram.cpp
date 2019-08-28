#include <bits/stdc++.h>

#pragma GCC optimize ("O3")
 
using namespace std;
 
#define MAXN 1005
 
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
#define f first
#define s second

int n, r, x[MAXN];
double a[MAXN];
int main()
{
    cin >> n >> r;
    FOR(i, n)
    {
        cin >> x[i];
    }
    FOR(i, n)
    {
        if(!i)
        {
            a[i] = r;
            continue;
        }
        FORD(j, i)
        {
            if(abs(x[i]-x[j]) > 2*r)
            {
                a[i] = max(a[i], (double)(r));
            } else 
            {
                a[i] = max(a[i], a[j] + sqrt(4*r*r-(x[i]-x[j])*(x[i]-x[j])));
            }
        }
    }
    FOR(i, n)
    {
        cout << setprecision(15) << fixed << a[i] << endl;
    }
}