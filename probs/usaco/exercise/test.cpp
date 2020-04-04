#include <bits/stdc++.h>

using namespace std;

string ans[10005];
int main()
{
	freopen("test.in", "r", stdin);
	freopen("array.txt", "w", stdout);
	for(int i = 0; i <= 10000; i++)
	{
		int ind;
		cin >> ind >> ans[i];
	}
	cout << "[";
	for(int i = 0; i < 10000; i++) cout << ans[i] << ",";
	cout << ans[10000] << "]";
}