#include <iostream>

using namespace std;

bool vis[200005];
int main()
{
    int n;
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        vis[a]=1;
    }
    for(int i = 1; i <= n; i++) if(!vis[i])
    {
        cout << i << endl;
        break;
    }
}