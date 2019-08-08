// time: 14:04

#include <bits/stdc++.h>

using namespace std;

#define END 100000

int T, n, minx, maxx, miny, maxy;
int main()
{
    cin >> T;
    while(T--)
    {
        cin >> n;
        minx = -END;
        maxx = END;
        miny = -END;
        maxy = END;
        for(int i = 0; i < n; i++)
        {
            int x, y;
            cin >> x >> y;
            int a;
            cin >> a;
            if(!a) minx = max(minx, x);
            cin >> a;
            if(!a) maxy = min(maxy, y);
            cin >> a;
            if(!a) maxx = min(maxx, x);
            cin >> a;
            if(!a) miny = max(miny, y);
        }
        if(minx > maxx || miny > maxy) cout << 0 << endl;
        else cout << 1 << " " << maxx << " " << miny << endl;
    }
}