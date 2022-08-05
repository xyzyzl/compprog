#include <iostream>
#include <string>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);
	int n; cin >> n;
	string s; cin >> s;
	char prec = 0;
	for(int i = 0; i < 2*n; i+=2)
	{
		char greg = 0;
		int k = s[i] - 'A';
		int l = s[i+1] - 'A';
		for(int j = 0; j < 4; j++)
		{
			if(j != k && j != l)
			{
				if(prec == (j+'A')) continue;
				cout << (char)(j + 'A');
				greg = j+'A';
			}
		}
		for(int j = 0; j < 4; j++)
		{
			if(j != k && j != l)
			{
				if(prec != (j+'A')) continue;
				cout << (char)(j + 'A');
				greg = j+'A';
			}
		}
		prec = greg;
	}
	cout << endl;
	return 0;
}