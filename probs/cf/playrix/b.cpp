#include <bits/stdc++.h>
 
#pragma GCC optimize ("O3")
 
using namespace std;

#define MAXN 200001

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
#define x first
#define y second

int n, m, p[MAXN], a[MAXN], b[MAXN], v[MAXN];
bool comp(int i, int j)
{
    return p[i] < p[j];
}
set<int, bool(*)(int lhs, int rhs)> t[3];

int main()
{
    DUEHOANG;
    FOR(i, 3) t[i] = set<int, bool(*)(int lhs, int rhs)>(comp);
    cin >> n;
    FOR(i, n) cin >> p[i];
    FOR(i, n)
    {
        cin >> a[i];
        t[a[i]-1].insert(i);
    }
    FOR(i, n)
    {
        cin >> b[i];
        if(a[i] != b[i]) t[b[i]-1].insert(i);
    }
    cin >> m;
    FOR(i, m)
    {
        int j;
        cin >> j;
        j--;
        int ind = *t[j].begin();
        if(t[j].empty()) cout << -1 << " ";
        else
        {
            t[j].erase(t[j].begin());
            // cout << ind << endl;
            if(a[ind] == j+1)
            {
                t[b[ind]-1].erase(ind);
            }
            if(b[ind] == j+1)
            {
                t[a[ind]-1].erase(ind);
            }
            cout << p[ind] << " ";
        }
    }
}

// issue: none after this submission, but i originally intended something, went to fix some other area, went back, and did the
// exact opposite of what i was planning on doing

// follow through before fixing another bug or moving somewhere else.