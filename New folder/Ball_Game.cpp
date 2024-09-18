#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main() {
	// your code goes here
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int arr[n];
        for(int i=0; i<n; i++)cin >> arr[i];
        int brr[n];
        for(int i=0; i<n; i++)cin >> brr[i];
        vector<pair<int,int>> vec;
        for(int i=0; i<n; i++){
            vec.push_back({arr[i], brr[i]});
        }
        sort(begin(vec), end(vec));
        long double time[n];
        for(int i=0; i<n; i++){
            time[i]=((long double)vec[i].first/vec[i].second);
            // cout << fixed << setprecision(20) << time[i] << endl;
        }

        int cnt=0;
        int i=0;
        map<long double, int> mp;
        while(i<n){
            if(i<n-1 && time[i]>time[i+1]){
                while(i<n-1 && time[i]>time[i+1]){
                    i++;
                }
                auto it = mp.upper_bound(time[i]);
                if(it!=mp.end()){
                    int temp = it->second;
                    long double temp1 =  it->first;
                    while(it!=mp.end()){
                        if(it!=mp.end()){
                            mp.erase(it++);
                        }else{
                            break;
                        }
                    }
                    if(mp.find(time[i])==mp.end()){
                        mp[time[i]]=min(temp,cnt);
                    }
                    cnt=temp;
                }else{
                    int temp = it->second;
                    long double temp1 = it->first;
                    cnt++;
                    if(mp.find(time[i])==mp.end()){
                        mp[time[i]]=min(temp,cnt);
                    }
                }
                i++;
            }else{
                auto it = mp.upper_bound(time[i]);
                if(it!=mp.end()){
                    int temp = it->second;
                    long double temp1 = it->first;
                    while(it!=mp.end()){
                        if(it!=mp.end()){
                            mp.erase(it++);
                        }else{
                            break;
                        }
                    }
                    if(mp.find(time[i])==mp.end()){
                        mp[time[i]]=min(temp,cnt);
                    }
                    cnt=temp;
                }else{
                    int temp = it->second;
                    long double temp1 = it->first;
                    cnt++;
                    if(mp.find(time[i])==mp.end()){
                        mp[time[i]]=min(temp,cnt);
                    }
                }
                i++;
            }
        }

        // auto it = mp.begin();
        // while(it!=mp.end()){
        //     cout << fixed << setprecision(20) << it->first << " " << it->second << endl;
        //     it++;
        // }


        cout << cnt << endl;
    }
}