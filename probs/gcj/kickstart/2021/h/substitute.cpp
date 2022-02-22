#include <bits/stdc++.h>

using namespace std;


void solve()
{
    int n; cin >> n;
    string s; cin >> s;
    vector<int> pre(n), nxt(n), b;
    vector<bool> v(n);
    for(int i = 0; i < n; i++)
    {
        v[i] = 1;
        b.push_back(s[i] - '0');
    }
    for(int i = 0; i < n; i++)
    {
        pre[i] = i-1;
        nxt[i] = i+1;
    }
    set<int> poi[10];
    for(int i = 0; i < n-1; i++)
    {
        if((b[i] + 1)%10 == b[i+1])
        {
            poi[b[i]].insert(i);
        }
    }
    while(true)
    {
        int f = 0;
        for(int i = 0; i < 10; i++)
        {
            while(!poi[i].empty())
            {
                int k = *poi[i].begin();
                poi[i].erase(poi[i].begin());
                int l = pre[k];
                int r = nxt[k];
                v[r] = 0;
                if(nxt[r] < n)
                {
                    if((b[r]+1) % 10 == b[nxt[r]])
                    {
                        poi[b[r]].erase(r);
                    }
                    pre[nxt[r]] = k;
                    nxt[k] = nxt[r];
                } else 
                {
                    nxt[k] = nxt[r];
                }
                if(l >= 0)
                {
                    if((b[l]+1)%10==b[k])
                    {
                        poi[b[l]].erase(l);
                    }
                }
                b[k] = (i+2)%10;
                if(nxt[k] < n)
                {
                    if((b[k]+1)%10 == b[nxt[k]])
                    {
                        f++;
                        poi[b[k]].insert(k);
                    }
                }
                if(l >= 0)
                {
                    if((b[l]+1)%10 == b[k])
                    {
                        f++;
                        poi[b[l]].insert(l);
                    }
                }
            }
        }
        if(!f) break;
    }
    for(int i = 0; i < n; i++) if(v[i]) cout << b[i];
    cout << endl;
}

int main()
{
    int t; cin >> t;
    for(int i = 1; i <= t; i++)
    {
        cout << "Case #" << i << ": ";
        solve();
    }
}