
#include <bits/stdc++.h>

#pragma GCC optimize("O3")

using namespace std;

#define MAXN 200005

#define FOR(i, n) for (int i = 0; i < n; i++)
#define FORR(j, i, n) for (int i = j; i < n; i++)
#define FORD(i, n) for (int i = n - 1; i >= 0; i--)
#define FOBIR(i, n) for (int i = 1; i <= n; i++)
#define pb push_back
#define mp make_pair
#define endl '\n'
#define DUEHOANG                  \
	ios_base::sync_with_stdio(0); \
	cin.tie(NULL);                \
	cout.tie(NULL)

#define JaydenXia(in, out) \
	freopen(in, "r", stdin); \
	freopen(out, "w", stdout);

#define long long long

typedef set<int> si;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef vector<pii> vii;
typedef priority_queue<int> pqi;
typedef stack<int> sti;
typedef queue<int> qi;
typedef deque<int> di;
typedef map<int, int> mii;
#define f first
#define s second

int n, k;
pii q[MAXN];
vector<pair<int, pii> > edl;

long ans = 0;
class UnionFind
{
private:
	vector<int> p, rank;
public:
	UnionFind(int N)
	{
		rank.assign(N, 1);
		p.assign(N, 0);
		for (int i = 0; i < N; i++)
			p[i] = i;
	}
	int findSet(int i)
	{
		return (p[i] == i) ? i : (p[i] = findSet(p[i]));
	}
    long sum(long a)
    {
        return a*(a-1)/2;
    }
	void unionSet(int i, int j)
	{
		if (1)
		{
			int x = findSet(i), y = findSet(j);
			if (rank[x] < rank[y])
            {
                int temp = x;
                x=y;
                y=temp;
            }
            ans -= sum(rank[x]);
            ans -= sum(rank[y]);

            rank[x] += rank[y];
            ans += sum(rank[x]);

            p[y] = x;
		}
	}
};

int main()
{
    DUEHOANG;
    cin >> n >> k;
    FOR(i, n-1)
    {
        int a, b;
        cin >> a >> b;
        a--; b--;
        int w;
        cin >> w;
        edl.pb(mp(w, mp(a,b)));
    }
    UnionFind uf(n);
    FOR(i, k)
    {
        cin >> q[i].f;
        q[i].s = i;
    }
    sort(q, q+k);
    sort(edl.begin(), edl.end());
    vector<long> almaty(k);
    int j = 0;
    FOR(i, k)
    {
        // cout << q[i].s << endl;
        while(j < n-1 && edl[j].f <= q[i].f)
        {
            uf.unionSet(edl[j].s.f, edl[j].s.s);
            j++;
        }
        almaty[q[i].s] = ans;
    }
    for(long i : almaty) cout << i << " ";
    cout << endl;
}