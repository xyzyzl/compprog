#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    vector<int> killer(n+1);
    set<int> is_in;
    for(int i = 0; i < n; i++)
    {
        is_in.insert(i+1);
    }
    for(int i = 0; i < m; i++)
    {
        vector<int> kill;
        int l, r, x;
        cin >> l >> r >> x;
        auto it = is_in.lower_bound(l);
        while(it != is_in.end())
        {
            // cout << *it << endl;
            if(*it > r) break;
            if(*it != x)
            {
                killer[*it] = x;
                kill.push_back(*it);
            }
            it++;
        }
        for(int elim : kill)
        {
            is_in.erase(elim);
        }
    }
    for(int i = 0; i < n; i++)
    {
        cout << killer[i+1] << " ";
    }
}