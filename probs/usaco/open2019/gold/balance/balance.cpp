#include <bits/stdc++.h>
 
using namespace std;
 
#define MAXN 100005
 
#define FOR(i, n) for(int i = 0; i < n; i++)
#define FORD(i, n) for(int i = n-1; i >= 0; i--)
#define FOBIR(i, n) for(int i = 1; i <= n; i++)
#define pb push_back
#define mp make_pair
#define endl '\n'
#define DUEHOANG ios_base::sync_with_stdio(0); cin.tie(); cout.tie()
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
#define x first
#define y second

int n, arr[2*MAXN], ones, cs;

ll inv(int a, int b) // find # of inversions
{
    int n_ones = 0, res = 0;
    for(int i = a; i < b; i++)
    {
        if(arr[i]) n_ones++;
        else res += n_ones;
    }
    return res;
}

ll ans = LLONG_MAX;

void balance(int wanted, int a)
{
    ll beg = inv(0, n);
    ll end = inv(n, 2*n);
    ll del = beg-end;
    ans = min(ans, abs(del));
    // just keep looking for all of the (Desired value) and see how many steps to move
    // and to make balanced
    int lmostr=n;
    int ones_so_far = 0;
    int moved = 0;
    ll cost = 0;
    FORD(i, n) if(arr[i] == wanted)
    {
        cost += (n-1)-i;
        del -= a*((n-1)-i);
        cost++;
        del += a*(cs);
        cost += ones_so_far;
        del += a*ones_so_far;
        cost += moved;
        del += a*moved;
        
        ones_so_far++;
        if(ones_so_far + moved > n) return;
        while(ones_so_far + moved > lmostr - n)
        {
            if(arr[lmostr] != wanted)
            {
                lmostr++;
            } else if(lmostr == 2*n-1) return;
            else 
            {
                del += a*(n + ones_so_far + moved - lmostr);
                cost += n + ones_so_far + moved - lmostr;
                moved++;
                lmostr++;
            }
        }
        ans = min(ans, cost + abs(del));
    }
}

int main()
{
    freopen("balance.in", "r", stdin);
    freopen("balance.out", "w", stdout);
    cin >> n;
    FOR(i, 2*n)
    {
        cin >> arr[i];
        if(arr[i]) ones++;
    }
    cs = ones-n;
    balance(1, 1);
    balance(0, -1);
    cout << ans << endl;
}