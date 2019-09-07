#include <bits/stdc++.h>

using namespace std;

int n, m, bl, w;
int main()
{
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        if(m < a) bl = 0;
        else bl++;
        w = max(w, bl);
        m = a;
    }
    cout << w << endl;
}