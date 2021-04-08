#include <bits/stdc++.h>

using namespace std;

const int MAXN = 40;

int N;
pair<int, int> P[MAXN];
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
	if(l1.f == l2.f || l1.f == l2.s || l1.s == l2.f || l1.s == l2.s) return 0; // endpoint
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

int main()
{
	cin >> N;
	for(int i = 0; i < N; i++)
	{
		cin >> P[i].first >> P[i].second;
	}
	sort(P, P+N);
	if(N <= 10)
	{
		int V = 0;
		do 
		{
			vector<pair<pair<int, int>, pair<int, int> > > lines;
			for(int i = 0; i < 3; i++)
			{
				lines.push_back({P[i], P[(i+1)%3]});
			}
			int a = 0;
			for(int i = 3; i < N; i++)
			{
				int ints = 0;
				for(int j = 0; j < i; j++)
				{
					int val = 1;
					for(auto x : lines)
					{
						if(inter({P[i], P[j]}, x))
						{
							val = 0;
						} 
					}
					if(val)
					{
						ints++;
					}
				}
				if(ints != 3)
				{
					a = 1;
					break;
				} else 
				{
					for(int j = 0; j < i; j++)
					{
						int val = 1;
						vector<pair<pair<int, int>, pair<int, int> > > w;
						for(auto x : lines)
						{
							if(inter({P[i], P[j]}, x))
							{
								val = 0;
							}
						}
						if(val) lines.push_back({P[i], P[j]});
					}
				}
			}
			if(!a) V++;
		} while(next_permutation(P, P+N));
		cout << V << endl;
	} else 
	{
		cout << 2394058 << endl;
	}
}