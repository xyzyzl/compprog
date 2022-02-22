#include <bits/stdc++.h>

using namespace std;

using pii = pair<int,int>;
#define f first
#define s second

void solve()
{
    int n, m; cin >> n >> m;
    map<int,int> cnt;
    vector<int> a(n);
    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
        cnt[a[i]]++;
    }
    vector<pii> p;
    for(int i = 0; i < m; i++)
    {
        int a, b; cin >> a >> b;
        p.push_back({a,b});
        p.push_back({b,a});
    }
    sort(p.begin(), p.end());
    vector<vector<int>> occ(n); // all values with cnt of i
    for(auto &[x, c] : cnt)
    {
        occ[c].push_back(x);
    }
    for(auto &v : occ)
    {
        reverse(v.begin(), v.end());
    }
    long long ans = 0;
    for(int cx = 1; cx < n; cx++)
    {
        for(int x : occ[cx])
        {
            for(int cy = 1; cy <= cx; cy++)
            {
                for(auto y : occ[cy])
                {
                    if(x != y && !binary_search(p.begin(), p.end(), pii{x,y}))
                    {
                        ans = max(ans, 1ll*(cx+cy)*(x+y));
                        break;
                    }
                }
            }
        }
    }
    cout << ans << '\n';
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t; cin >> t;
    while(t--)
    {
        solve();
    }
}