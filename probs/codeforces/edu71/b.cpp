#include <bits/stdc++.h>

using namespace std;

int n, m, gd[55][55], ngd[55][55];
vector<pair<int, int> > pos;
int main()
{
    cin >> n >> m;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
            cin >> gd[i][j];
    }
    int sum = 0, sum2 = 0;
    for(int i = 0; i < n-1; i++)
    {
        for(int j = 0; j < m-1; j++)
        {
            sum = gd[i][j] + gd[i][j+1] + gd[i+1][j] + gd[i+1][j+1];
            
            if(sum == 4)
            {
                pos.push_back({i+1,j+1});
                ngd[i][j] = 1;
                ngd[i][j+1] = 1;
                ngd[i+1][j] = 1;
                ngd[i+1][j+1] = 1;
            }  
        }
    }
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            if(ngd[i][j] != gd[i][j])
            {
                cout << "-1" << endl;
                return 0;
            }
        }
    }
    cout << pos.size() << endl;
    for(pair<int, int> p : pos)
    {
        cout << p.first << " " << p.second << endl;
    }
}