#include <bits/stdc++.h>

using namespace std;

long long n, k, a[100005], d;
int m;
int main()
{
    cin >> n >> m >> k;
    for(int i = 0; i < m; i++)
    {
        cin >> a[i];
        a[i]--;
    }
    int x = -1, op = 0;
    for(int i = 0; i < m; i++)
    {
        int y = (a[i]-d)/k;
        if(x != y)
        {
            d=i;
            x = (a[i]-d)/k;
            op++;
        }
    }
    cout << op;
}