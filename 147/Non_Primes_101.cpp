#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	vector<bool> primes(201,true);
    primes[0]=primes[1]=false;
 
    //seive of eratosthenes
    for(int i=2;i*i<=201;i++)
    {
        if(primes[i])
        {
            for(int j=i;i*j<=201;j++)
            {
                primes[i*j]=false;
            }
        }
    }
	
	
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int arr[n];
        for(int i=0; i<n; i++)cin >> arr[i];
        int one=0;
        int ones=0;
        int odd=0;
        int even=0;
        int feven=0;
        int seven=0;
        int fodd=0;
        int sodd=0;
        
        unordered_map<int, int> mp;
        for(int i=0; i<n; i++){
            if(arr[i]%2==0){
                even++;
                if(feven==0){
                    feven=i;
                }else if(seven==0){
                    seven=i;
                }
            }else{
                if(arr[i]==1){
                    ones++;
                    one=i;
                }else{
                    odd++;
                    if(fodd==0){
                        fodd=i;
                    }else if(sodd==0){
                        sodd=i;
                    }
                }
            }
            mp[arr[i]]=i;
        }
        
        if(even>=2){
          cout << feven+1 << " " << seven+1 << endl;
        }else if(odd>=2){
          cout << fodd+1 << " " << sodd+1 << endl;
        }else if(odd==1 && ones>0){
          cout << one+1 << " " << fodd+1 << endl;
        }else{
          auto it = mp.begin();
          vector<pair<int,int>> brr;
          while(it!=mp.end()){
            brr.push_back({it->first, it->second});
            it++;
          }

          bool flag=false;
          for(int i=0; i<brr.size(); i++){
            for(int j=i+1; j<brr.size(); j++){
              if(!primes[brr[i].first+brr[j].first]){
                cout << brr[i].second+1<< " " << brr[j].second+1 << endl;
                flag=true;
                break;
              }
            }
          }
          if(!flag){
            cout << -1 << endl;
          }
    
        }
    }
}
