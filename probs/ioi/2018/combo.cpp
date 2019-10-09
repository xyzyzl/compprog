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

int press(string p);

string guess_sequence(int n)
{
    string ans = "";
    if(press("AB") >= 1)
    {
        if(press("A") >= 1) ans += 'A';
        else ans += 'B';
    }
    else if(press("X") >= 1) ans += 'X';
    else ans += 'Y';

    vector<char> poss;
    poss.push_back('A');
    poss.push_back('B');
    poss.push_back('Y');
    poss.push_back('X');
    poss.erase(find(poss.begin(), poss.end(), ans[0]));

    for(int i = 2; i < n; i++)
    {
        int next = press(ans + poss[0] + (ans + poss[1] + poss[0] + ans + poss[1] + poss[1] + ans + poss[1] + poss[2]));
        if(next < i) ans += poss[2];
        else if(next == i) ans += poss[0];
        else ans += poss[1];
    }

    if(n == 1) return ans;
    if(press(ans + poss[0]) == n) ans = ans + poss[0];
    else if(press(ans + poss[1]) == n) ans = ans + poss[1];
    else ans = ans + poss[2];
    return ans;
}