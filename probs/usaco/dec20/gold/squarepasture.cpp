#include <bits/stdc++.h>

using namespace std;

int N;
typedef pair<int, int> pii;
#define f first
#define s second
pii arr[205];

int main()
{
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> arr[i].f >> arr[i].s;
	}
	int ans = N + 1;
	int dc = 0;
	for (int WOW = 0; WOW < 2; WOW++)
	{
		sort(arr, arr + N);
		for (int i = 0; i < N; i++)
		{
			set<int> ys;
			for (int j = i + 1; j < N; j++)
			{
				if (j - 1 > i)
					ys.insert(arr[j - 1].s);
				int yL = min(arr[i].s, arr[j].s), yH = max(arr[i].s, arr[j].s);
				int sl = arr[j].f - arr[i].f;
				int lo = yH - sl, hi = yL;
				if (lo > hi)
					continue;
				vector<int> yv;
				for (int x : ys)
					yv.push_back(x);
				int l = 0, r = -1;
				while (l < yv.size() && yv[l] < lo)
					l++;
				while (r+1 < yv.size() && yv[r + 1] <= lo + sl)
					r++;
				while (true)
				{
					ans++;
					int a = yL, b = yH;
					if (l <= r)
					{
						a = min(a, yv[l]);
						b = max(b, yv[r]);
					}
					if (b - a == sl)
						dc++; // this will be double counted
					// move up one
					int bup = INT_MAX, tup = INT_MAX;
					if (l < yv.size())
						bup = yv[l] + 1;
					if (r+1 < yv.size())
						tup = yv[r + 1]-sl;
					if (min(bup, tup) > hi)
						break;
					l += (bup<=tup);
					r += (bup>=tup);
				}
			}
		}
		for(int i = 0; i < N; i++) swap(arr[i].f, arr[i].s);
	}
	cout << ans - dc / 2 << endl;
}