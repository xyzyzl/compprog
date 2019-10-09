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

int n;
char arr[MAXN];
int main()
{
    cin >> n;
    FOR(i, n) cin >> arr[i];
    int l=0, r=0, lqm=0, rqm=0;
    FOR(i, n/2)
    {
        if(arr[i] != '?') l += arr[i]-'0'; else lqm++;
        if(arr[n-i-1] != '?') r += arr[n-i-1]-'0'; else rqm++;
    }
    // cout << lqm << " " << rqm << endl;
    if(l + lqm*9 - r + l - r - rqm*9 == 0) cout << "Bicarp" << endl;
    else cout << "Monocarp" << endl;
}