// Time:
// Algorithms: 

#include <bits/stdc++.h>

#pragma GCC optimize("O3")

using namespace std;

#define MAXN 200005

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
#define INF (1e9*1)+5

typedef set<int> si;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef pair<int, pii> iii;
typedef vector<pii> vii;
typedef vector<iii> viii;
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
    return a = max(a, b); 
}
const int MIN(int &a, int b)
{
    return a = min(a, b); 
}

int n, freq[MAXN];
int main()
{
    int t = 1;
    // cin >> t; // uncomment if it's multitest
    while(t--)
    {
        cin >> n;
        FOR(i, n)
        {
            int x;
            cin >> x;
            freq[x]++;
        }
        // find min value
        int ct = 0;
        FOBIR(i, n)
        {
            if(!freq[i]) continue;
            else 
            {
                ct++;
                i += 2;
            }
        }
        cout << ct << " ";
		// find max value
		ct = 0;
		bool ex = 0;
		int dist = 2;
		FOBIR(i, n)
		{
			if(!freq[i])
			{
				dist++;
				continue;
			}
			int right = i;
			int sm = 0;
			while(right <= n && freq[right])
			{
				right++;
				sm += freq[right-1];
			}
			ct += (right-i); // the number of houses that form a segment
			if(sm > (right-i) && (!ex || dist > 1))
			{
				sm--;
				ct++;
				// cout << "yes" << endl;
			}
			ex = 0; // extendable?
			if(sm > (right-i))
			{
				ex = 1;
				ct++;
				// cout << "ok" << endl;
			}
			dist = 0;
			// cout << i << " " << right - 1 << endl;
			// cout << ct << endl;
			i = right-1; // sets i back to right value
		}
		cout << ct << endl;
    }
    
}