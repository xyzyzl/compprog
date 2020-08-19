#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n, m;
    cin>>n>>m;
    for(int i = 1; i <= n/2; i++)
    {
        for(int j = 1; j <= m; j++)
        {
            cout << i << " " << j << endl;
            cout << (n-i+1) << " " << (m-j+1) << endl;
        }
    }
    if(n%2)
    {
        deque<int> d;
        for(int i = 1; i <= m; i++)
        {
            d.push_back(m-i+1);
        }
        while(d.size())
        {
            cout << n/2+1 << " " << d.back() << endl;
            d.pop_back();
            if(!d.size()) break;
            cout << n/2+1 << " " << d.front() << endl;
            d.pop_front();
        }
    }
}