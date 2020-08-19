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
#define f first
#define s second

int n, fact[MAXN], one[MAXN], two[MAXN];
pii arr[MAXN];
mii fs, ss;
map<pii, int> bh,seen;

int main()
{
    long p = 1;
    FOBIR(i, 300004)
    {
        p = p*i;
        p %= MOD;
        fact[i] = p;
    }
    fact[0] = 1;
    cin >> n;
    FOR(i, n)
    {
        cin >> arr[i].f >> arr[i].s;
        fs[arr[i].f]++;
        ss[arr[i].s]++;
    }
    long s1 = 1; // number of times where first is sorted
    FOR(i, n+1)
    {
        if(fs[i] != 0) s1 = (s1*fact[fs[i]]) % MOD;
    }
    long s2 = 1; // number of times where second is sorted
    FOR(i, n+1)
    {
        if(ss[i] != 0) s2 = (s2*fact[ss[i]]) % MOD;
    }
    // cout << s2 << endl;
    long nts = 1; // intersection between first and second
    sort(arr, arr+n);
    
    FOR(i, n-1)
    {
        if(arr[i+1].s < arr[i].s)
        {
            nts = 0; break;
        }
        bh[arr[i]]++;
    }
    bh[arr[n-1]]++;
    FOR(i, n)
    {
        if(seen[arr[i]]) continue;
        seen[arr[i]]++;
        nts = (nts*fact[bh[arr[i]]]) % MOD;
        // cout << nts << endl;
    }
    // cout << s1 << " " << s2 << " " << nts << endl;
    long ans = ((long)(fact[n]-s1-s2+nts)+MOD)%MOD;
    while(ans <= 0)
    {
        ans += MOD;
    }
    cout << ans % MOD;
}