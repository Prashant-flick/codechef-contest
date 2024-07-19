
    #include <bits/stdc++.h>
using namespace std;
// STAY CALM

#define int long long int
#define vi vector<int>
#define read(a) for(auto &i: a) cin>>i
// #define mod 998244353
#define mod 1000000007



signed main() {
 int t=1;
 cin>>t;
 // sieve();
 while(t--){
  int n;
  cin>>n;

  vi a(n,0);
  read(a);
  vi p(n,0);
  read(p);
  int f=0;
  int cnt=1;
  for(int i=0;i<n;i++){
   if(i==n-1){break;}
   if(a[i]+p[i]>=a[i+1]){}
   else{
    cnt++;
   }
  }
  
  if(cnt<=2){f=1;}
  // cout<<f<<endl;
  cnt=1;
  
  for(int i=n-1;i>=0;i--){
   if(i==0){break;}
   if(a[i]-p[i]<=a[i-1]){}
   else{
    // cout<<i<<endl;
    cnt++;
   }
  }
  
  // cout<<cnt<<endl;
  if(cnt<=2){f=1;}
  // cout<<f<<endl;
  int leftreach=0;
  for(int i=0;i<n;i++){
   if(a[i]+p[i]>=a[i+1]){leftreach=i+1;}
   else{break;}
  }
  int rightreach=n-1;
  for(int i=n-1;i>=0;i--){
   if(a[i]-p[i]<=a[i-1]){rightreach=i-1;}
   else{break;}
  }
  if(leftreach+1>=rightreach){f=1;}
  if(f){cout<<"YES"<<endl;continue;}
  // left right case
  
  // left me kaha tak jaa sakt- 0 to default 
  for(int i=1;i<n;i++){
   if(a[i]-p[i]<=a[i-1]){continue;}
   else{
    // yaha se right jaana aue can we reach end 
    // cout<<i<<endl;
    for(int j=i;j<n;j++){
     if(j==n-1){f=1;}
     if(a[j]+p[j]>=a[j+1]){continue;}
     else{break;}
    }
     
    break;
   }
  }
  
  
  

  if(f){cout<<"YES"<<endl;}
  else{cout<<"NO"<<endl;}
 }

 return 0;
}