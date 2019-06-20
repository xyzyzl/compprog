//============================================================================
// Name        : B.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Polycarp owns a membrane keyboard and can't type correctly
//             : Therefore he must have just typed repetitions. If it fails to reach
//             : The frequency of the guess, the guess must have been wrong
//============================================================================

#include <iostream>
#include <string>
#include <map>
#include <algorithm>
using namespace std;

int n;
string s1, s2;
map<int, int> m1, m2;
int main() {
	cin >> n;
	for(int T = 0; T < n; T++) {
		bool yes = true;
		m1.clear();
		m2.clear();
		cin >> s1 >> s2;
		if(s1.length() > s2.length()) {
			cout << "NO" << endl;
			continue;
		}
		for(int i = 0; i < s1.length(); i++) {
			m1[s1[i]]++;
			m2[s2[i]]++;
		}
		for(int i = 0, j = 0; i < s1.length() && j < s2.length(); i++) {
			char c = s1[i];
			int c1 = 0;
			while(i < s1.length() && s1[i] == c) {
				// cout << c << " " << s1[i] << endl;
				i++;
				c1++;
			}
			i--;
			// cout << j << endl;
			int c2 = 0;
			while(c == s2[j]) {
				c2++;
				j++;
			}
			// cout << c1 << " " << c2 << endl;
			if(c1 > c2) {
				cout << "NO" << endl;
				yes=false;
				break;
			}
		}
		if(!yes) continue;
		for(int i = s1.length(); i < s2.length(); i++){
			if(m1[s2[i]] == 0) {
				cout << "NO" << endl;
				yes = false;
				break;
			}
			m2[s2[i]]++;
		}
		if(!yes) continue;
		auto t1 = unique(s1.begin(), s1.end());
		string a = string(s1.begin(), t1);
		auto t2 = unique(s2.begin(), s2.end());
		string b = string(s2.begin(), t2);
		if(a==b) {
			cout << "YES" << endl;
		}
		else {
			cout << "NO" << endl;
		}
	}
	return 0;
}
