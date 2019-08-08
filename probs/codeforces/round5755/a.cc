// time: 5:30

#include <bits/stdc++.h>

using namespace std;

int n;
int main()
{
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        long long a, b, c;
        cin >> a >> b >> c;
        long long e = (a+b+c)/2;
        cout << e << endl;
    }
}