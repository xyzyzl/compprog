#include <bits/stdc++.h>

#pragma GCC optimize("O3")

using namespace std;

#define MAXN 105

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

#define int long

int n;
vi v, psum;
signed main()
{
    int pos = 1, neg = 0;
    cin >> n;
    v.resize(n+1);
    psum.resize(n+1);
    FOBIR(i, n)
    {
        cin >> v[i];
    }
    psum[0]=1;
    FOBIR(i, n)
    {
        psum[i] = psum[i-1] * (v[i] > 0 ? 1 : -1);
        // cout << psum[i] << endl;
        if(psum[i] > 0) pos++; else neg++;
    }
    // cout << pos << " " << neg << endl;
    cout << pos*neg << " " << n*(n+1)/2 - pos*neg << endl;
}