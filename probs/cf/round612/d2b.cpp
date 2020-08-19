// Time:
// Algorithms: 

#include <bits/stdc++.h>

#pragma GCC optimize("O3")

using namespace std;

#define MAXN 1505
#define MAXK 35

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

int n, k;
string arr[MAXN];
set<string> st;
int main()
{
	DUEHOANG;
    int t = 1;
    // cin >> t; // uncomment if it's multitest
    while(t--)
    {
		int ans = 0;
		cin >> n >> k;
		FOR(i, n)
		{
			cin >> arr[i];
			st.insert(arr[i]); // set of all cards
		}
		FOR(i, n)
		{
			FORR(i+1, j, n)
			{
				vector<char> last;
				FOR(ind, k)
				{
					if(arr[i][ind] == arr[j][ind]) last.pb(arr[i][ind]);
					else 
					{
						if(arr[i][ind] == 'S' && arr[j][ind] == 'E') last.pb('T');
						else if(arr[i][ind] == 'E' && arr[j][ind] == 'S') last.pb('T');
						else if(arr[i][ind] == 'S' && arr[j][ind] == 'T') last.pb('E');
						else if(arr[i][ind] == 'T' && arr[j][ind] == 'S') last.pb('E');
						else if(arr[i][ind] == 'E' && arr[j][ind] == 'T') last.pb('S');
						else if(arr[i][ind] == 'T' && arr[j][ind] == 'E') last.pb('S');
					}
				}
				ostringstream x;
				for(char c : last) x << c;
				string str = x.str();
				if(st.count(str)) ans++;
			}
		}
		cout << ans/3 << endl;
    }
    
}