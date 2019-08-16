#include <bits/stdc++.h>
 
using namespace std;

#define MAXN 1005

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

int n;
bool arr[11];
int main()
{
    cin >> n;
    FOR(i, n)
    {
        char c;
        cin >> c;
        if(c == 'L')
        {
            FOR(j, 10)
            {
                if(arr[j] == 0) // fill closest empty room from left
                {
                    arr[j]=1;
                    break;
                }
            }
        } else if(c == 'R')
        {
            FORD(j, 10)
            {
                if(arr[j] == 0) // fill the one closest to right.
                {
                    arr[j] = 1;
                    break;
                }
            }
        } else // remove selected
        {
            c -= '0';
            arr[c] = 0;
        }
    }
    FOR(i, 10)
    {
        cout << arr[i];
    }
}