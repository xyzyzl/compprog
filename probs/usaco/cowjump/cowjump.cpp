// observation: between an intersection of two segments one intersection must carry all of the intersections.
// then find which one intersects more other line segments. if there is an equal amount (which must be 1), pick
// the one with the smaller index.
// use sweepline to find any intersection.
// be careful when using (multi) set to find intersecting lines, and also ensure that the start point of each line is considered first in the sweep.
#include <bits/stdc++.h>

#define int long long
using namespace std;

#define f first
#define s second

bool on(pair<int, int> p, pair<int, int> q, pair<int, int> r)
{
	if (q.f <= max(p.f, r.f) && q.f >= min(p.f, r.f) &&
		q.s <= max(p.s, r.s) && q.s >= min(p.s, r.s))
		return true;

	return false;
}

int ort(pair<int, int> p, pair<int, int> q, pair<int, int> r)
{
	int val = (q.s - p.s) * (r.f - q.f) - (q.f - p.f) * (r.s - q.s);
	if (val == 0)
		return 0;
	return (val > 0) ? 1 : 2;
}

bool inter(pair<pair<int, int>, pair<int, int> > l1, pair<pair<int, int>, pair<int, int> > l2)
{
	int o1 = ort(l1.f, l1.s, l2.f);
	int o2 = ort(l1.f, l1.s, l2.s);
	int o3 = ort(l2.f, l2.s, l1.f);
	int o4 = ort(l2.f, l2.s, l1.s);
	if (o1 != o2 && o3 != o4)
		return 1;
	if(!o1 && on(l1.f, l2.f, l1.s)) return 1;
	if(!o2 && on(l1.f, l2.s, l1.s)) return 1;
	if(!o3 && on(l2.f, l1.f, l2.s)) return 1;
	if(!o4 && on(l2.f, l1.s, l2.s)) return 1;
	return 0;
}

signed main()
{
	freopen("cowjump.in", "r", stdin);
	freopen("cowjump.out", "w", stdout);
	int n;
	cin >> n;
	// cerr << inter(make_pair(make_pair(1, 2), make_pair(1, 3)), make_pair(make_pair(0, 1), make_pair(2, 2))) << endl;
	vector<pair<pair<int, int>, pair<int, int>>> lns(n);
	vector<pair<pair<int, int>, pair<int, int>>> pts;
	for (int i = 0; i < n; i++)
		cin >> lns[i].f.f >> lns[i].f.s >> lns[i].s.f >> lns[i].s.s;
	for (int i = 0; i < n; i++)
	{
		pts.push_back(make_pair(make_pair(lns[i].f.f, lns[i].f.s), make_pair(i, 0)));
		pts.push_back(make_pair(make_pair(lns[i].s.f, lns[i].s.s), make_pair(i, 1)));
	}
	sort(pts.begin(), pts.end());
	multiset<pair<pair<pair<int, int>, pair<int, int> >, int > > h;
	int p=0,q=0;
	for (int i = 0; i < 2 * n; i++)
	{
		pair<pair<int, int>, pair<int, int> > L = lns[pts[i].s.f];	
		pair<pair<pair<int, int>, pair<int, int> >, int> P = make_pair(L, pts[i].s.f);
		if (!pts[i].s.s) // needs to be inserted before remove. the "start" one is always placed after, for some reason.
		{
			h.insert(P);
			auto it = h.find(P);
			if((it != h.begin()) && inter(L, prev(it)->f))
			{
				p = min(pts[i].s.f, prev(it)->s);
				q = max(pts[i].s.f, prev(it)->s);
				break;
			}
			it = h.upper_bound(P);
			if((it != h.end()) && inter(L, it->f))
			{
				p = min(pts[i].s.f, it->s);
				q = max(pts[i].s.f, it->s);
				break;
			}
		}
		else
		{
			// cerr << (P.f == lns[P.s]) << endl;
			auto i1 = h.upper_bound(P);
			if(h.find(P) == h.begin())
			{
				h.erase(P);
				continue;
			}
			auto i2 = prev(h.find(P));
			if(i1 != h.end() && i1 != i2 && inter(i1->f, i2->f))
			{
				// cerr << "mmm" << endl;
				p = min(i1->s, i2->s);
				q = max(i1->s, i2->s);
				break;
			}
			h.erase(P);
		}
	}
	// cerr << p << " " << q << endl;
	int ip=0,iq=0;
	for(int i = 0; i < n; i++)
	{
		if(i != p)
		{
			ip += inter(lns[i], lns[p]);
		}
		if(i != q)
		{
			iq += inter(lns[i], lns[q]);
		}
	}
	if(ip < iq) cout << 1+q << endl;
	else cout << 1+p << endl;
}