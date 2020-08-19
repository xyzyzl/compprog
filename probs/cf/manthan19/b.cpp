#include <bits/stdc++.h>

#pragma GCC optimize("O3")

using namespace std;

#define MAXN 2005

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
int a[MAXN];
map<int, int> freq;
map<int, int> d, u;
set<int> kentaro;
int main()
{
    cin >> n;
    FOR(i, n)
    {
        cin >> a[i];
        freq[a[i]]++;
    }
    int last = n-1;
    bool flag = 0;
    FORD(i, n)
    {
        d[a[i]]++;
        kentaro.insert(a[i]);
        if(d[a[i]] > 1)
        {
            last = i;
            flag = 1;
            break;
        }
    }
    if(flag == 0)
    {
        cout << 0 << endl;
        return 0;
    }
    int frst = 0;
    FOR(i, n)
    {
        u[a[i]]++;
        if(u[a[i]] > 1 || kentaro.count(a[i]))
        {
            frst = i;
            break;
        }
    }
    int w = abs(last-frst + 1);
    frst = 0;
    last = n-1;
    u.clear();
    d.clear();
    kentaro.clear();
    FOR(i, n)
    {
        u[a[i]]++;
        kentaro.insert(a[i]);
        if(u[a[i]] > 1)
        {
            frst = i;
            break;
        }
    }
    FORD(i, n)
    {
        d[a[i]]++;
        if(d[a[i]] > 1 || kentaro.count(a[i]))
        {
            last = i;
            break;
        }
    }
    cout << min(w, abs(last-frst+1)) << endl;
}