#include <bits/stdc++.h> // idk lol

#pragma GCC optimize("O3")

using namespace std;

#define MAXN 1000005

#define FOR(i, n) for (int i = 0; i < n; i++)
#define FORR(j, i, n) for (int i = j; i < n; i++)
#define FORD(i, n) for (int i = n - 1; i >= 0; i--)
#define FOBIR(i, n) for (int i = 1; i <= n; i++)
#define FOBIRD(i, n) for (int i = n; i >= 1; i--)
#define pb push_back
#define mp make_pair
#define endl '\n'
#define DUEHOANG                  \
    ios_base::sync_with_stdio(0); \
    cin.tie(NULL);                \
    cout.tie(NULL)

#define fileio(in, out)      \
    freopen(in, "r", stdin); \
    freopen(out, "w", stdout);

#define ll long long

typedef set<int> si;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef pair<int, pii> iii;
typedef vector<pii> vii;
typedef priority_queue<int> pqi;
typedef stack<int> sti;
typedef queue<int> qi;
typedef deque<int> di;
typedef map<int, int> mii;
#define f first
#define s second

#define LEFT(x) 2 * x
#define RIGHT(x) 2 * x + 1

#define bitinc(x) x&-x

const int MAX(int &a, int b)
{
    a = max(a, b); 
}
const int MIN(int &a, int b)
{
    a = min(a, b); 
}

int n, arr[MAXN],psum[MAXN],pos[2*MAXN],r[MAXN];
int main()
{
    cin >> n;
    char c;
    FOBIR(i, n)
    {
        cin >> c;
        arr[i] = (c=='p') ? 1 : -1;
    }
    psum[0] = n;
    FOBIR(i, n)
    {
        psum[i] = psum[i-1] + arr[i];
    }
    r[n] = pos[psum[n]] = n;
    int ans = 0;
    FORD(i, n)
    {
        if(psum[i] < psum[i+1])
        {
            r[i] = r[i+1];
            if(pos[psum[i]] != 0 && psum[r[pos[psum[i]]]] >= psum[r[i]])
                r[i] = r[pos[psum[i]]];
        } else r[i] = i;
        ans = max(ans, r[i] - i);
        pos[psum[i]] = i;
    }
    cout << ans << endl;
}