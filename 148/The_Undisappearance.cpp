  #include <bits/stdc++.h>
  using namespace std;

  int main() {
    // your code goes here
      int t=1;
      cin >> t;
      while(t--){
          int n;
          cin >> n;
          int arr[n];
          int cnt[4]={0};
          for(int i=0; i<n; i++){
            cin >> arr[i];
            cnt[arr[i]]++;
          }
          int ans=((n*(n-1))/2)+n;
          for(int i=1; i<=3; i++){
            if(cnt[i]==1)ans--;
          }
          
          int i=0,j=0;
          int cnt2[4]={0};
          int ans2=0;
          while(j<n){
            if(j-i>=1){
              int cnt5=0;
              for(int k=1; k<4; k++){
                int index=k-1;
                if(index==0)index=3;
                if(cnt[k]>0 || cnt2[index])cnt5++;
              }
              if(cnt5<3){
                ans2++;
                cnt2[arr[i]]--;
                cnt[arr[i]]++;
                i++;
              }else{
                cnt2[arr[j]]++;
                cnt[arr[j]]--;
                j++;
              }
            }else{
              cnt2[arr[j]]++;
              cnt[arr[j]]--;
              j++;
            }
          }
          if(j==n)j--;
          while(i<n-1){
            if(j-i>=1){
              int cnt5=0;
              for(int k=1; k<4; k++){
                int index=k-1;
                if(index==0)index=3;
                if(cnt[k]>0 || cnt2[index])cnt5++;
              }
              if(cnt5<3){
                ans2++;
              }
              cnt2[arr[i]]--;
              cnt[arr[i]]++;
              i++;
            }
          }
          cout << ans-ans2 << endl;
      }
  }
