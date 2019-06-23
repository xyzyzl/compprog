#include <bits/stdc++.h>

#define int long long

using namespace std;

int n, q;
int arr[100005];
deque<pair<int, int> > d;
#define f first
#define s second

pair<int, int> second()
{
    pair<int, int> a = d.front();
    d.pop_front();
    pair<int, int> b = d.front();
    d.push_front(a);
    return b;
}

void pbf()
{
    pair<int, int> a = d.front();
    d.pop_front();
    d.push_back(a);
}

void pbs()
{
    pair<int, int> a = d.front();
    d.pop_front();
    pair<int, int> b = d.front();
    d.pop_front();
    d.push_back(b);
    d.push_front(a);
}

void op()
{
    pair<int, int> a = d.front();
    pair<int, int> b = second();

    if(b.f > a.f) pbf();
    else pbs();
}

int32_t main()
{
    cin >> n >> q;
    if(q == 0) return 0;
    int mx = 0, mxi = 0;
    for(int i = 0; i < n; i++) 
    {
        cin >> arr[i];
        if(arr[i] > mx) 
        {
            mx = arr[i];
            mxi = i;
        }
        d.push_back(make_pair(arr[i], i));
    }
    vector<pair<int, int> > V, eV;
    
    for(int i = 0; i < mxi; i++)
    {
        // cout << d.front().f << endl;
        eV.push_back(make_pair(d.front().f, second().f));
        op();
    }
    // cout << d.front().f << endl;
    pair<int, int> l = second();
    do
    {
        V.push_back(make_pair(d.front().f, second().f));
        op();
    } while (second().f != l.f || second().s != l.s); // not the exact same
    for(int i = 0; i < q; i++)
    {
        int query;
        cin >> query;
        if(query <= mxi) 
        {
            cout << eV[query-1].f << " " << eV[query-1].s << endl;
        } else 
        {
            query = query-mxi-1;
            query %= (n-1);
            cout << V[query].f << " " << V[query].s << endl;
        }
    }
}