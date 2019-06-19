#include <iostream>

using namespace std;

int n;
int main() {
    cin >> n;
    int m = n/2+1;
    cout << m << endl;
    for(int i = 1; i <= m; i++) cout << i << " 1\n";
    for(int i = 2; i <= n-m+1; i++) cout << m << " " << i << endl;
    return 0;
}