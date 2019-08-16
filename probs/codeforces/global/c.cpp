#include <bits/stdc++.h>

using namespace std;

int n;
int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int s;
        cin >> s;
        const int len = floor(log2(s)) + 1;
        bitset<26> bs = bitset<26>(s);
        string n = bs.to_string();
        // cout << n << endl;
        int ones = 0;
        for(int i = 0; i < n.length(); i++) if(n[i] == '1') ones++;
        if(ones == len)
        {
            // cout << "m" << endl;
            int smallest = 1;
            for(int i = 2; i*i <= s; i++)
            {
                if((s/i)*i == s)
                {
                    smallest = i;
                    // cout << "w" << endl;
                    break;
                }
            }
            if(smallest == 1) cout << 1 << endl;
            else cout << s/smallest << endl;
            // cout << "j" << endl;
        } else 
        {
            cout << (1 << len)-1 << endl;
        }
    }
}