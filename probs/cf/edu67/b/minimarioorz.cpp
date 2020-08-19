#include <bits/stdc++.h>
 
using namespace std;
  
#define MAXN 505
#define INF (int)(1e9+7);
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
#define f first
#define s second
typedef vector<pair<int, int> > vii;

vi fs[27];
int n, m, freq[27];
string s, t;
int main()
{
    // minimario orz
    cin >> n;
    cin >> s;
    FOR(i, n)
    {
        char c = s[i];
        fs[c-'a'].pb(i);
    }
    cin >> m;
    FOR(i, m)
    {
        FOR(j, 27) freq[j] = 0;
        cin >> t;
        FOR(j, t.length()) freq[t[j]-'a']++;
        // FOR(j, t.length()) cout << freq[t[j]-'a'] << endl;
        int ind = 0;
        FOR(j, t.length())
        {
            ind = max(ind, fs[t[j]-'a'][freq[t[j]-'a']-1]);
        }
        cout << ind+1 << endl;
    }
}