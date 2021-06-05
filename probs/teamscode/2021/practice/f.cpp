#include <bits/stdc++.h>

using namespace std;
#define int long long

const int MAXN = 105;

int n, a[MAXN], b[MAXN], u[MAXN];
map<int, int> M;
signed main()
{
	cin >> n;
	int ct = 0;
	set<int> S;
	for(int i = 0; i < n; i++)
	{
		cin >> a[i];
		S.insert(a[i]);	
	}
	for(int x : S) M[x] = ct++;
	for(int i = 0; i < n; i++)
		cin >> b[i];
	long long ret = 0;
	for(int i = 0; i < n; i++)
	{
		int z = -1;
		int val = -1;
		int tm = INT_MAX;
		for(int j = 0; j < n; j++) if(M[a[j]] >= i && !u[j])
		{
			if(tm > M[a[j]])
			{
				tm = M[a[j]];
				val = b[j];
				z = j;
			} else if(tm == M[a[j]])
			{
				if(val < b[j])
				{
					val = b[j];
					z = j;
				}
			}
		}
		// cerr << z << " " << val << endl;
		u[z] = 1;
		ret += val;
	}
	cout << ret << endl;
}
