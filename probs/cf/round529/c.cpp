#include <bits/stdc++.h>

using namespace std;

int n, k;
int s[32];
int main()
{
    cin >> n >> k;
    string bin;
    bitset<31> bs(n);
    bin = bs.to_string();
    // cout << bin << endl;
    int ct = 0; 
    for(int i = 0; i < bin.size(); i++)
    {
        ct += bin[i]=='1';
        s[bin.size()-1-i] += bin[i]=='1';
    }
    // cout << ct << endl;
    if(ct > k || n < k)
    {
        cout << "NO";
    } else 
    {
        for(int i = bin.size(); i >= 1; i--)
        {
            if(!s[i]) continue;
            if(k - ct <= s[i])
            {
                // cout << i << endl;
                int x = k-ct;
                ct += x;
                s[i] -= x;
                s[i-1] += 2*x;
                break;
            }
            else
            {
                // cout << "k" << endl;
                ct += s[i];
                s[i-1] += 2*s[i];
                s[i] = 0;
            }
        }
        cout << (ct == k ? "YES" : "NO") << endl;
        if(ct == k)
        {
            for(int i = 0; i < bin.size(); i++)
            {
                // cout << s[i] << endl;
                for(int j = 0; j < s[i]; j++)
                {
                    cout << (1 << i) << " ";
                }
            }
        }
    }
}