// TIME: 30 minutes

#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        long long n;
        cin >> n;
        int x = 0, y = 0;
        for(long long i = 50000; i >= 2; i--)
        {
            if((i*(i-1))/2 <= n)
            {
                x=i;
                y=n-(i*(i-1))/2;
                break;
            }
        }
        cout<<"133";
        for(int i = 0; i < y; i++) cout << 7;
        for(int i = 2; i < x; i++) cout << 3;
        cout << 7 << endl;
    }
}