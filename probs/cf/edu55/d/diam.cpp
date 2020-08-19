#include <bits/stdc++.h>
 
using namespace std;
  
#define MAXN 505
#define INF (int)(1e9+7);
#define FOR(i, n) for(int i = 0; i < n; i++)
#define FORD(i, n) for(int i = n-1; i >= 0; i--)
#define FOBIR(i, n) for(int i = 1; i <= n; i++)
#define pb push_back
#define mp make_pair
#define endl '\n'
#define DUEHOANG ios_base::sync_with_stdio(0); cin.tie(); cout.tie()
 
typedef set<int> si;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef priority_queue<int> pqi;
typedef stack<int> sti;
typedef queue<int> qi;
typedef deque<int> di;
typedef map<int, int> mii;
#define f first
#define s second
typedef vector<pair<int, int> > vii;

int n, a[MAXN], diam, head, tail;
bool vis[MAXN];
vii edg;
qi q;
int sss;
int main()
{
    cin >> n;
    FOR(i, n)
    {
        cin >> a[i];
        sss += a[i];
    }
    if(sss < 2*(n-1))
    {
        cout << "NO" << endl;
        return 0;
    }
    int pre = -1;
    // cout << n << endl;
    FOR(i, n)
    {
        if(a[i] > 1)
        {
            q.push(i);
            vis[i] = 1;
            diam++;
            if(pre == -1) pre = i;
            else
            {
                edg.pb(mp(pre, i));
                a[i]--; a[pre]--;
                pre = i;
            }
        }
        // cout << "why is it running?" << endl;
    }
    // FOR(i, n) cout << a[i] << endl;
    head = q.front();
    tail = q.back();
    // cout << tail << endl;
    bool u=0, w=0;
    FOR(i, n)
    {
        if(!vis[i])
        {
            int link = q.front();
            while(a[link] < 0) q.pop();
            bool did_a_thing = 0;
            if(link == head)
            {
                if(!u)
                {
                    did_a_thing = 1;
                    u=1;
                    diam++;
                }
            }
            if(link == tail)
            {
                if(!did_a_thing && !w)
                {
                    w=1;
                    diam++;
                }
            }
            edg.pb(mp(link, i));
            if(--a[link] <= 0) q.pop();
        }
    }
    diam--;
    cout << "YES " << diam << endl;
    cout << edg.size() << endl;
    for(pii p : edg) cout << p.f+1 << " " << p.s+1 << endl;
}