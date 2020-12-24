#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <climits>
#include <cmath>

using namespace std;
#define int long long

int N, L;
typedef pair<int, int> pii;
#define f first
#define s second
#define pb push_back
pii pts[2005], O;

int dist_2(pii p1, pii p2)
{
	return (((int)p1.f - p2.f) * (p1.f - p2.f) + ((int)p1.s - p2.s) * (p1.s - p2.s));
}

int orientation(pii p, pii q, pii r)
{
	int val = (q.s - p.s) * (r.f - q.f) - (q.f - p.f) * (r.s - q.s);
	if (val == 0)
		return 0;
	return (val > 0) ? 1 : 2;
}

bool comp(pii a, pii b)
{
	int x = orientation(O, a, b);
	if (x == 0)
	{
		return (dist_2(O, b) >= dist_2(O, a));
	}
	return (x == 1);
}

bool c2(pii a, pii b)
{
	if(a.s == b.s) return a.f < b.f;
	return a.s < b.s;
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
	int ymin = pts[0].f, mn = 0;
	for(int i = 1; i < N; i++)
	{
		int y = pts[i].s;
		if((y < ymin) || (y == ymin && pts[i].f < pts[mn].f)) 
		{
			ymin = y;
			mn = i;
		}
	}
	swap(pts[0], pts[mn]);
	O = pts[0];
	sort(pts + 1, pts + N, comp);

	int m = 1;
	for (int i = 1; i < N; i++)
	{
		while (i < N-1 && orientation(O, pts[i], pts[i + 1]) == 0)
			i++;
		pts[m] = pts[i];
		++m;
	}
	if (m < 3)
	{
		for (int i = 0; i < m; i++)
		{
			hull.pb(pts[i]);
		}
		return;
	}
	stack<pii> st;
	st.push(pts[0]);
	st.push(pts[1]);
	st.push(pts[2]);
	for (int i = 3; i < m; i++)
	{
		while (st.size() >= 2 && orientation(sec_to_top(st), st.top(), pts[i]) != 1)
		{
			st.pop();
		}
		st.push(pts[i]);
	}
	while (!st.empty())
	{
		hull.pb(st.top());
		st.pop();
	}
}

const long double PI = 3.141592653589;
signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N >> L;
	for (int i = 0; i < N; i++)
	{
		cin >> pts[i].f >> pts[i].s;
		pts[i].f += 10001;
		pts[i].s += 10001;
	}
	hull.clear();
	convex();
	int M = hull.size();
	long double X = 2 * PI * L; // create a full circle of radius L with the rounded parts of the walls
	for(int i = 0; i < M; i++)
	{
		// cerr << "dbg: " << hull[i].f << " " << hull[i].s << endl;
		long double A = sqrt(dist_2(hull[i], hull[(i+1)%M])); // add the lengths of the hull as is
		X += A;
	}
	cout << (int)(X+0.5) << endl;
}