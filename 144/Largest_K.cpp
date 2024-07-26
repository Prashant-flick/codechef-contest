#include <bits/stdc++.h>
using namespace std;

int main() {
  // your code goes here
int t;
cin>>t;
while(t--)
{
    int n;
    cin>>n;
    int a[n];
    long long int m=0;
    int maxi=-1;
    map<int,int>mp;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
        mp[a[i]]++;
    }
    vector<int>v;
    for(auto it:mp)
    {v.push_back(it.second);
    }
    // sort(v.begin(),v.end());
    int z=1;
    int N=v.size();
for(int i=N-1;i>=0;i--)
{
    m+=v[i];
    int b=(m/z)*z;
    maxi=max(b,maxi);
    z++;
    
    
}
    cout<<maxi<<endl;
}
}