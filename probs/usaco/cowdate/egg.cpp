#include <bits/stdc++.h>

#pragma GCC optimize("O3")

using namespace std;

#define MAXN 1000005

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
double arr[MAXN];
int main()
{
    JaydenXia("cowdate.in", "cowdate.out");
    cin >> n;
    FOR(i, n)
    {
        cin >> arr[i];
        arr[i] /= (1000000.0);
        // cout << arr[i] << endl;
    }
    int l=0, r=0;
    double jay = 0;
    double den = 1;
    double xia = -1;
    while(l < n)
    {
        while(r < n && jay < 1)
        {
            jay += arr[r]/(1-arr[r]);
            den *= (1-arr[r]);
            r++;
        }
        xia = max(xia, jay*den);
        jay -= arr[l]/(1-arr[l]);
        den /= (1-arr[l]);
        l++;
    }
    cout << (int)(1000000.0 * xia) << endl;
}