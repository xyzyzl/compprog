#include <bits/stdc++.h>
 
using namespace std;
  
#define MAXN 1005
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
typedef pair<int, pii> iii; // remember that iii.f is an integer and that iii.s is a pair
typedef priority_queue<int> pqi;
typedef stack<int> sti;
typedef queue<int> qi;
typedef deque<int> di;
typedef map<int, int> mii;
#define f first
#define s second
typedef vector<pair<int, int> > vii;

int n, m, greed_is_good=10000000;
int arr[MAXN];
iii que[MAXN];
bool srt[MAXN];
int main()
{
    fill(arr, arr+MAXN, -1);
    // vfire orz
    cin >> n >> m;
    FOR(i, m) cin >> que[i].f >> que[i].s.f >> que[i].s.s;
    cout << "rr" << endl;
    FOR(i, m)
    {
        if(que[i].f)
        {
            for(int i = que[i].s.f; i <= que[i].s.s; i++) srt[i]=1;
        }
    }
    cout << "r" << endl;
    FOR(i, m)
    {
        bool orzed_tmw = 0;
        if(!que[i].f)
        {
            int orig = greed_is_good;
            for(int i = que[i].s.f; i <= que[i].s.s; i++)
            {
                if(arr[i] == -1)
                {
                    if(!srt[i] && !orzed_tmw)
                    {
                        orzed_tmw=1;
                        greed_is_good--;
                    }
                    arr[i] = greed_is_good;
                }
            }
            if(orig == greed_is_good)
            {
                cout << "NO" << endl;
                return 0;
            }
        }
    }
    cout << "YES" << endl;
    FOR(i, n) cout << arr[i] << " ";
}