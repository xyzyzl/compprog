#include <bits/stdc++.h>
 
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
typedef priority_queue<int> pqi;
typedef stack<int> sti;
typedef queue<int> qi;
typedef deque<int> di;
typedef map<int, int> mii;
#define f first
#define s second

long long n, m, k;
long long gcd(long long a, long long b)
{
    if(a==0) return b;
    return gcd(b%a, a);
}
int main()
{
    cin >> n >> m >> k;
    long long d = gcd(n, m);
    FOR(i, k)
    {
        long long a1, a2, b1, b2;
        cin >> a1 >> a2 >> b1 >> b2;
        a2--;
        b2--;
        long long v1, v2;
        if(a1 == 1) v1 = n;
        else v1 = m;
        if(b1 == 1) v2 = n;
        else v2 = m;
        long long a = a2/(v1/d);
        long long b = b2/(v2/d);
        // cout << a << " " << b << endl;
        if(a == b) cout << "YES\n";
        else cout << "NO\n";
    }
}