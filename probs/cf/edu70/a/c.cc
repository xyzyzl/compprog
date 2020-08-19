#include <bits/stdc++.h>

#pragma GCC optimize ("O3")
 
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
typedef vector<pii> vii;
typedef priority_queue<int> pqi;
typedef stack<int> sti;
typedef queue<int> qi;
typedef deque<int> di;
typedef map<int, int> mii;
#define f first
#define s second

int T;
int main()
{
    cin >> T;
    while(T--)
    {
        string a, b;
        cin >> a >> b;
        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());
        int j=0, x=0;
        FOR(i, b.length())
        {
            if(b[i] == '1')
            {
                j=i;
                break;
            }
        }
        for(int i = j; i < a.length(); i++)
        {
            if(a[i] == '1')
            {
                x = i;
                break;
            }
        }
        if(x-j < 0) cout << 0 << endl;
        else cout << x-j << endl;
    }
}