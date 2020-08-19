#include <bits/stdc++.h>

#pragma GCC optimize("O3")

using namespace std;

#define MAXN 1000005

#define FOR(i, n) for (int i = 0; i < n; i++)
#define FORR(j, i, n) for (int i = j; i < n; i++)
#define FORD(i, n) for (int i = n - 1; i >= 0; i--)
#define FOBIRD(i, n) for (int i = n; i > 0; i--)
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

#define ll long long

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

const ll MOD = (ll)(1e9+7);
ll n, arr[MAXN], fact1[MAXN], fact2[MAXN];

ll wow(int ind)
{
    return fact1[n-ind-1] * fact2[n-ind+1] % MOD;
}

int main()
{
    DUEHOANG;
    cin >> n;
    FOBIR(i, n)
    {
        cin >> arr[i];
    }
    sort(arr+1, arr+1+n);
    fact1[0] = fact2[n+1] = 1;
    FOBIR(i, n)
    {
        fact1[i] = (fact1[i-1] * i) % MOD;
    }
    FOBIRD(i, n)
    {
        fact2[i] = (fact2[i+1] * i) % MOD;
    }
    ll ok = 0;
    ll ko = 0;
    ll fuck = 0;
    FOBIR(i, n)
    {
        if(arr[i] == arr[n]) break;
        if(arr[i] == arr[i-1]) ok++;
        else 
        {
            ko += ok;
            ok = 1;
        }
        fuck = (fuck + (wow(ko) * arr[i]) % MOD) % MOD;
    }
    cout << fuck << endl;
}