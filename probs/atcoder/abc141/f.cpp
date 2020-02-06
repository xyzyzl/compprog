#include <iostream>
#include <climits>
#include <set>

using namespace std;

#define int long long

int n, arr[100005];
set<int> rem;
#define INT_BITS 64
  
int fun() 
{ 
  int index = 0; 
  
  for (int i = INT_BITS-1; i >= 0; i--) 
  { 
    int maxInd = index; 
    int maxEle = INT_MIN; 
    for (int j = index; j < n; j++) 
    { 
      if ( (arr[j] & (1 << i)) != 0  
                     && arr[j] > maxEle ) 
                maxEle = arr[j], maxInd = j; 
      } 
  
      if (maxEle == INT_MIN) 
        continue; 
  
      swap(arr[index], arr[maxInd]); 
  
      maxInd = index; 

      for (int j=0; j<n; j++) 
      { 
        if (j != maxInd && 
             (arr[j] & (1 << i)) != 0) 
          arr[j] = arr[j] ^ arr[maxInd]; 
      } 
  
      index++; 
  } 
  
  int res = 0; 
  for (int i = 0; i < n; i++) 
    res ^= arr[i]; 
  return res; 
} 

signed main() {
  cin >> n;
  for(int i = 0; i < n; i++) cin >> arr[i];
  for(int i = 0; i < n; i++) rem.insert(arr[i]);
  // cout << fun() << endl;
  int f = fun();
  cout << f << endl;
  for(int i = 0; i < n; i++) cout << arr[i] << " ";
  cout << endl;
  for(int i = 0; i < n; i++) if(rem.count(arr[i])) rem.erase(arr[i]);
  long long leftover=0;
  for(int thing : rem) leftover ^= thing;
  cout << f + leftover << endl;
}
