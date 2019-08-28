#include <bits/stdc++.h>

using namespace std;

int main()
{
    string s;
    cin >> s;
    if(s=="0")
    {
        cout << 0 << endl;
        return 0;
    }
    int num_of_one = 0;
    for(int i = 0; i < s.length(); i++)
    {
        if(s[i] == '1') num_of_one++;
    }
    int w = (num_of_one==1 && s.length()%2==1);
    cout << (s.length()+1)/2 - w << endl;
}