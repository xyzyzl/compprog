#include <bits/stdc++.h>

#pragma GCC optimize("O3")

using namespace std;

#define MAXN 300005
#define MOD 998244353

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
#define x first
#define y second

int n, m, k[21][21];
string s;
int main()
{
    cin >> n >> m >> s;
    FOR(i, n-1)
    {
        if(s[i] != s[i+1])
        {
            k[min(s[i], s[i+1]) - 'a'][max(s[i], s[i+1]) - 'a']++;
        }
    }
    vector<int> v;
    FOR(i, m)
    {
        FOR(j, m)
        {
            v.push_back(k[i][j]);
        }
    }
    sort(v.begin(), v.end());
    reverse(v.begin(), v.end());
    int ans = 0;
    FOR(i, v.size())
    {
        ans += v[i] * (i/2+1);
    }
    cout << ans << endl;
}