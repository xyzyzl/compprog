#include <iostream>

using namespace std;

int main()
{
    int n;
    cin>>n;
    int t=1;
    for(int i = 1; i < n; i++)
    {
        t += 4*i;
    }
    cout<<t<<endl;
}