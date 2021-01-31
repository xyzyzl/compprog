#include <bits/stdc++.h>

using namespace std;
using ll=long long;

ll kp10[19];
ll p10[19];
int main()
{
	for(int i = 1; i < 19; i++)
	{
		kp10[i] = 9*i;
		p10[i] = 9;
		for(int j = 1; j < i; j++)
		{
			kp10[i] *= 10ll;
			p10[i]  *= 10ll;
		}
	}
	int q; cin >> q;
	while(q--)
	{
		ll k; cin >> k;
		ll a = 0, b = 0;
		int w = 0;
		for(int i = 1; i < 19; i++)
		{
			b += p10[i];
			a += kp10[i];
			if(a >= k)
			{
				a -= kp10[i];
				b -= p10[i];
				w = i;
				break;
			}
		}
		ll x = k-a;
		ll real = b + ceil((long double)x/w);
		int pos = x%w;
		if(!pos) pos = w;
		cout << to_string(real)[pos-1] << endl;
	}
}
