#include <bits/stdc++.h>

#pragma GCC optimize ("O3")
 
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
typedef vector<pii> vii;
typedef priority_queue<int> pqi;
typedef stack<int> sti;
typedef queue<int> qi;
typedef deque<int> di;
typedef map<int, int> mii;
#define x first
#define y second

string s, t;
int main()
{
    cin >> s >> t;
    int j = 0;
    int s1, e1, s2, e2;
    FOR(i, s.length())
    {
        if(s[i] == t[j])
        {
            if(j == 0) s1 = i;
            if(j == t.length()-1) e1 = i;
            j++;
        }
    }
    int kazakh = max(s1, (int)s.length()-e1-1);
    reverse(s.begin(), s.end());
    reverse(t.begin(), t.end());
    j = 0;
    FOR(i, s.length())
    {
        if(s[i] == t[j])
        {
            if(j == 0) e2 = s.length()-i-1;
            if(j == t.length()-1) s2 = s.length()-i-1;
            j++;
        }
    }
    cout << max(kazakh, max(s2, (int)s.length()-e2-1)) << endl;
}