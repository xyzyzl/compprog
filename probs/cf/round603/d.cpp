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

#define fileio(in, out)      \
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

int n, p[MAXN];

int findSet(int i)
{
    return (p[i] == i) ? i : (p[i] = findSet(p[i]));
}
bool isSameSet(int i, int j)
{
    return findSet(i) == findSet(j);
}
void unionSet(int i, int j)
{
    if (!isSameSet(i, j))
    {
        int a = findSet(i), b = findSet(j);
        if (a > b)
        {
            swap(a, b);
        }
        p[a] = b;
    }
}

map<char, int> head;

int main()
{
    cin >> n;
    FOBIR(i, n) p[i] = i;
    FOBIR(i, n)
    {
        string s;
        cin >> s;
        for(char c : s)
        {
            if(!head[c]) head[c] = i;
            else unionSet(i, head[c]);
        }
    }
    si s;
    FOBIR(i, n)
    {
        s.insert(findSet(i));
    }
    cout << s.size() << endl;
}