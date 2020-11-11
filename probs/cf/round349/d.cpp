
#include <bits/stdc++.h>
#include <bits/extc++.h>

using namespace std;

int n, m, vs[3005], dst[3005], ml[3005], mr[3005];
vector<int> l[3005], r[3005];
vector<int> adj[3005], adj2[3005];
int main()
{
    cin >> n >> m;
    for(int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        --a; --b;
        if(a==b) continue;
        adj[a].push_back(b);
        adj2[b].push_back(a);
    }
    for(int i = 0; i < n; i++)
    {
        memset(dst, 0x7f, sizeof dst);
        memset(vs, 0, sizeof vs);
        dst[i] = 0;
        queue<int> q;
        q.push(i);
        while(!q.empty())
        {
            int x = q.front();
            q.pop();
            if(vs[x]) continue;
            vs[x] = 1;
            for(int y : adj[x])
            {
                if(vs[y]) continue;
                dst[y] = dst[x] + 1;
                q.push(y);
            }
        }
        for(int j = 0; j < n; j++)
        {
            if(dst[j] > 2e9) continue;
            if(dst[j] > ml[i])
            {
                l[i].clear();
                l[i].push_back(j);
            } else if(dst[j] == ml[i])
            {
                l[i].push_back(j);
            }
            ml[i] = max(ml[i], dst[j]);
        }
    }
    for(int i = 0; i < n; i++)
    {
        memset(dst, 0x7f, sizeof dst);
        memset(vs, 0, sizeof vs);
        dst[i] = 0;
        queue<int> q;
        q.push(i);
        while(!q.empty())
        {
            int x = q.front();
            q.pop();
            if(vs[x]) continue;
            vs[x] = 1;
            for(int y : adj2[x])
            {
                if(vs[y]) continue;
                dst[y] = dst[x] + 1;
                q.push(y);
            }
        }
        for(int j = 0; j < n; j++)
        {
            if(dst[j] > 2e9) continue;
            if(dst[j] > mr[i])
            {
                r[i].clear();
                r[i].push_back(j);
            } else if(dst[j] == mr[i])
            {
                r[i].push_back(j);
            }
            mr[i] = max(mr[i], dst[j]);
        }
    }
    /*
    for(int i = 0; i < n; i++) for(int L : l[i]) for(int R : r[i])
    {
        cerr << L << ' ' << i << ' ' << R << endl;
    }
    */
    int mx = 0;
    int a=0,b=0,c=0,d=0;
    for(int i = 0; i < n; i++) for(int L : l[i]) for(int M : l[L]) for(int R : r[i])
    {
        if(L == R || L == i || R == i || L == M || i == M || R == M) continue;
        int x = mr[i] + ml[i] + ml[L];
        if(x > mx)
        {
            mx = x;
            a=R+1;
            b=i+1;
            c=L+1;
            d=M+1;
        }
        // cerr << x << ' ' << r[i] << ' ' << i << ' ' << l[i] << ' ' << l[l[i]] << endl;
    }
    cout << a << ' ' << b << ' ' << c << ' ' << d << endl;
}