#include <bits/stdc++.h>

using namespace std;

int n, arr[100005];
int main()
{
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    sort(arr, arr+n);
    arr[n-1] = arr[n-1] == 1 ? 2 : 1;
    sort(arr, arr+n);
    for(int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}