// TIME: 36:35
#include <bits/stdc++.h>

using namespace std;

int n, a[200005], b[200005];
pair<int, int> c[200005];
map<pair<int, int> , int> m;
int main()
{
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> a[i];
    for(int i = 0; i < n; i++)
        cin >> b[i];
    int extra = 0;
    for(int i = 0; i < n; i++)
    {
        if(a[i] == 0)
        {
            if(a[i] == 0 && b[i] == 0)
                extra++;
            continue;
        }
        if(a[i] < 0)
        {
            a[i] *= -1;
            b[i] *= -1;
        } else if(a[i] == 0)
        {
            if(b[i] < 0)
            {
                a[i] *= -1;
                b[i] *= -1;
            }
        }
        int fact = __gcd(abs(a[i]), abs(b[i]));
        c[i] = make_pair(b[i]/fact, a[i]/fact);
        m[c[i]]++;
    }
    int mx = 0;
    for(int i = 0; i < n; i++)
        mx = max(mx, m[c[i]]);
    cout << mx+extra << endl;
}