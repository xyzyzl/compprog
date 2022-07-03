#include <iostream>
#include <vector>

using namespace std;

const int MAXN = 300005;
const int MAXV = 1000005;

// fenwick tree that keeps track of how many segments exist at current index
int bit[MAXV];
void add(int x, int v)
{
    while(x < MAXV)
    {
        bit[x] += v;
        x+=(x&-x);
    }
}

int get(int x)
{
    int ret = 0;
    while(x > 0)
    {
        ret += bit[x];
        x -= x&-x;
    }
    return ret;
}

int n, m, ans[MAXN];
vector<int> seg[MAXV];
vector<pair<int,int> > q[MAXV];
int main()
{
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> n >> m;
	for(int i = 0; i < n; i++)
	{
		int l, r; cin >> l >> r;
		seg[r].push_back(l);
	}
	for(int i = 0; i < m; i++)
	{
		ans[i] = n;
		int cnt, lst=0; cin >> cnt;
		for(int j = 0; j < cnt; j++)
		{
			int a; cin >> a;
			if(a - lst > 1)
			{
				q[a-1].push_back(make_pair(lst+1, i));
			}
			lst = a;
		}
		if(MAXV - 4 - lst > 1)
		{
			q[MAXV-5].push_back(make_pair(lst+1, i));
		}
	}
	for(int r = 1; r < MAXV; r++)
	{
		for(int l : seg[r])
		{
			add(l, 1);
		}
		int tmp = get(r);
		for(pair<int,int> x : q[r])
		{
			ans[x.second] -= (tmp - get(x.first-1));
		}
	}
	for(int i = 0; i < m; i++)
	{
		cout << ans[i] << endl;
	}
}