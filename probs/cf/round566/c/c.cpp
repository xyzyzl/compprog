// c.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <string>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <vector>

using namespace std;
int n;
bool vowel(char c) {
	return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
}
map<int, vector<string>[5] > thing;
vector<pair<string, string> > good_boys;
vector<pair<string, string> > very_good_boys;
int main() {
	cin >> n;
	int mc = 0;
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		int vcnt = 0;
		for (int i = 0; i < s.length(); i++) {
			if (vowel(s[i])) vcnt++;
		}
		mc = max(vcnt, mc);
		for (int i = s.length() - 1; i >= 0; i--) {
			if (vowel(s[i])) {
				switch (s[i]) {
				case 'a': thing[vcnt][0].push_back(s); break;
				case 'e': thing[vcnt][1].push_back(s); break;
				case 'i': thing[vcnt][2].push_back(s); break;
				case 'o': thing[vcnt][3].push_back(s); break;
				case 'u': thing[vcnt][4].push_back(s); break;
				}
				break;
			}
		}
	}

	// int ct = n;
	for (auto& a : thing) {
		// cout << a.first << endl;
		for(int i = 0; i < 5; i++) {
			vector<string>& hot = a.second[i];
			while (hot.size() >= 2) {
				// (a.first == 4) cout << "yesa" << endl;
				string s1, s2;
				s1 = hot.back(); hot.pop_back();
				s2 = hot.back(); hot.pop_back();
				very_good_boys.push_back(make_pair(s1, s2));
			}
		}
		vector<string> veryhot;
		for (int i = 0; i < 5; i++) {
			vector<string> hot = a.second[i];
			for (auto& cool : hot) veryhot.push_back(cool);
			a.second[i].clear();
			hot.clear();
		}
		while (veryhot.size() >= 2) {
			string s1, s2;
			s1 = veryhot.back(); veryhot.pop_back();
			s2 = veryhot.back(); veryhot.pop_back();
			good_boys.push_back(make_pair(s1, s2));
		}
	}
	vector<pair<string, string> > b;
	while (good_boys.size() && very_good_boys.size()) {
		b.push_back(make_pair(good_boys.back().first, very_good_boys.back().first));
		b.push_back(make_pair(good_boys.back().second, very_good_boys.back().second));
		good_boys.pop_back(); very_good_boys.pop_back();
	}

	while (very_good_boys.size() > 1) {
		pair<string, string> despacito1 = very_good_boys.back(); very_good_boys.pop_back();
		pair<string, string> despacito2 = very_good_boys.back(); very_good_boys.pop_back();
		b.push_back(make_pair(despacito1.first, despacito2.first));
		b.push_back(make_pair(despacito1.second, despacito2.second));
	}

	cout << b.size() / 2 << endl;
	for (auto& w : b) {
		cout << w.first << " " << w.second << endl;
	}
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
