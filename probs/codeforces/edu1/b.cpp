#include <bits/stdc++.h>
 
#pragma GCC optimize ("O3")

using namespace std;

#define MAXN 100005

#define FOR(i, n) for(int i = 0; i < n; i++)
#define FORD(i, n) for(int i = n-1; i >= 0; i--)
#define FOBIR(i, n) for(int i = 1; i <= n; i++)
#define pb push_back
#define mp make_pair
#define endl '\n'
#define DUEHOANG ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL)
 
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

string s;
int n;
int main()
{
    DUEHOANG;
    cin >> s;
    cin >> n;
    FOR(i, n)
    {
        int l, r, k;
        cin >> l >> r >> k;
        l--;
        r--;
        string t1 = s.substr(l, r-l+1);
        string t2 = s.substr(l, r-l+1);
        int m = t1.length();
        k %= m;
        FOR(i, m)
        {
            t2[i] = t1[(i-k+m)%m];
        }
        // cout << t2 << endl;
        FOR(i, m)
        {
            s[l+i] = t2[i];
        }
    }
    cout << s << endl;
}