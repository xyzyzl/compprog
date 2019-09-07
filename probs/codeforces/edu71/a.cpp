#include <bits/stdc++.h>

using namespace std;

int b,p,f;
int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        cin >> b >> p >> f;
        int h,c;
        cin >> h >> c;
        if(c > h)
        {
            int temp = c;
            c=h;
            h=temp;
            temp = p;
            p=f;
            f=temp;
        }
        b/=2;
        if(p>b)
        {
            cout << h*b << endl;
        } else
        {
            int sm = h*p;
            b -= p;
            sm += c*min(b, f);
            cout << sm << endl;
        }
    }
}