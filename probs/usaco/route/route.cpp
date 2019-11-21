#include <bits/stdc++.h>

#pragma GCC optimize ("O3")

#define MAXN 40005
#define MAXE 100005

using namespace std;

int n,m,r;
long long a[MAXN], b[MAXN], da[MAXN], db[MAXN];
pair<int, int> e[MAXE];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    freopen("route.in", "r", stdin);
    freopen("route.out", "w", stdout);
    cin >> n >> m >> r;
    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 0; i < m; i++) cin >> b[i];
    for(int i = 0; i < r; i++) cin >> e[i].first >> e[i].second;

    for(int i = 0; i < n; i++) da[i] = a[i];
    for(int i = 0; i < m; i++) db[i] = b[i];

    sort(e, e+r);
    reverse(e, e+r);
    // now we just find the maximum value leading to each index (or the index itself if larger)
    // this way we know when to add previous values and when to not do so
    for(int i = 0; i < r; i++)
    {
        int f = e[i].first, s = e[i].second;
        --f; // ENSURE ZERO-BASED INDEXING!!!
        --s; // else the question will break !
        long long na = max(da[f], db[s] + a[f]);
        long long nb = max(db[s], da[f] + b[s]);
        da[f] = na;
        db[s] = nb;
    }
    long long obama = 0;
    for(int i = 0; i < n; i++) obama = max(obama, da[i]);
    for(int i = 0; i < m; i++) obama = max(obama, db[i]);
    cout << obama << endl;
}