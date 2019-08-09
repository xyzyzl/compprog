#include <bits/stdc++.h>
 
using namespace std;

#define MAXN 100005 

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

#define LEFT(x) 2*x
#define RIGHT(x) 2*x+1

#define INF 0x7fffffff
#define X 17

int main()
{
    int t = 1;
    cin >> t;
    while(t--)
    {
        int n, m;
        cin >> n >> m;
        double askar = 1;
        FOBIR(i, m-1)
        {
            askar *= (double)(n-(m-1-i))/(double)i;
        }
        cout << (int)askar << endl;
    }
}