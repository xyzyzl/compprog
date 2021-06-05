#include <string>

using namespace std;

// z algorithm for longest common prefix
// could also use hash
void za()
{
	string c = S+"$"+A;
	vector<int> Z(c.length());
	for(int i = 1, l = 0, r = 0; i < c.length(); i++)
	{
		if(i <= r) Z[i] = min(r-i+1, Z[i-l]);
		while(i+Z[i] < c.length() && c[Z[i]] == c[i+Z[i]]) ++Z[i];
		if(i+Z[i]-1 > r) l=i, r=i+Z[i]-1;
	}
}
