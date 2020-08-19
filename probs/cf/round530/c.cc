#include <bits/stdc++.h>

using namespace std;

string s;
int k, len, cc, sf;

int main()
{
    cin >> s >> k;
    for(int i = 0; i < s.length(); i++)
    {
        if(s[i] != '*' && s[i] != '?') len++;
        else if(s[i] == '*') sf++;
        else cc++;
    }
    if(len-k > cc+sf || (len<k&&!sf))
    {
        cout << "Impossible";
    } else
    {
        if(len==k) for(int i = 0; i < s.length(); i++)
        {
            if(s[i] != '*' && s[i] != '?') cout << s[i];
        } else if(len > k)
        {
            int ct = len-k;
            for(int i = 0; i < s.length(); i++)
            {
                if(ct && (i+1 < s.length() && (s[i+1]=='?'||s[i+1]=='*')))
                {
                    ct--;
                    continue;
                }
                if(s[i] == '?' || s[i] == '*') continue;
                cout << s[i];
            }
        } else 
        {
            bool bb = 0;
            for(int i = 0; i < s.length(); i++)
            {
                if(!bb && (i+1 < s.length() && (s[i+1] == '*')))
                {
                    bb=1;
                    for(int j = 0; j < k-len+1; j++) cout << s[i];
                } else if(s[i] != '?' && s[i] != '*') cout << s[i];
            }
        }
    }
    
}