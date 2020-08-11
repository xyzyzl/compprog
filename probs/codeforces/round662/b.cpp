#include <bits/stdc++.h>

using namespace std;

int n, q, num[100005];
int main()
{
	cin >> n;
	for(int i = 0; i < n; i++)
	{
		int a;
		cin >> a;
		num[a]++;
	}
	cin >> q;
	int can_sq = 0, can_rc = 0;
	for(int i = 1; i < 100005; i++)
	{
		can_rc += (num[i]/2);
		if(num[i] >= 4) can_sq++;
	}
	// cout << can_rc << " " << can_sq << endl;
	while(q--)
	{
		char c;
		int b;
		cin >> c >> b;
		if(c == '+')
		{
			int pre = num[b];
			num[b]++;
			if(pre < 4 && num[b] >= 4) can_sq++;
			if(!(num[b]%2)) can_rc++;
		} else
		{
			int pre = num[b];
			num[b]--;
			if(num[b] < 4 && pre >= 4) can_sq--;
			if(num[b]%2) can_rc--;
		}
		if(can_rc >= 4 && can_sq) cout << "YES" << endl;
		else cout << "NO" << endl;
	}
}
