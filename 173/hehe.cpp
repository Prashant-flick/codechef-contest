#include <bits/stdc++.h>
using namespace std;

int solve(int a, int b){
    if(a==0){
        return b;
    }
    if(a%2==1){
        return 2*solve((a-1)/2,b);
    }
    return b+solve(a-1,b);
}

int main() {
	cout << solve(15,10) << endl;
}
