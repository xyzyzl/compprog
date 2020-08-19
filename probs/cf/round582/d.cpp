
#include <bits/stdc++.h>

#pragma GCC optimize("O3")

using namespace std;

#define MAXN 200005

#define FOR(i, n) for (int i = 0; i < n; i++)
#define FORR(j, i, n) for (int i = j; i < n; i++)
#define FORD(i, n) for (int i = n - 1; i >= 0; i--)
#define FOBIR(i, n) for (int i = 1; i <= n; i++)
#define pb push_back
#define mp make_pair
#define endl '\n'
#define DUEHOANG                  \
	ios_base::sync_with_stdio(0); \
	cin.tie(NULL);                \
	cout.tie(NULL)

#define JaydenXia(in, out) \
	freopen(in, "r", stdin); \
	freopen(out, "w", stdout);

#define long long long

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

int n, k, arr[MAXN];
vi states;
int main()
{
    cin >> n >> k;
    FOR(i, n)
    {
        cin >> arr[i];
    }
    vector<vi> sat(MAXN + 30);
    FOR(i, n)
    {
        int w = arr[i];
        int dev = 0;
        while(w > 0)
        {
            sat[w].pb(dev);
            states.pb(w);
            w /= 2;
            dev++;
        }
    }
    int A = INT_MAX;
    for(vi kaz : sat)
    {
        if(kaz.size() >= k)
        {
            sort(kaz.begin(), kaz.end());
            int jemerends=0;
            FOR(i, k)
            {
                jemerends+=kaz[i];
            }
            A = min(A, jemerends);
        }
    }
    cout << A << endl;
}