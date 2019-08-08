#include <bits/stdc++.h>
 
using namespace std;
 
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

int t;
int main()
{
    cin >> t;
    while(t--)
    {
        double n;
        cin >> n;
        if(n*n-4*n < 0)
        {
            cout << "N" << endl;
            continue;
        }
        cout << "Y ";
        double a = (n + sqrt(n*n-4*n))/2.0;
        double b = (n - sqrt(n*n-4*n))/2.0;
        cout << setprecision(15) << fixed << a << " " << b << endl;
    }
}