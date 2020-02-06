#include <bits/stdc++.h>

using namespace std;

int main()
{
  string s;
  cin >> s;
  for(int i = 0; i < s.length(); i++)
  {
    if(i % 2) if(s[i] == 'R') {
	cout << "No" << endl;
	return 0;
      }
    if(i % 2 == 0) if(s[i] == 'L') {
	cout << "No" << endl;
	return 0;
      }
  }
  cout << "Yes" << endl;
}
