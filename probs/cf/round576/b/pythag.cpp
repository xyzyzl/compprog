#include <bits/stdc++.h>

using namespace std;

double h, l;
int main()
{
    cin >> h >> l;
    // (a+h)^2 - a^2 = l^2
    // a^2 + 2ah + h^2 - a^2 = l^2
    // 2ah + h^2 = l^2
    // 2ah = (l^2-h^2)
    // 2a = (l^2-h^2)/h
    // a = (l^2-h^2)/2h
    cout << setprecision(15) << fixed << (l*l-h*h)/(2*h) << endl;
}