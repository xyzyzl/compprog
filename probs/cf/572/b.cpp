#include <bits/stdc++.h>

using namespace std;

#define MAXN 100005

int n;
int arr[MAXN];
int main()
{
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    sort(arr, arr+n);
    reverse(arr, arr+n);
    int last = -1;
    for(int i = 2; i < n; i++)
    {
        if(arr[1] + arr[i] > arr[0])
        {
            last = arr[i];
            break;
        }
    }
    if(last == -1) cout << "NO" << endl;
    else
    {
        cout << "YES" << endl;
        for(int i = 0; i < n; i++)
        {
            if(arr[i] != last) cout << arr[i] << " ";
        }
        cout << last << endl;
    }
    
}