#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int MAXN = 300005;
const ll INF = 1e18;

struct Tt
{
    int c, p, a, b;
    Tt(int c, int p, int a, int b)
    {
        this->c = c;
        this->p = p;
        this->a = a;
        this->b = b;
    }
    bool operator<(Tt other)
    {
        if(a==other.a) return b < other.b;
        return a < other.a;
    }
};

struct ST
{
    int n, sz;
    vector<int> bv;
    vector<Tt> tv;
    ST(vector<Tt> v) : tv(v)
    {
        n = 1;
        sz = (int)tv.size();
        // O(lg m)
        while(n < sz) n *= 2;
        bv.resize(2*n);
        // O(m)
        for(int i = 0; i < n; i++)
        {
            if(i < sz) bv[i+n] = tv[i].b;
            else bv[i+n] = -1;
        }
        // O(m)
        for(int i = n-1; i >= 1; i--)
        {
            // propagate
            bv[i] = max(bv[2*i], bv[2*i+1]);
        }
    }

    void remove(vector<int>& rem, int val, int node=1, int l=0, int r=-1)
    {
        if(r<0) r+=n; //n-1 parameter doesnt work lmaoooooo
        if(l >= sz || tv[l].a > val || bv[node] < val) // out of range
        {
            return;
        } else if(l == r)
        {
            bv[node] = -1; // don't consider this node again
            rem.push_back(l);
        } else 
        {
            int m = (l+r)/2;
            remove(rem,val,2*node,l,m);
            remove(rem,val,2*node+1,m+1,r);
            bv[node] = max(bv[2*node], bv[2*node+1]);
        }
    }
};

int n, m;
ll dist[MAXN], distl[MAXN], distr[MAXN];
vector<Tt> v;

void dijk()
{
    priority_queue<pair<ll, int>, vector<pair<ll, int> >, greater<pair<ll, int> > > pq;
    for(int i = n; i < n+m; i++)
    {
        dist[v[i-n].c] = min(dist[v[i-n].c], dist[i]+v[i-n].p);
    }
    for(int i = 0; i < n; i++)
    {
        if(dist[i] < INF) pq.push({dist[i], i});
    }
    // dijkstra except once we buy a ticket we remove it from ST so we don't mistakenly buy it again
    ST st(v); // O(m)
    while(!pq.empty())
    {
        auto x = pq.top(); pq.pop(); // O(lg n)
        if(x.first > dist[x.second]) continue; // no reason to update to longer path
        vector<int> rem;
        st.remove(rem,x.second); // O(lg m) to traverse, and it removes some tickets so...
        for(int y : rem) // O(m) in total over every time this loop is run
        { // O(lg n) in here
            if(dist[y+n] > x.first)
            {
                dist[y+n] = x.first;
                if(dist[v[y].c] > x.first + v[y].p)
                {
                    dist[v[y].c] = x.first + v[y].p;
                    pq.push({dist[v[y].c], v[y].c});
                }
            }
        }
    }
} // so this should be O(m lg n) roughly

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cin >> n >> m;
    v.assign(m, Tt(69,69,69,69));
    for(int i = 0; i < m; i++)
    {
        int c,p,a,b; cin>>c>>p>>a>>b;
        --c; --a; --b;
        v[i] = Tt(c,p,a,b);
    } // O(M) to this point

    sort(v.begin(), v.end()); // O(m lg m)

    fill(dist,dist+n+m,INF);
    dist[0] = 0;
    dijk(); // find distances from 0
    for(int i = 0; i < n+m; i++) distl[i] = dist[i];
    fill(dist,dist+n+m,INF);
    dist[n-1] = 0;
    dijk(); // find distances from n-1
    for(int i = 0; i < n+m; i++) distr[i] = dist[i];
    for(int i = 0; i < n+m; i++) dist[i] = distl[i] + distr[i];
    dijk();

    // O(N)
    for(int i = 0; i < n; i++)
    {
        if(dist[i] < INF) cout << dist[i] << '\n';
        else cout << -1 << '\n';
    }
}