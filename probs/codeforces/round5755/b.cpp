// 10:32

#include <bits/stdc++.h>

using namespace std;

#define int long long

int q, n, k;
vector<int> v;
signed main()
{
    cin >> q;
    for(int i = 0; i < q; i++)
    {
        v.clear();
        cin >> n >> k;
        for(int i = 0; i < n; i++)
        {
            int a;
            cin >> a;
            if(a%2) v.push_back(i+1);
        }
        if(v.size() < k)
        {
            cout << "NO" << endl;
        } else if(v.size() % 2 != k % 2)
        {
            cout << "NO" << endl;
        } else 
        {
            cout << "YES" << endl;
            for(int i = 0; i < k-1; i++)
            {
                cout << v[i] << " ";
            }
            cout << n << endl;
        }
    }
}