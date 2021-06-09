#include <bits/stdc++.h>

using namespace std;

int que(int t, int i, int j, int x)
{
	cout << "? " << t << " " << i+1 << " " << j+1 << " " << x << endl;
	cout.flush();
	int ret; cin >> ret;
	return ret;
}

void solve()
{
	int n;
	cin >> n;
	int best = -1;
	for(int i = 0; i+1 < n; i += 2)
	{
		int x = que(1, i, i+1, n-1);
		if(x == n)
		{
			best = i+1;
			break;
		} else if(x == n-1)
		{
			if(que(1, i+1, i, n-1) == n)
			{
				best = i;
				break;
			}
		}
	}
	if(best == -1) best = n-1;
	vector<int> p(n);
	p[best] = n;
	for(int i = 0; i < n; i++)
	{
		if(i == best) continue;
		p[i] = que(2, i, best, 1);
	}
	cout << "! ";
	for(int i = 0; i < n; i++)
	{
		cout << p[i] << " ";
	}
	cout << endl;	
	cout.flush();
}

int main()
{
	int T; cin >> T;
	while(T--) solve();
}