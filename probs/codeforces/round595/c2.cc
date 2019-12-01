// turkmenbashy be like https://www.niyazovlawgroup.com/

#include <bits/stdc++.h>

#pragma GCC optimize("O3")

using namespace std;

#define int long long

int q;
long long n;
int po(int b, int e)
{
    // linear is fine here
    int ans = 1;
    for(int i = 0; i < e; i++)
    {
        ans *= b;
    }
    return ans;
}
signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> q;
    while (q--)
    {
        cin >> n;
        vector<int> d; // each digit
        int m = n;
        while (m != 0)
        {
            d.push_back(m % 3);
            m /= 3;
        }
        d.push_back(0);
        reverse(d.begin(), d.end());
        int f2 = -1;
        for (int i = 0; i < d.size(); i++)
        {
            if (d[i] == 2)
            {
                f2 = i;
                break;
            }
        }
        if (f2 != -1)
        {
            int l0 = -1;
            for (int i = f2; i >= 0; i--)
            {
                if (d[i] == 0)
                {
                    l0 = i;
                    break;
                }
            }
            d[l0] = 1;
            for (int i = l0 + 1; i < d.size(); i++)
            {
                d[i] = 0;
            }
        }
        reverse(d.begin(), d.end());
        int ans = 0;
        for(int i = 0; i < d.size(); i++)
        {
            ans += pow(3,i) * d[i];
        }
        cout << ans << endl;
    }
}