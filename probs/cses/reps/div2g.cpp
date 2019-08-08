#include <iostream>
#include <string>

using namespace std;

string s;
int main()
{
	cin >> s;
	int ct=0, bct=0;
	for(int i = 0; i < s.length(); i++)
	{
		if(i==0 || s[i] != s[i-1])
		{
			bct = max(bct, ct);
			ct = 1;
		} else
		{
			ct++;
		}
	}
	bct = max(bct, ct);
	cout << bct;
}