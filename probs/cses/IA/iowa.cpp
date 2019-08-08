#include <bits/stdc++.h>

using namespace std;

int n, arr[200005];
int main()
{
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> arr[i];
    long long b=0;
    for(int i = 0; i < n; i++)
    {
        if(arr[i] < arr[i-1])
        {
            b+=(arr[i-1]-arr[i]);
            arr[i] = arr[i-1];
        }
    }
    cout << b;
}