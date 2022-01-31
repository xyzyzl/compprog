#include <bits/stdc++.h>
using namespace std;
using pii = pair<int,int>;
using pli = pair<long long, int>;
#define f first
#define s second

struct B 
{
    signed l, w, h, p, i;
    B() {}
    B(int l, int w, int h, int p, int i)
    {
        this->l = l;
        this->w = w;
        this->h = h;
        this->p = p;
        this->i = i;
    }
    bool operator<(B other)
    {
        if(h == other.h)
        {
            if(l == other.l) return w < other.w;
            return l < other.l;
        }
        return h < other.h;
    }
};

int n, last[100005], ans[100005];
B a[100005];
pli bit[5005][5005];

void updy(int x, int y, pii val)
{
	while(y <= 1000)
	{
		if(bit[x][y].f < val.f)
        {
            bit[x][y] = val;
        }
		y += (y&-y);
	}
}
 
void upd(int x, int y, pii val)
{
	while(x <= 1000)
	{
		updy(x, y, val);
		x += (x&-x);
	}
}
 
pli quey(int x, int y)
{
	long long ret = 0;
    int val = 0;
	while(y > 0)
	{
        if(ret < bit[x][y].f)
        {
		    ret = bit[x][y].f;
            val = bit[x][y].s;
        }
		y -= (y & -y);
	}
	return {ret,val};
}
 
pli que(int x, int y)
{
	long long ret = 0;
    int val = 0;
	while(x > 0)
	{
		pii k = quey(x, y);
        if(ret < k.f)
        {
            ret = k.f;
            val = k.s;
        }
		x -= (x & -x);
	}
	return {ret,val};
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        int l, w, h, p; cin >> l >> w >> h >> p;
        if(l<w) swap(l,w);
        a[i] = B(l, w, h, p, i+1);
    }
    sort(a, a+n);
    fill(last, last+n, 0);
    for(int i = 0; i < n; i++)
    {
        pii p = que(a[i].l, a[i].w);
        last[i] = p.s;
        ans[i] = a[i].p+p.f;
        upd(a[i].l, a[i].w, {ans[i],i+1});
    }

    int mxi = 0;
    int bes = 0;
    for(int i = 0; i < n; i++)
    {
        if(ans[i] > bes)
        {
            mxi = i;
            bes = ans[i];
        }
    }
    cout << bes << endl;

    vector<signed> l;
    while(mxi != -1)
    {
        l.push_back(a[mxi].i);
        mxi = last[mxi]-1;
    }
    cout << l.size() << endl;
    for(auto& x : l) cout << x << " ";
    cout << endl;
}