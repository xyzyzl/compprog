#include <bits/stdc++.h>

#pragma GCC optimize("O3")

using namespace std;

#define MAXN 200005

#define FOR(i, n) for (int i = 0; i < n; i++)
#define FORD(i, n) for (int i = n - 1; i >= 0; i--)
#define FOBIR(i, n) for (int i = 1; i <= n; i++)
#define pb push_back
#define mp make_pair
#define endl '\n'
#define DUEHOANG                  \
	ios_base::sync_with_stdio(0); \
	cin.tie(NULL);                \
	cout.tie(NULL)

typedef set<int> si;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef priority_queue<int> pqi;
typedef stack<int> sti;
typedef queue<int> qi;
typedef deque<int> di;
typedef map<int, int> mii;
#define x first
#define y second

int n;
vi adj[MAXN];
int arr[MAXN];
int ord[MAXN];
bool vis[MAXN];
vi askar;

bool mirbek_atabekov(int a, int b)
{
    return ord[a] < ord[b];
}

int main()
{
    cin >> n;
    FOR(i, n-1)
    {
        int a,b;
        cin>>a>>b;
        a--;
        b--;
        adj[a].pb(b);
        adj[b].pb(a);
    }
    FOR(i, n)
    {
        cin >> arr[i];
        arr[i]--;
        ord[arr[i]] = i; // after = larger
    }
    FOR(i, n)
    {
        sort(adj[i].begin(), adj[i].end(), mirbek_atabekov);
    }
    qi benq; // benq is the best
    benq.push(0);
    while(!benq.empty())
    {
        int tp = benq.front();
        benq.pop();
        askar.pb(tp);
        vis[tp] = true;
        for(int nx : adj[tp])
        {
            if(!vis[nx]) benq.push(nx);
        }
    }
    FOR(i, n)
    {
        // cout << askar[i] << " " << arr[i] << endl;
        if(askar[i] != arr[i])
        {
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;
}