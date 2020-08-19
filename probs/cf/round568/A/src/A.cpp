//============================================================================
// Name        : A.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int a, b, c, d;
int main() {
	cin >> a >> b >> c >> d;
	vector<int> v;
	v.push_back(a);
	v.push_back(b);
	v.push_back(c);
	sort(v.begin(), v.end());
	int j = v[1];
	int tmw_orz = 0;
	if(j-v[0]<d) {
		tmw_orz += d-(j-v[0]);
	}
	if(v[2]-j<d) {
		tmw_orz += d-(v[2]-j);
	}
	cout << tmw_orz << endl;
	return 0;
}
