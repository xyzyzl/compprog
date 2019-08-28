#include <bits/stdc++.h>

#pragma GCC optimize("O3")

using namespace std;

#define MAXN 100005

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

int T;
int main()
{
    cin >> T;
    while(T--)
    {
        int b,p,f,h,c;
        cin >> b >> p >> f >> h >> c;
        int ans=0;
        if(c > h)
        {
            ans+=c*min(b/2, f);
            b-=2*min(b/2, f);
        } else 
        {
            ans+=h*min(b/2, p);
            b-=2*min(b/2, p);
        }
        // then you would see how many buns you have left to make the smaller
        if(c > h)
        {
            ans+=h*min(b/2, p);
            b-=2*min(b/2, p);
        } else 
        {
            ans+=c*min(b/2, f);
            b-=2*min(b/2, f);
        }
        cout << ans << endl;
    }
}