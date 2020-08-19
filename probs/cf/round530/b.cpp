#include <bits/stdc++.h>

using namespace std;

int a;
int main()
{
    cin >> a;
    double d = sqrt(a);
    double d1 = ceil(d), d2 = ceil(a/d1);
    cout << (int)(d1+d2);
}