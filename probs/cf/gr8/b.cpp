#include <bits/stdc++.h>
using namespace std;

int main()
{
	long long k;
	cin >> k;
	long long pr = 0;
	int ind = 0;
	vector<int> a(10, 1);
	while(pr < k)
	{
		pr = 1;
		for(int i = 0; i < 10; i++)
		{
			pr *= a[i];
		}
		if(pr >= k) break;
		a[ind++]++;
		ind %= 10;
	}
	string s = "codeforces";
	for(int i = 0; i < 10; i++)
	{
		for(int j = 0; j < a[i]; j++) cout << s[i]; 
	}
	cout << endl;
}
