#include <bits/stdc++.h>
 
using namespace std;

#define MAXN 201

#define FOR(i, n) for(int i = 0; i < n; i++)
#define FORD(i, n) for(int i = n-1; i >= 0; i--)
#define FOBIR(i, n) for(int i = 1; i <= n; i++)
#define pb push_back
#define mp make_pair
#define endl '\n'
#define DUEHOANG ios_base::sync_with_stdio(0); cin.tie(); cout.tie()
 
typedef set<int> si;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef priority_queue<int> pqi;
typedef stack<int> sti;
typedef queue<int> qi;
typedef deque<int> di;
typedef map<int, int> mii;
#define x first
#define y second

bool is_subseq(string s, string t)
{
    int j = 0;
    FOR(i, s.length())
    {
        if(s[i] == t[j]) j++;
    }
    return (j == t.length());
}

int main()
{
    int t=1;
    // cin >> t;
    while(t--)
    {
        string s, t;
        cin >> s >> t;
        int ans = 0;
        FOR(i, s.length())
        {
            for(int j = i+1; j <= s.length(); j++)
            {
                string r = s.substr(0, i) + s.substr(j, s.length());
                // cout << r << " " << i << " " << j << endl;
                if(is_subseq(r, t)) ans = max(ans, j-i);
            }
        }
        cout << ans << endl;
    }
}