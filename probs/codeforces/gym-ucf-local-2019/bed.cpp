#include <bits/stdc++.h>

using namespace std;

#define PI atan2(1.0,1.0) * 4.0

double dtor(double d)
{
    return d*PI/180.0;
}

int main()
{
    double n,m,h,x,y,a;
    cin >> m >> n >> h >> x >> y >> a;
    y=m-y;
    a = dtor(a);
    // cout << PI << endl;
    double p = x + h*cos(a);
    double q = y - h*sin(a);
    // cout << p << " " << q << endl;
    cout << ((p > n || q > m) ? "NO" : "YES") << endl;
}