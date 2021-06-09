#include <bits/stdc++.h>

using namespace std;

int n;
int main()
{
	cin >> n;
	map<int, int> facts;
	for(int i = 2; i <= sqrt(n); i++)
	{
		while(n % i == 0)
		{
			n /= i;
			facts[i]++;
		}
	}
	if(n != 1) facts[n]++;
	for(pair<int, int> x : facts) cout << x.first << " " << x.second << endl;
}
