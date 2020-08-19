#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;
#define f first
#define s second

int main()
{
	int t;
	cin >> t;
	while(t--)
	{
		int n, x;
		cin >> n >> x;
		map<int, int> thing;
		for(int i = 0; i < n; i++)
		{
			int ha;
			cin >> ha;
			thing[ceil((double)x / (double)ha)]++;
		}
		int rem = 0, ans = 0;
		for(auto g : thing)
		{
			int div = g.f;
			int val = g.s + rem;
			ans += val/div;
			rem = val%div;
		}
		cout << ans << endl;
	}
}
