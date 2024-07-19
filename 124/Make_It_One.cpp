#include <iostream>
using namespace std;

int main() {
    int testCases;
    cin >> testCases;
    
    while(testCases--) {
        int left, right;
        cin >> left >> right;
        
        int length = (right - left) + 1;
        if(length == 1) {
            if(right == 1) {
                cout << 1 << endl;
            } else {
                cout << -1 << endl;
            }
        } else if(length % 2 == 0) {
            int array[length];
            int index = 0;
            for(int i = left; i <= right; i++) {
                array[index] = i;
                index++;
            }
            for(int i = 0; i < length; i += 2) {
                swap(array[i], array[i + 1]);
            }
            for(int i = 0; i < length; i++) {
                cout << array[i] << " ";
            }
            cout << endl;
        } else {
            if(right % 2 == 0) {
                cout << -1 << endl;
            } else {
                int array[length];
                int index = 0;
                for(int i = left; i <= right; i++) {
                    array[index] = i;
                    index++;
                }
                for(int i = 0; i < length - 3; i += 2) {
                    swap(array[i], array[i + 1]);
                }
                int temp = array[length - 3];
                array[length - 3] = array[length - 1];
                int temp2 = array[length - 2];
                array[length - 2] = temp;
                array[length - 1] = temp2;
                
                for(int i = 0; i < length; i++) {
                    cout << array[i] << " ";
                }
                cout << endl;
            }
        }
    }
    return 0;
}
