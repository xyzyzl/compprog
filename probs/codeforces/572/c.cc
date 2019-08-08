#include <bits/stdc++.h>

using namespace std;

int n, q, psum[100005], arr[100005];
int main()
{
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    psum[0] = arr[0];
    for(int i = 1; i < n; i++)
    {
        psum[i] = psum[i-1] + arr[i];
    }

    cin >> q;
    for(int i = 0; i < q; i++)
    {
        int a, b;
        cin >> a >> b;
        a--; b--;
        int w;
        if(a==0) w = psum[b];
        else w = psum[b]-psum[a-1];
        cout << (w-w%10)/10 << endl;
    }
}