#include <bits/stdc++.h>

using namespace std;

int n,m;
set<int> h;
pair<int, pair<int, int> > lines[200005];
#define f first
#define s second
int main()
{
	cin >> n >> m;
	for(int i = 0; i < n; i++)
	{
		int x,y;
		cin >> lines[i].s.f >> x >> y;
		if(x == 0)
		{
			lines[i].f = y;
			lines[i].s.s = 0;
		}
	}
}
