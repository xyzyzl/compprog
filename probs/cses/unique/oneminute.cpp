// 1:25 impl

#include <iostream>
#include <set>

using namespace std;

int n;
int main() {
	cin >> n;
    set<int> s;
	for(int i = 0; i < n; i++)
    {
        int a; cin >> a;
        s.insert(a);
    }
    cout << s.size() << endl;
}