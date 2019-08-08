// time: 8:07

#include <bits/stdc++.h>

using namespace std;

int n;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie();
    cout.tie();
    cin >> n;
    if(n < 4)
    {
        if(n == 1) cout << 1;
        else cout << "NO SOLUTION";
        return 0;
    }
    if(n == 4) cout << "2 4 1 3";
    else for(int i = 1; i <= n/2; i++)
    {
        cout << i << " " << (i+(n+1)/2) << " ";
    }
    if(n%2) cout << (n+1)/2;
}