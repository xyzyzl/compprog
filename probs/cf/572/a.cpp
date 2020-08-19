#include <bits/stdc++.h>

using namespace std;

#define MAXN 100005

int n;
bool arr[MAXN];
int main()
{
    cin >> n;
    int goodness = 0;
    for(int i = 0; i < n; i++)
    {
        char c;
        cin >> c;

        arr[i] = (c == '1');
        goodness += (arr[i] == 0 ? -1 : 1);
    }
    if(goodness != 0)
    {
        cout << 1 << '\n';
        for(int i = 0; i < n; i++) cout << arr[i];
    }
    else 
    {
        cout << 2 << '\n';
        cout << arr[0] << " ";
        for(int i = 1; i < n; i++) cout << arr[i];
    }
}