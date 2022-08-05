#include <bits/stdc++.h>

using namespace std;

int main()
{
	int n; cin >> n;
	freopen("test.txt", "w", stdout);
	cout << n << endl;
	srand(time(NULL));
	for(int i = 0; i < n; i++)
	{
		cout << (-100000 + (rand() % 200000)) << " " << (-100000 + (rand() % 200000)) << endl;
	}
}