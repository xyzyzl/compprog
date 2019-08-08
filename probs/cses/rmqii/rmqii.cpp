#include <bits/stdc++.h>
 
using namespace std;

#define MAXN 200005 

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

#define LEFT(x) 2*x
#define RIGHT(x) 2*x+1

#define INF 0x7fffffff

int N, Q, arr[MAXN], st[4*MAXN];

// SEGMENT TREE
void build(int node, int a, int b) {
	if (a > b) return;
	if (a == b) {
		st[node] = arr[a];
		return;
	}
	build(LEFT(node), a, (a + b) / 2);
	build(RIGHT(node), (a + b) / 2 + 1, b);

	st[node] = min(st[LEFT(node)], st[RIGHT(node)]);
}

int rmq(int node, int a, int b, int i, int j) {
	if (a > b || a > j || b < i) return INF;
	if (a >= i && b <= j) return st[node];

	int q1 = rmq(LEFT(node), a, (a + b) / 2, i, j);
	int q2 = rmq(RIGHT(node), (a + b) / 2 + 1, b, i, j);
	return min(q1, q2); // this operation will change if it becomes something else
}

void upd(int node, int a, int b, int x, int value)
{
    if(a == b)
    {
        st[node] = value;
        return;
    }

    if(x <= (a+b)/2) upd(LEFT(node), a, (a+b)/2, x, value);
    else upd(RIGHT(node), (a+b)/2+1, b, x, value);
    st[node] = min(st[LEFT(node)], st[RIGHT(node)]);
}

int main()
{
    cin >> N >> Q;
    FOR(i, N) cin >> arr[i];
    build(1, 0, N-1);
    FOR(bishkek, Q)
    {
        int n, a, b;
        cin >> n >> a >> b;
        if(n==1)
        {
            a--;
            upd(1, 0, N-1, a, b);
        } else 
        {
            a--; b--;
            cout << rmq(1, 0, N-1, a, b) << endl;
        }
    }
}