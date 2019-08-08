#include <bits/stdc++.h>

using namespace std;

int a, b, c;
int m[11], p[11], s[11];
int main()
{
    char k;
    cin >> a >> k;
    switch(k)
    {
        case 'm': m[a]++;
            break;
        case 'p': p[a]++;
            break;
        case 's': s[a]++;
            break;
        default: break;
    }
    cin >> b >> k;
    switch(k)
    {
        case 'm': m[b]++;
            break;
        case 'p': p[b]++;
            break;
        case 's': s[b]++;
            break;
        default: break;
    }
    cin >> c >> k;
    switch(k)
    {
        case 'm': m[c]++;
            break;
        case 'p': p[c]++;
            break;
        case 's': s[c]++;
            break;
        default: break;
    }
    int mn = 2;
    for(int i = 1; i < 10; i++) 
    {
        int j = 2;
        if(m[i])
        {
            if(m[i-1]) j--;
            if(m[i+1]) j--;
        } else
        {
            if(m[i-1] && m[i+1]) j--;
        }
        if(m[i] == 3) j = 0;
        if(m[i] == 2) j = min(j, 1);
        mn = min(mn, j);
    }
    for(int i = 2; i < 9; i++) 
    {
        int j = 2;
        if(p[i])
        {
            if(p[i-1]) j--;
            if(p[i+1]) j--;
        } else
        {
            if(p[i-1] && p[i+1]) j--;
        }
        if(p[i] == 3) j = 0;
        if(p[i] == 2) j = min(j, 1);
        mn = min(mn, j);
    }
    for(int i = 2; i < 9; i++) 
    {
        int j = 2;
        if(s[i])
        {
            if(s[i-1]) j--;
            if(s[i+1]) j--;
        } else
        {
            if(s[i-1] && s[i+1]) j--;
        }
        if(s[i] == 3) j = 0;
        if(s[i] == 2) j = min(j, 1);
        mn = min(mn, j);
    }
    cout << mn << endl;
}