#include <bits/stdc++.h>

using namespace std;

int a, b;
int main()
{
    cin >> a >> b;
    int n = 0, c = 1;
    while(c < b)
    {
        c += (a-1);
        n++;
    }
    cout << n << endl;
}