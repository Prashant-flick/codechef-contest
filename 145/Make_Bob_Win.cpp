#include <bits/stdc++.h>
using namespace std;

int main() {
  // std::ios::sync_with_stdio(false);
  // std::cin.tie(nullptr);

  int t;
  cin >> t;
  while(t--){
    int n;
    cin >> n;
    string s;
    cin >> s;
    int cnt1=0;
    int cnt2=0;
    int i=0;
    int cnt3=0;
    while(i<n){
      int cnt=1;
      while(i<n-1 && s[i]==s[i+1]){
          cnt++;
          i++;
      }
      if(s[i]=='1'){
        cnt1++;   
      }else{
        cnt2++;
        cnt3+=cnt;
      }
      i++;
    }
    
    if(cnt1>cnt2){
      cout << 0 << endl;
    }else if(cnt1==cnt2){
      cout << 1 << endl;
    }else{
      if(cnt1==0 && cnt3==1){
        cout << 1 << endl;
        continue;
      }
      cout << 2 << endl;
    }
  }
}
