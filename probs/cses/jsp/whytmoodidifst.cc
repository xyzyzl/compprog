#include <bits/stdc++.h>

using namespace std;

#define int long long

typedef pair<int, pair<int, int> > iii;
#define f first
#define s second

int n, d[100005];
iii g[100005];
int b(int i)
{
    int l = 0, h = i-1;
    while(l <= h)
    {
        int m = (l+h)/2;
        if(g[m].f < g[i].s.s)
        {
            if(g[m+1].f < g[i].s.s) l=m+1;
            else return m;
        } else h=m-1;
    }
    return -1;
}
signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie();
    cout.tie();
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        cin >> g[i].s.s >> g[i].f >> g[i].s.f;
    }
    sort(g, g+n);
    d[0] = g[0].s.f;
    for(int i = 1; i < n; i++)
    {
        // you can add a previous state
        int a = g[i].s.f;
        int c = b(i);
        if(c != -1) a += d[c];

        d[i] = max(a, d[i-1]); // or you could do nothing
    }
    cout << d[n-1] << endl;
}