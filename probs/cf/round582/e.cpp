
#include <bits/stdc++.h>

#pragma GCC optimize("O3")

using namespace std;

#define MAXN 55

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
int main()
{
    cin >> n;
    string a;
    cin >> a;
    string b;
    cin >> b;
    string perm = "abc";
    vector<string> states;
    do
    {
        string s1="", s2="";
        FOR(i, n) s1 += perm;
        FOR(i, n) s2 += perm[0];
        FOR(i, n) s2 += perm[1];
        FOR(i, n) s2 += perm[2];
        states.pb(s1);
        states.pb(s2);
    } while (next_permutation(perm.begin(), perm.end()));
    for(string mm : states)
    {
        if(mm.find(a) == string::npos && mm.find(b) == string::npos)
        {
            cout << "YES" << endl;
            cout << mm << endl;
            return 0;
        }
    }
    cout << "NO" << endl;
}