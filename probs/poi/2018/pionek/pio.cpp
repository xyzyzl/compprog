#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;
#define f first
#define s second

const int MAXN = 200005;
const double PI = 3.14159265;

int n;
// so using this as a separate pii array and double array led to
// a segmentation fault, but putting them together in a struct made
// it work.
struct abc
{
	pii vec;
	double val;
} k[MAXN*2];

bool comp(abc a, abc b)
{
	return a.val < b.val;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n;
	for(int i = 0; i < n; i++)
	{
		int a, b; cin >> a >> b;
		k[i].vec = {a, b};
		k[i].val = atan2(b, a);
	}
	sort(k, k+n, comp);
	int j = 0;
	// given a point i, only rotating up to 180 degrees from i will actually
	// contribute in any way to making it farther. we can include anything and everything up to then
	ll sx = 0, sy = 0, ans = 0;
	for(int i = 0; i < n; i++)
	{
		while(j < i+n && k[j].val - k[i].val < PI)
		{
			sx += k[j].vec.f;
			sy += k[j].vec.s;
			ans = max(ans, sx*sx+sy*sy);
			++j;
		}
		sx -= k[i].vec.f;
		sy -= k[i].vec.s;
		ans = max(ans, sx*sx+sy*sy);
		k[i+n] = k[i];
		k[i+n].val = k[i].val+2.0*PI; // add another wrap around with the vectors
	}
	cout << ans << endl;
}
