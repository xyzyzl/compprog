#include <bits/stdc++.h>

using namespace std;

void rec(int a, int b, int c, int n)
{
	if(n-1)
		rec(a, c, b, n-1);
	cout << a << " " << c << endl;
	if(n-1)
		rec(b, a, c, n-1);
}

int main()
{
	int n; cin >> n;
	cout << (1 << n)-1 << endl;
	rec(1,2,3,n);
}
