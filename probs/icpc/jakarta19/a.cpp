#include <bits/stdc++.h>

using namespace std;

int n, arr[100005];
int main()
{
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        cin >> arr[(i+1)%n];
    }
    for(int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}