/*input
2
*/

#include <bits/stdc++.h>
using namespace std;

const int MAXN = 65540;

int n, vis[MAXN];
signed main()
{
	cin >> n;
	// small n = brute force is possible
	for(int i = 0; i < n; i++)
	{
		cout << 0;
	}
	cout << endl;
	vis[0] = 1;
	int x = 0;
	for(int i = 1; i < (1 << n); i++)
	{
		for(int j = 0; j < n; j++)
		{
			int k = x^(1 << j);
			if(!vis[k])
			{
				x=k;
				vis[k] = 1;
				// need to manually output x
				for(int j = n-1; j >= 0; j--) if(x & (1 << j)) cout << 1; else cout << 0;
				cout << endl;
				break;  
			}
		}
	}
}