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

long long gcd(long long a, long long b)
{
    if(a == 0) return b;
    return gcd(b%a, a);
}

int main()
{
    int t=1;
    // cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        vector<long long> v(n);
        FOR(i, n)
        {
            cin >> v[i];
        }
        long long res = v[0];
        FOR(i, n)
        {
            res = gcd(res, v[i]);
        }
        long long ct = 0;
        FOBIR(i, sqrt(res))
        {
            if(res%i == 0)
            {
                if(res/i==i) ct++;
                else ct+=2;
            }
        }
        cout << ct << endl;
    }
}