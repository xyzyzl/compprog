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

#define contains count
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

int n,k,s1[MAXN],s2[MAXN];
int main()
{
    cin >> n >> k;
    FOR(i, n)
    {
        cin >> s1[i];
    }
    FOR(i, n)
    {
        cin >> s2[i];
    }
    si p1, p2;
    vi v;
    FOR(i, n)
    {
        if(p2.contains(s1[i])) p2.erase(s1[i]);
        else p1.insert(s1[i]);
        if(p1.contains(s2[i])) p1.erase(s2[i]);
        else p2.insert(s2[i]);
        if(p1.empty() && p2.empty())
        {
            v.pb(i);
        }
    }
    if(v.size() < k)
    {
        cout << "NO" << endl;
    } else 
    {
        string ans(n, ' ');;
        cout << "YES" << endl;
        int pre = 0;
        int w = 0;
        for(int cur : v)
        {
            for(int i = pre; i <= cur; i++)
            {
                // cout << s1[i] - 1 << endl;
                ans[s1[i]-1] = (char)('a'+min(w, 25));
            }
            w++;
            pre = cur+1;
        }
        cout << ans << endl;
    }
}