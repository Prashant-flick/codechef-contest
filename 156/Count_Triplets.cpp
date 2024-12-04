#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t;
	while(t--){
	    int n;
	    cin >> n;
	    vector<int> arr(n+1);
        vector<vector<vector<int>>> vec(101, vector<vector<int>> (2));
        for(int i=1; i<=n; i++){
            cin >> arr[i];
            if(i%2==0){
                vec[arr[i]][0].push_back(i);
            }else{
                vec[arr[i]][1].push_back(i);
            }
        }


        int ans=n;
        int vis[101][101]={0};
        for(int i=1; i<=n; i++){
            cout << i << " " << arr[i] << endl;
            for(int j=1 ;j<101; j++){
                if(vis[arr[i]][j])continue;
                if(j==arr[i] || (vec[j][0].size()==0 && vec[j][1].size()==0)){
                    continue;
                }
                int maxi = i+abs(arr[i]-j);
                int mini = i-abs(arr[i]-j);
                if(maxi>n){
                    if(maxi%2==0){
                        if(n%2==0){
                            maxi=n;
                        }else{
                            maxi=n-1;
                        }
                    }else{
                        if(n%2!=0){
                            maxi=n;
                        }else{
                            maxi=n-1;
                        }
                    }
                }
                if(mini<=0){
                    if(mini%2==0){
                        mini=2;
                    }else{
                        mini=1;
                    }
                }
                if(maxi==i){
                    maxi-=2;
                }
                if(mini==i){
                    mini+=2;
                }
                if((maxi%2==0 && vec[j][0].size()==0) || (maxi%2==1 && vec[j][1].size()==0)){
                    continue;
                }
                if(maxi%2==0){
                    int maxindex = upper_bound(vec[j][0].begin(), vec[j][0].end(), maxi) - vec[j][0].begin();
                    maxindex--;
                    int minindex = upper_bound(vec[j][0].begin(), vec[j][0].end(), mini) - vec[j][0].begin();
                    minindex--;
                    cout << "here1 " << minindex << " " << maxindex << endl;
                    if(minindex<0)minindex=0;
                    for(int p=minindex; p<=maxindex; p++){
                        if(abs(vec[j][0][p]-i)==abs(arr[i]-j)){
                            ans+=(abs(arr[i]-j)+1)*2;
                        }else{
                            ans+=2;
                            if((i-(((i+(j-1))-(p+1))/2))>0){
                                ans+=2;
                            }
                        }
                    }
                }else{
                    int maxindex = upper_bound(vec[j][1].begin(), vec[j][1].end(), maxi) - vec[j][1].begin();
                    maxindex--;
                    int minindex = upper_bound(vec[j][1].begin(), vec[j][1].end(), mini) - vec[j][1].begin();
                    minindex--;
                    if(minindex<0)minindex=0;
                    cout << "here1 " << minindex << " " << maxindex << endl;
                    for(int p=minindex; p<=maxindex; p++){
                        if(abs(vec[j][1][p]-i)==abs(arr[i]-j)){
                            ans+=(abs(arr[i]-j)+1)*2;
                        }else{
                            ans+=2;
                            if(i-(((i+(j-1))-p)/2)>0){
                                ans+=2;
                            }
                        }
                    }
                }
                vis[j][arr[i]]=1;
            }
        }

        cout << ans << endl;

	}

}
