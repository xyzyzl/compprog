#include <bits/stdc++.h>

using namespace std;

int N, K;
string S;
void solve()
{
	cin >> N >> K;
	cin >> S;
	int a = 0, b = 0;
	for(int i = 0; i < N; i++)
	{
		if(S[i] == '*')
		{
			a = i;
			break;
		}
	}
	for(int i = N-1; i >= 0; i--)
	{
		if(S[i] == '*')
		{
			b = i;
			break;
		}
	}
	int x = a;
	int md = 0;
	int ct = 1;
	while(x < b)
	{
		int y = x+K;
		int z = x+1;
		for(int i = y; i >= x; i--)
		{
			if(S[i] == '*')
			{
				z=i;
				break;
			}
		}
		x=z;
		++ct;
	}
	cout << ct << endl;
}

int main()
{
	int t; cin >> t;
	while(t--) solve();
}
