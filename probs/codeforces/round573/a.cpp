#include <iostream>

using namespace std;

int x;
int main()
{
    cin >> x;
    int r = x%4;
    if(r==3 || r==0 || r==1)
    {
        cout << abs(r-1) << " A";
    } else 
    {
        cout << "1 B";
    }
}