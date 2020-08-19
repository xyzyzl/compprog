#include <bits/stdc++.h>

using namespace std;

int n;
long long l, r;
int main()
{
	int t;
	cin >> t;
	while(t--)
	{
		cin >> n >> l >> r;
		long long steps = 1;
		int ind = 1;
		while(ind < n && steps <= l - 2*(n-ind))
		{
			steps += 2*(n-ind);
			ind++;
		}
		// cout << ind << endl;
		vector<int> v;
		while(ind < n && steps <= r)
		{
			for(int x = ind + 1; x <= n; x++)
			{
				if(steps >= l && steps <= r)
					cout << ind << " ";
				steps++;
				if(steps >= l && steps <= r)
					cout << x << " ";
				steps++;
			}
			ind++;
		}
		if(steps <= r)
		{
			cout << 1;
		}
		cout << endl;
	}
}
