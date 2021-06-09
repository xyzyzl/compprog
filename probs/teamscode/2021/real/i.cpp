#include <bits/stdc++.h>

using namespace std;

int N;
int win[20210425];
int main()
{
	for(int i = 0; i <= 20210300; i++) win[i] = -1;
	for(int i = 20210301; i < 20210425; i++) win[i] = 2;
	win[20210423] = 1;
	win[20210301] = 1;
	for(int i = 20210300; i >= 1; i--)
	{
		if(win[i+123] == 1 && win[i+1] == 1) win[i] = 0;
		if(win[i+123] == 0) win[i] = 1;
		if(win[i+1]   == 0) win[i] = 1;
	}
	cin >> N;
	for(int i = 0; i < N; i++)
	{
		int k; cin >> k;
		cout << (win[k] == 1 ? "Yes" : "No") << endl;
	}
}
