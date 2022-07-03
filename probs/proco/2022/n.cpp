#include <bits/stdc++.h>

using namespace std;

#define int long long
vector<int> res;

// 0 = D, 1 = R
int gcd(int a, int b, int cur)
{
    if (a == 0 || b == 0)
        return max(a, b);
        
    if (b > a)
        return gcd(b, a, 1 - cur);
        
    for (int i = 0; i < a / b; ++i)
        res.push_back(cur);
        
    return gcd(b, a % b, 1 - cur);
}

signed main()
{
    int i, j;
    cin >> i >> j;
    
    if (gcd(i, j, 0) != 1)
    {
        cout << "IMPOSSIBLE" << endl;
    }
    else
    {
        cout << "POSSIBLE" << endl;
        // minus 1 bc 1 1 ==> 1 0 should not be counted
        for (int i = 0; i < (int)res.size() - 1; ++i)
        {
            if (res[i] == 1)
                cout << 'R'<< endl;
            else
                cout << 'D'<< endl;
        }
    }
    return 0;
}
