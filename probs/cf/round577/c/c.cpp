#include <bits/stdc++.h>
 
using namespace std;
 
#define int long long
int n, k, arr[200005];
signed main()
{
    cin >> n >> k;
    for(int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    sort(arr, arr+n);
    int i = n/2;
    int start = arr[i];
    while(i < n-1)
    {
        if(k==0) break;
        if(k < (i-n/2+1)*(arr[i+1]-arr[i]))
        {
            start += k/(i-n/2+1);
            k=0;
            i++;
        } else 
        {
            start += (arr[i+1]-arr[i]);
            k -= (i-n/2+1)*(arr[i+1]-arr[i]);
            i++;
        }
    }
    if(k) start += k/(i-n/2+1);
    cout << start << endl;
}