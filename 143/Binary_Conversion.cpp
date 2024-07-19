#include<bits/stdc++.h>
using namespace std;

#define int long long

int32_t main(){
int t;
  cin >> t;
  while(t--)
  {
      int n,k;
      cin >> n >> k;
      string s, t;
      cin >> s >> t;
      
      if(s == t and k%2 == 0)
      {
          cout << "YES" << '\n';
          continue;
      }
      
      int ct0=0,ct1=0;
      int v1=0,v2=0;
      for(int i = 0; i < s.size(); i++)
      {
          if(s[i] == '0' and t[i] == '1')
          {
              ct0++;
          }
          else if(s[i] == '1' and t[i] == '0')
          {
              ct1++;
          }
         // else
         // {
              if (s[i] == '0') v1++;
              else v2++;
         // }
          
      }
      
      if(ct0 != ct1)
      {
          cout << "NO" << '\n';
          continue;
         // return 0;
      }
      if (ct0 > k)
      {
           cout << "NO" << '\n';
           continue;
      }
      if ((k - ct0) and v1 < 2 and v2 < 2)
      {
          cout << "NO" << '\n';
          continue;
      }
      
      cout <<  "YES" << '\n';
      
      
    }
}