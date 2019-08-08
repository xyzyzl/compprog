#include <bits/stdc++.h>
 
using namespace std;

#define MAXN 200005 

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

int N, sub[MAXN];
vi adj[MAXN];
void subtree_sizes(int i, int par)
{
    sub[i]++;
    for(int j : adj[i])
    {
        if(j != par)
        {
            subtree_sizes(j, i);
            sub[i] += sub[j];
        }
    }
}

int main()
{
    cin >> N;
    FOR(i, N-1)
    {
        int a;
        cin >> a;
        adj[i+1].pb(a-1);
        adj[a-1].pb(i+1);
    }
    subtree_sizes(0, -1);
    FOR(i, N)
    {
        cout << sub[i]-1 << " ";
    }
    return 0;
}