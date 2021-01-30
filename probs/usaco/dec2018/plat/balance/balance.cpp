#include <bits/stdc++.h>

#define MAXN 100005
using namespace std;

#define int long long
typedef pair<int, int> pii; 
#define f first
#define s second
#define ll long long
int n, l[MAXN], r[MAXN];
ll f[MAXN];
pii pts[MAXN];
pii O = make_pair(0,0);

unsigned int dist_2(pii p1, pii p2)
{
    return (((unsigned int)p1.f-p2.f)*(p1.f-p2.f) + ((unsigned int)p1.s-p2.s)*(p1.s-p2.s));
}

int orientation(pii p, pii q, pii r) 
{ 
    int val = (q.s - p.s) * (r.f - q.f) - (q.f - p.f) * (r.s - q.s);
    if (val == 0) return 0;
    return (val > 0)? 1: 2;
}

bool comp(pii a, pii b)
{
    int x = orientation(O, a, b);
    if(x == 0)
    {
        return (dist_2(O, b) >= dist_2(O, a));
    }
    return (x == 1);
}

pii sec_to_top(stack<pii> &st)
{
    pii tp = st.top();
    st.pop();
    pii ret = st.top();
    st.push(tp);
    return ret;
}

vector<pii> hull;
void convex()
{
    sort(pts+1, pts+n+2, comp);

    int m = 1;
	for(int i = 1; i <= n+1; i++)
    {
        while(i < n+1 && orientation(O,pts[i],pts[i+1]) == 0) i++;
        pts[m] = pts[i];
        ++m;
    }
    stack<pii> st;
	for(int i = 0; i < m; i++)
    {
        while(st.size() >= 2 && orientation(sec_to_top(st), st.top(), pts[i]) != 1)
        {
            st.pop();
        }
        st.push(pts[i]);
    }
    while(!st.empty())
    {
        hull.push_back(st.top());
        st.pop();
    }
    reverse(hull.begin(), hull.end());
}

signed main()
{
	freopen("balance.in", "r", stdin);
	freopen("balance.out", "w", stdout);
	cin >> n;
	for(int i = 1; i <= n; i++)
	{
		cin >> f[i];
	}
	f[0] = 0;
	f[n+1] = 0;
	for(int i = 0; i < n+2; i++) pts[i] = make_pair(i, f[i]);
	convex();
	for(int i = 0; i < hull.size()-1; i++)
	{
		for(int j = 1+hull[i].f; j < hull[i+1].f; j++)
		{
			l[j] = hull[i].f;
			r[j] = hull[i+1].f;
		}
		l[hull[i].f]=r[hull[i].f]=hull[i].f;
	}
	l[n+1] = r[n+1] = hull.back().f;
	for(int i = 1; i <= n; i++)
	{
		if(l[i] == r[i])
		{
			cout << 100000ll * f[i] << endl;
		} else 
		{
			cout << 100000ll * ((r[i]-i)*f[l[i]] + (i-l[i])*f[r[i]])/(r[i]-l[i]) << endl;
		}
	}
}
