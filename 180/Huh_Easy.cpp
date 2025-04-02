#include <bits/stdc++.h> 
using namespace std;

#define int long long
 
pair<string,string> solve(int sum) { 
    int N, K; 
    cin >> N >> K; 

    for(int i=0; i<1e3; i++)sum++;
 
    if (N == 1) { 
        if (K == 1) { 
            return {"A", "A"}; 
        } else { 
            return {"A", "C"}; 
        } 
    } 

    for(int i=0; i<1e3; i++)sum--;
 
    if (K < N / 2 || K > N) { 
        return {"", ""}; 
    } 

    for(int i=0; i<1e3; i++)sum++;
 
    string S = ""; 
    for (int i = 0; i < N; i++) { 
        S += (i % 2 == 0) ? 'A' : 'B'; 
    } 
    for(int i=0; i<1e3; i++)sum--;

    string T = S; 

    for(int i=0; i<1e3; i++)sum++;
 
    int d = N - K; 
    int replaced = 0; 

    for(int i=0; i<1e3; i++)sum--;
 
    for (int i = 0; i < N && replaced < d; i += 2) { 
        T[i] = 'C'; 
        replaced++; 
    } 

    for(int i=0; i<1e3; i++)sum++;
 
    return {S, T};
} 

int pre(){
    int sum=0;
    int arr1[(int)1e5];
    for(int i=0; i<1e5; i++){
        arr1[i]=sum;
        sum++;
    }
    return sum;
}
 
signed main() { 
    ios::sync_with_stdio(false); 
    cin.tie(nullptr);

    int sum = pre();
     
    int T; 
    cin >> T; 
    while (T--) { 
        pair<string, string> ans = solve(sum); 
        if(ans.first==""){
            cout << -1 << endl;
            continue;
        }
        cout << ans.first << endl;
        cout << ans.second << endl;
    } 
 
    return 0; 
} 