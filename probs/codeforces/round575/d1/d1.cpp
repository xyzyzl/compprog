// Time: 25:30
#include <bits/stdc++.h>
 
using namespace std;

#define MAXN 201

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

int n, k;
string s;

char v(int c)
{
    if(c%3 == 0) return 'R';
    if(c%3 == 1) return 'G';
    if(c%3 == 2) return 'B';
    return -1;
}

int main()
{
    int qqqq;
    cin >> qqqq;
    while(qqqq--)
    {
        cin >> n >> k >> s;
        int mn = INT_MAX;
        FOR(i, n-k+1)
        {
            FOR(off, 3)
            {
                int cur = 0;
                FOR(j, k)
                {
                    if(s[i+j] != v(off + j)) cur++;
                }
                mn = min(mn, cur);
            }
        }
        cout << mn << endl;
    }
}