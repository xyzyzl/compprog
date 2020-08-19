#include <bits/stdc++.h>

using namespace std;

int w, h, w1, h1, w2, h2;
int main()
{
    cin >> w >> h >> w1 >> h1 >> w2 >> h2;
    for(int i = h; i >= 0; i--)
    {
        w += i;
        if(i==h1) w = max(0, w-w1);
        if(i==h2) w = max(0, w-w2);
    }
    cout << w << endl;
}