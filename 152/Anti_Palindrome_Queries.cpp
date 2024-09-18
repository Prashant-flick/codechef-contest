#include <bits/stdc++.h>
using namespace std;

vector<int> segTree;
int n;

int solve(vector<int> &nums, int l, int r, int s, int e){
    while(s>=l && e<=r){
        if(nums[s]==nums[e])return 1;
        s--;
        e++;
    }
    return 0;
}

void buildTree(vector<int> &nums, int index, int l, int r){
    if(l==r){
        segTree[index]=0;
        return;
    }
    int mid = (l+r)/2;
    buildTree(nums, 2*index+1, l, mid);
    buildTree(nums, 2*index+2, mid+1, r);
    int c = solve(nums, l, r, mid, mid+1);
    segTree[index] = max(segTree[2*index+1], max(segTree[2*index+2] ,c));
    return;
}

bool rangeSum(int i, int l, int r, int left, int right){
    int mid = (l+r)/2;
    // cout << l << " " << r << " " << i << endl;
    if(left>r || right<l){
        return false;
    }else if(left<=l && right>=r){
        // cout << "here1 " << segTree[i] << endl;
        if(segTree[i]==1){
            return true;
        }else{
            return false;
        }
    }else{
        return max(rangeSum(2*i+1, l, mid, left, right), rangeSum(2*i+2, mid+1, r, left, right));
    }
}


int main() {
    int t;
    cin >> t;
    while(t--){
        int q;
        cin >> n >> q;
        vector<int> arr(n);
        for(int i=0; i<n; i++)cin >> arr[i];   

        segTree.resize(4*n,0);
        buildTree(arr, 0, 0, n-1);

        while(q--){
            int l,r;
            cin >> l >> r;
            if((r-l+1)%2==1){
                cout << "No" << endl;
                continue;
            }
            l--;
            r--;
            int c = rangeSum(0, 0, n-1, l, r);
            // cout << c << endl;
            if(c==1){
                cout << "No" << endl;
            }else{
                cout << "Yes" << endl;
            }
        }

        segTree.clear();
    }
}
