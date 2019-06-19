#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;
int n;
string s[100005];
map< pair<int, char> , vector<string> > fcnt;
map< int , vector<string> > vcnt;
bool isvowel(char c) {
	return (c=='a'||c=='e'||c=='i'||c=='o'||c=='u');
}
pair<int, char> arr[100005];
int main() {
	cin >> n;
	for(int i = 0; i < n; i++) {
		cin >> s[i];
		int v=0;
		for(int j = 0; j < s[i].length(); j++) {
			if(isvowel(s[i][j])) v++;
		}
		vcnt[v].push_back(s[i]);
		char last=0;
		for(int j = s[i].length()-1; j >= 0; j--) {
			if(isvowel(s[i][j])) {
				last = s[i][j];
				break;
			}
		}
		fcnt[make_pair(v, last)].push_back(s[i]);
		arr[i] = make_pair(v, last);
	}

	vector<string> v[4];

	for(int i = 0; i < n; i++) {
		if(vcnt[arr[i].first].size() < 2) continue;
		vcnt[arr[i].first].erase(find(vcnt[arr[i].first].begin(), vcnt[arr[i].first].end(), s[i]));
		fcnt[arr[i]].erase(find(fcnt[arr[i]].begin(), fcnt[arr[i]].end(), s[i]));
		v[0].push_back(s[i]);
	}

	return 0;
}