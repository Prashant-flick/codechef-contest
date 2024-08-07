#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--){
      int n;
      cin >> n;
      string s;
      cin >> s;
      int cnt1[5]={0};
      for(int i=0; i<n; i++){
        if(s[i]=='f'){
          cnt1[0]++;
        }else if(s[i]=='r'){
          cnt1[1]++;
          if(cnt1[1]>cnt1[0]){
            cnt1[1]=cnt1[0];
          }
        }else if(s[i]=='o'){
          cnt1[2]++;
          if(cnt1[2]>cnt1[1]){
            cnt1[2]=cnt1[1];
          }
        }else if(s[i]=='n'){
          cnt1[3]++;
          if(cnt1[3]>cnt1[2]){
            cnt1[3]=cnt1[2];
          }
        }else if(s[i]=='t'){
          cnt1[4]++;
          if(cnt1[4]>cnt1[3]){
            cnt1[4]=cnt1[3];
          }
        }
      }

      int cnt2[4]={0};
      for(int i=n-1; i>=0; i--){
        if(s[i]=='k'){
          cnt2[3]++;
        }else if(s[i]=='c'){
          cnt2[2]++;
          if(cnt2[2]>cnt2[3]){
            cnt2[2]=cnt2[3];
          }
        }else if(s[i]=='a'){
          cnt2[1]++;
          if(cnt2[1]>cnt2[2]){
            cnt2[1]=cnt2[2];
          }
        }else if(s[i]=='b'){
          cnt2[0]++;
          if(cnt2[0]>cnt2[1]){
            cnt2[0]=cnt2[1];
          }
        }
      }

      int ans=cnt1[4]*5 + cnt2[0]*4;
      ans=n-ans+cnt1[4]+cnt2[0];
      for(int i=3; i>=0; i--){
        int temp=cnt1[i]-cnt1[i+1];
        while(temp){
          if(cnt1[4]>=4-i){
            cnt1[4]-=(4-i);
            cnt1[4]++;
            temp--;
            ans-=4;
          }else{
            break;
          }
        }
      }

      for(int i=1; i<4; i++){
        int temp=cnt2[i]-cnt2[i-1];
        while(temp){
          if(cnt2[0]>=i){
            cnt2[0]-=i;
            cnt2[0]++;
            temp--;
            ans-=3;
          }else{
            break;
          }
        }
      }
      if(cnt2[0]>=4){
        int cnt=0;
        while(cnt2[0]>=4){
          cnt+=3*(cnt2[0]/4);
          cnt2[0]=cnt2[0]/4+cnt2[0]%4;
        }
        ans-=cnt;
      }
      if(cnt1[4]>=5){
        int cnt=0;
        while(cnt1[4]>=5){
          cnt+=4*(cnt1[4]/5);
          cnt1[4]=cnt1[4]/5+cnt1[4]%5;
        }
        ans-=cnt;
      }
      
      cout << ans << endl;
    }
}
