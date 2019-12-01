#include <bits/stdc++.h>

using namespace std;

int n,m,k, a[100005], b[100005];
int main()
{
    cin >> n >> m >> k;
    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 0; i < m; i++) cin >> b[i];
    sort(a,a+n);
    reverse(a,a+n);
    sort(b,b+m);
    reverse(b,b+m);

    int g = 0;
    for(int i = 0; i < min(n,m); i++)
    {
        if(a[i] > b[i])
        {
            // cout << a[i] << " " << b[i] << endl;
            g = 1;
            break;
        }
    }
    cout << (g || n > m ? "YES" : "NO") << endl;
}