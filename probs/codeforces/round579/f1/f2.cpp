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
typedef vector<pii> vii;
typedef priority_queue<int> pqi;
typedef stack<int> sti;
typedef queue<int> qi;
typedef deque<int> di;
typedef map<int, int> mii;
#define x first
#define y second
 
int n, r, dp[61005];
 
bool comp(pii a, pii b)
{
    return max(a.x, -a.y) + a.y < max(b.x, -b.y) + b.y;
}
 
int main()
{
    cin >> n >> r;
    vii pos,neg;
    FOR(i, n)
    {
        int a, b;
        cin >> a >> b;
        if(b>=0) pos.pb({a,b});
        else neg.pb({max(a, -b),b});
    }
    int sz = 0;
    sort(pos.begin(), pos.end());
    for(pii p : pos)
    {
        if(r >= p.x)
        {
            sz++;
            r += p.y;
        } else break;
    }
    sort(neg.begin(), neg.end(), comp);
    reverse(neg.begin(), neg.end());
    // dp[r] = sz;
    FOR(j, neg.size())
    {
        FOR(i, r+1)
        {
            if(neg[j].x <= i && i+neg[j].y >= 0) dp[i+neg[j].y] = max(dp[i]+1, dp[i+neg[j].y]);
            // do nothing or take job
        }
    }
    int m = 0;
    FOR(i, r+1)
    {
        m = max(m, dp[i]);
    }
    cout << sz+m << endl;
}