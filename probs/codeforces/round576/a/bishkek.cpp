#include <bits/stdc++.h>

using namespace std;

int n, x, y, arr[100005];
int main()
{
    cin >> n >> x >> y;
    for(int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    for(int i = 0; i < n; i++)
    {
        bool good = 1;
        for(int j = 1; j <= x; j++)
        {
            if(i-j < 0) break;
            if(arr[i-j] < arr[i])
            {
                good = 0;
                break;
            }
        }
        for(int j = 1; j <= y; j++)
        {
            if(i+j >= n) break;
            if(arr[i+j] < arr[i])
            {
                good = 0;
                break;
            }
        }
        if(good)
        {
            cout << (i+1) << endl;
            break;
        }
    }
}