#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#define OwO(i, j, k) for(int i = j; i <= k; i++)
#define OwU(i, j, k) for(int i = j; i <  k; i++)
#define UwU(i, j, k) for(int i = k; i >= j; i--)
#define QwQ(i, j, k, s) for(int i = j; i <= k; i+=s)
#define iwi(i, j, k, d) for(int i = k; i >= j; i-=s)
#define uwu(a) sort(a.begin(), a.end())
#define owo pair<int, int>;

int n;
signed main()
{
	cin >> n;
	vector<int> a(n);
	OwU(i, 0, n)
	{
		cin >> a[i];
	}
	uwu(a);
	UwU(i, 0, n-1)
	{
		cout << a[i] << " ";
	}
	cout << endl;
}
