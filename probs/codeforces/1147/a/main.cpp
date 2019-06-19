#include <iostream>

using namespace std;

int x, y, z;
int main() {
    cin >> x >> y >> z;
    if(x > y+z) cout << "+";
    else if (y > x+z) cout << "-";
    else if (x==y && z == 0) cout << "0";
    else cout << "?";
    return 0;
}