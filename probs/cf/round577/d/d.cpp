#include <bits/stdc++.h>

using namespace std;

#define int long long

typedef pair<int, int> pii;

int n, m, k, q, arr[200005], l[200005], r[200005], dp[200005][4], d[4];
vector<int> v[200005];
int left(int i)
{
    if(v[i].empty()) return 0;
    return v[i][0];
}
int right(int i)
{
    if(v[i].empty()) return 0;
    return v[i].back();
}
signed main()
{
    cin >> n >> m >> k >> q;
    for(int i = 0; i < k; i++)
    {
        int a, b;
        cin >> a >> b;
        v[a].push_back(b);
    }
    for(int i = 0; i < q; i++) cin >> arr[i];
    sort(arr, arr+q);
    for(int i = 1; i <= n; i++) sort(v[i].begin(), v[i].end());
    for(int i = 1; i <= arr[0]; i++) r[i] = arr[0];
    for(int i = arr[0]; i < arr[1]; i++) l[i] = arr[0];
    for(int i = 1; i < q-1; i++)
    {
        for(int j = arr[i-1]; j <= arr[i]; j++) r[j] = arr[i];
        for(int j = arr[i]; j < arr[i+1]; j++) l[j] = arr[i];
    }
    for(int i = arr[q-2]; i <= arr[q-1]; i++) r[i] = arr[q-1];
    for(int i = arr[q-1]; i <= m; i++) l[i] = arr[q-1];
    while(v[n].empty()) n--;
    if(n==1)
    {
        cout << right(1)-1;
        return 0;
    } else if(v[1].empty())
    {
        dp[1][0] = r[1]-1;
        d[0] = r[1];
    } else
    {
        if(l[right(1)] != 0)
        {
            dp[1][0] = right(1)-1+abs(right(1)-l[right(1)]);
            d[0] = l[right(1)];
        }
        if(r[right(1)] != 0)
        {
            dp[1][0] = right(1)-1+abs(right(1)-r[right(1)]);
            d[0] = r[right(1)];
        }
    }
    for(int i = 2; i < n; i++)
    {
        int c[4];
        if(right(i) == 0)
        {
            for(int j = 0; j < 4; j++)
            {
                dp[i][j] = dp[i-1][j] + 1;
            }
            continue;
        }
        c[0] = l[left(i)];
        c[1] = r[left(i)];
        c[2] = l[right(i)];
        c[3] = r[right(i)];
        for(int a = 0; a < 4; a++)
        {
            dp[i][a] = LLONG_MAX;
        }
        for(int j = 0; j < 4; j++)
        {
            if(d[j] != 0) for(int a = 0; a < 4; a++)
            {
                if(c[a] != 0)
                {
                    dp[i][a] = min(dp[i][a], dp[i-1][j]);
                }
            }
        }
    }
}