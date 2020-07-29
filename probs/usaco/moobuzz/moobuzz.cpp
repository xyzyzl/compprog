#include <bits/stdc++.h>

using namespace std;

long long n; // to prevent int overflow
int main()
{
    freopen("moobuzz.in", "r", stdin);
    freopen("moobuzz.out", "w", stdout);
    cin >> n;
    long long arr[8] = {1, 2, 4, 7, 8, 11, 13, 14};
    cout << ((n-1)/8)*15 + arr[(n-1)%8] << endl;
}
