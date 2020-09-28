#include <bits/stdc++.h>

using namespace std;

#define f first
#define s second

int n, q, p[2005 * 2005], sz[2005 * 2005];

int find_set(int i)
{
    return (p[i] == i) ? i : (p[i] = find_set(p[i]));
}

bool union_set(int i, int j)
{
    int x = find_set(i);
    int y = find_set(j);
    if (x == y)
        return false;
    p[x] = p[y] = x;
    sz[x] += sz[y];
    return true;
}

void init()
{
    for(int i = 0; i < n; i++) p[i] = i;
    for(int i = 0; i < n; i++) sz[i] = 1;
}

int main()
{
	freopen("mootube.in","r",stdin);
	freopen("mootube.out","w",stdout);
	cin >> n >> q;
	vector<pair<int, pair<int, int> > > eg;
	for(int i = 1; i < n; i++)
	{
		int a, b, r;
		cin >> a >> b >> r;
		--a; --b;
		eg.push_back(make_pair(r, make_pair(a,b)));
	}
	sort(eg.begin(), eg.end());
	reverse(eg.begin(), eg.end());
	vector<pair<int, pair<int, int> > > que(q);
	for(int i = 0; i < q; i++)
	{
		cin >> que[i].f >> que[i].s.f;
		que[i].s.f -- ;
		que[i].s.s = i;
	}
	sort(que.begin(), que.end());
	reverse(que.begin(), que.end());
	init();
	int j = 0;
	vector<int> ans(q);
	for(int i = 0; i < q; i++)
	{
		while(j < eg.size() && eg[j].f >= que[i].f)
		{
			union_set(eg[j].s.f, eg[j].s.s);
			j++;
		}
		ans[que[i].s.s] = sz[find_set(que[i].s.f)];
	}
	for(int x : ans) cout << x-1 << endl;
}