#include <iostream>
#include <string>
using namespace std;

bool remove_subsequence(string &S, const string &sub) {
    size_t pos = 0;
    for (char ch : sub) {
        pos = S.find(ch, pos);
        if (pos == string::npos) return false;
        ++pos;
    }
    pos = 0;
    for (char ch : sub) {
        pos = S.find(ch, pos);
        S.erase(pos, 1);
    }
    return true;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int N;
        string S;
        cin >> N >> S;
        
        bool changed;
        do {
            changed = false;
            if (remove_subsequence(S, "back")) {
                S.insert(S.begin(), 'q');
                changed = true;
            }
            if (remove_subsequence(S, "front")) {
                S.push_back('d');
                changed = true;
            }
        } while (changed);
        
        cout << S.length() << endl;
    }
    return 0;
}