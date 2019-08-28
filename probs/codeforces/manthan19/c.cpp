#include <bits/stdc++.h>

#pragma GCC optimize("O3")

using namespace std;

#define MAXN 2005

#define FOR(i, n) for (int i = 0; i < n; i++)
#define FORD(i, n) for (int i = n - 1; i >= 0; i--)
#define FOBIR(i, n) for (int i = 1; i <= n; i++)
#define pb push_back
#define mp make_pair
#define endl '\n'
#define DUEHOANG                  \
	ios_base::sync_with_stdio(0); \
	cin.tie(NULL);                \
	cout.tie(NULL)

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

int n, mat[1005][1005];
int main()
{
    cin >> n;
    int ct = 0;
    FOR(i, n/2)
    {
        FOR(j, n/2)
        {
            mat[i][j] = ct*4+0;
            mat[n-i-1][j] = ct*4+1;
            mat[n-i-1][n-j-1] = ct*4+2;
            mat[i][n-j-1] = ct*4+3;
            ct++;
        }
    }
    FOR(i, n)
    {
        FOR(j, n)
        {
            if(mat[i][j] == n*n) cout << "0 ";
            else cout << mat[i][j] << " ";
        }
        cout << endl;
    }
}