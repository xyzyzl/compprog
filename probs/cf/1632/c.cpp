#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int a, b; cin >> a >> b;
    // either run add a until you get b
    // or run add b and then run a = a|b
    int p1 = b-a;
    // if we were to do the second, then the amount that b will be less than a'=a|b is
    // going to be the number of bit positions where a_x = 1, b_x = 0
    // but we can minimize this further, depending on a and b. we can add buffer to a and b 
    int p2 = INT_MAX;
    for(int ap = a; ap < b; ap++)
    {
        int bp = 0;
        for(int i = floor(log2(b)); i >= 0; i--)
        {
            int ai = (1 & ap >> i);
            int bi = (1 & b >> i);
            if(ai == 1 && bi == 1)
                bp += (1 << i);
            else if(ai == 0 && bi == 1)
                bp += (1 << i);
            else if(ai == 1 && bi == 0)
            {
                bp += (1 << i);
                break; // don't even want to consider the values after
                // because it's minimal to just zero out all of them
            }
        }
        p2 = min(p2, (ap|bp)+ap-a-b+1);
    }
    cout << min(p1, p2) << endl;
}

int main()
{
    int t; cin >> t;
    while(t--)
    {
        solve();
    }
}