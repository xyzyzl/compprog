#include <bits/stdc++.h>

using namespace std;

int main()
{
	int a,b,c,d;
	cin >> a >> b >> c >> d;
	vector<int> ps(2000005);
	for(int x = a; x <= b; x++)
	{
		ps[x+b] += 1;
		ps[x+c+1] += -1;
	}
	for(int i = 1; i <= 2000000; i++) ps[i] += ps[i-1];
	long long ans = 0;
	for(int i = a+b; i <= b+c; i++)
	{
		ans += (long long)max(0, min(d-c+1, i-c)) * (ps[i]);
	}
	cout << ans << endl;
}
